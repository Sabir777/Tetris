#pragma once
#include <memory> // для std::unique_ptr
#include "Game.h"
#include "Play_field.h"
#include "Shape.h"
#include "Timer.h"
#include "Tetris.h"

class Wrapper_shape : protected Tetris {
private:
	std::unique_ptr<Shape> p_shape;
	std::unique_ptr<Shape> p_shape_prev;
	int key_press_prev;
	Timer time_down;
	Timer time_press_on;
	int long_press_period = 200;
	int speed_period = 500;
	bool shape_state_down;
	int next_shape_id = 3;
	int next_shape_color = 14;

public:
	Wrapper_shape() { pws = this; }
	void init(); //создание новой фигуры
	void move_left();
	void move_right();
	void move_rotate();
	void move_down_fast();
	void move_down_slow();
	void move();
	void show();
	int get_id_next_shape() { return next_shape_id; }
	int get_color_next_shape() { return next_shape_color; }
	void set_speed_period(int n) { speed_period = n; }
	void run();
};