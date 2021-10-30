#include "Wrapper_shape.h"

void Wrapper_shape::init() {
	shape_state_down = false;

	switch (next_shape_id) {
	case 1:
		p_shape = std::unique_ptr<Shape>(new I_shape(next_shape_color));
		p_shape_prev = std::unique_ptr<Shape>(new I_shape(next_shape_color));
		break;
	case 2:
		p_shape = std::unique_ptr<Shape>(new J_shape(next_shape_color));
		p_shape_prev = std::unique_ptr<Shape>(new J_shape(next_shape_color));
		break;
	case 3:
		p_shape = std::unique_ptr<Shape>(new L_shape(next_shape_color));
		p_shape_prev = std::unique_ptr<Shape>(new L_shape(next_shape_color));
		break;
	case 4:
		p_shape = std::unique_ptr<Shape>(new O_shape(next_shape_color));
		p_shape_prev = std::unique_ptr<Shape>(new O_shape(next_shape_color));
		break;
	case 5:
		p_shape = std::unique_ptr<Shape>(new Z_shape(next_shape_color));
		p_shape_prev = std::unique_ptr<Shape>(new Z_shape(next_shape_color));
		break;
	case 6:
		p_shape = std::unique_ptr<Shape>(new S_shape(next_shape_color));
		p_shape_prev = std::unique_ptr<Shape>(new S_shape(next_shape_color));
		break;
	case 7:
		p_shape = std::unique_ptr<Shape>(new T_shape(next_shape_color));
		p_shape_prev = std::unique_ptr<Shape>(new T_shape(next_shape_color));
		break;
	}

	next_shape_id = 1 + rand() % 7; // случайный выбор фигуры
	int n = 1 + rand() % 6; //случайный выбор цвета при инициализации
	if (n == 1) next_shape_color = 2;
	else if (n == 2) next_shape_color = 9;
	else if (n == 3) next_shape_color = 12;
	else if (n == 4) next_shape_color = 13;
	else if (n == 5) next_shape_color = 14;
	else next_shape_color = 15;

	p_shape->show(p_shape->get_color());
}

void Wrapper_shape::move_left() {
	int key_on = key_press;
	if (key_on == 37)
		if (key_on != key_press_prev || time_press_on.duration() >= long_press_period) {
			std::unique_ptr<Shape> p_temp_shape(p_shape->clone());
			p_temp_shape->shift_left();
			if (p_temp_shape->check_left() || ppf->check_cell(p_temp_shape)) return;
			*p_shape = *p_temp_shape;
		}
}

void Wrapper_shape::move_right() {
	int key_on = key_press;
	if (key_on == 39) {
		if (key_on != key_press_prev || time_press_on.duration() >= long_press_period) {
			std::unique_ptr<Shape> p_temp_shape(p_shape->clone());
			p_temp_shape->shift_right();
			if (p_temp_shape->check_right() || ppf->check_cell(p_temp_shape)) return;
			*p_shape = *p_temp_shape;
		}
	}
}

void Wrapper_shape::move_rotate() {
	int key_on = key_press;
	if (key_on == 38) {
		if (key_on != key_press_prev) {
			std::unique_ptr<Shape> p_temp_shape(p_shape->clone());
			p_temp_shape->rotate();
			if (p_temp_shape->check_left() || p_temp_shape->check_right()
				|| p_temp_shape->check_down() || ppf->check_cell(p_temp_shape)) return;
			*p_shape = *p_temp_shape;
		}
	}
}

void Wrapper_shape::move_down_fast() {
	int key_on = key_press;
	if (key_on == 40) {
		time_down.set_time_point(); //сброс счетчика если нажата стрелка вниз
		if (key_on != key_press_prev) {
			std::unique_ptr<Shape> p_temp_shape(p_shape->clone());
			for (;;) {
				p_temp_shape->shift_down();
				if (p_temp_shape->check_down() || ppf->check_cell(p_temp_shape)) return;
				*p_shape = *p_temp_shape;
			}
		}
	}
}

void Wrapper_shape::move_down_slow() {
	if (time_down.duration() >= speed_period) {
		std::unique_ptr<Shape> p_temp_shape(p_shape->clone());
		time_down.set_time_point();
		p_temp_shape->shift_down();
		if (p_temp_shape->check_down() || ppf->check_cell(p_temp_shape)) {
			shape_state_down = true;
			ppf->plus_shape(p_shape);
			return;
		}
		*p_shape = *p_temp_shape;
	}
}

void Wrapper_shape::move() {
	int key_on = key_press;
	if (!key_on) time_press_on.set_time_point(); //сброс счетчика, если отпустишь клавишу
	move_left();
	move_right();
	move_rotate();
	move_down_fast();
	move_down_slow();
	key_press_prev = key_on;
}

void Wrapper_shape::show() {
	if (*p_shape != *p_shape_prev) {
		p_shape_prev->show();
		p_shape->show(p_shape->get_color());
		*p_shape_prev = *p_shape;
	}
}

void Wrapper_shape::run() {
	if (game_state == GAME) {
		move();
		show();
		if (shape_state_down) init();
	}
}