#include "Play_field.h"

void Play_field::init(){
	for (int j = 0; j < 20; ++j)
		for (int i = 0; i < 10; ++i)
			arr_color_cell[j][i] = 0;
	max_index = 0;
}

bool Play_field::check_cell(std::unique_ptr<Shape> &p_shape) {
	for (int i = 0; i < 4; ++i)
		if (arr_color_cell[(*p_shape)[i].y][(*p_shape)[i].x])
			return true;
	return false;
}

void Play_field::plus_shape(std::unique_ptr<Shape> &p_shape) {
	int col = p_shape->get_color();
	y_shape_min = (*p_shape)[0].y;
	y_shape_max = y_shape_min;
	for (int i = 0; i < 4; ++i) {
		int x = (*p_shape)[i].x;
		int y = (*p_shape)[i].y;
		if (y < y_shape_min) y_shape_min = y;
		if (y > y_shape_max) y_shape_max = y;
		if (y > max_index) max_index = y;
		arr_color_cell[y][x] = col;
	}
	new_shape_down = true;
}

void Play_field::calculate_resize() {
	if (new_shape_down) {
		new_shape_down = false;
		for (int j = y_shape_min; j <= y_shape_max; ++j) {
			bool line_complete = true;
			for (int i = 0; i < 10; ++i) {
				if (!arr_color_cell[j][i]) {
					line_complete = false;
					break;
				}
			}
			if (line_complete) y_queue_delete.push(j);
		}
	}
}

void Play_field::set_score() {
	switch (y_queue_delete.size()) {
	case 1:
		pgm->set_print_score(100);
		return;
	case 2:
		pgm->set_print_score(300);
		return;
	case 3:
		pgm->set_print_score(700);
		return;
	case 4:
		pgm->set_print_score(1500);
		return;
	default: return;
	}
}

void Play_field::tetris_resize() {
	if (!y_queue_delete.empty()) {
		flag_resize = true;
		int arr_temp[20][10]{};

		for (int j = 0, jx = 0; j < 20; ++j) {
			if (!y_queue_delete.empty() && y_queue_delete.front() == j) {
				time_fire_row.set_time_point();
				flag_fire_show = true;
				show_fire_row(j);
				y_queue_delete.pop();
				--max_index;
			}
			else {
				for (int i = 0; i < 10; ++i)
					arr_temp[jx][i] = arr_color_cell[j][i];
				++jx;
			}
		}

		for (int j = 0; j < 20; ++j)
			for (int i = 0; i < 10; ++i)
				arr_color_cell[j][i] = arr_temp[j][i];
	}
}

void Play_field::show_fire_row(int y) {
		for (int i = 0; i < 10; ++i)
			print_coord_field(i, y, 0);
}

void Play_field::show() {
	if (flag_fire_show && time_fire_row.duration() >= time_fire_show)
		flag_fire_show = false;

	if (flag_resize && !flag_fire_show){ 
		flag_resize = false;
		print_fill(Fill(1, 30, 1, 38), 0);

		for(int j = 0; j < 19; ++j)
			for (int i = 0; i < 10; ++i)
				print_coord_field(i, j, arr_color_cell[j][i]);
	}
}

void Play_field::run(){
	if (game_state == GAME) {
		if (max_index >= 18) pgm->set_game_over();
		calculate_resize();
		set_score();
		tetris_resize();
		show();
	}
}