#pragma once
#include <memory>
#include <queue>
#include "Shape.h"
#include "Game.h"
#include "Tetris.h"

//class Game;

class Play_field : protected Tetris {
	int arr_color_cell[20][10]{}; //19 видимых и 1 невидимый (индексы 18 и 19)
	int max_index = 0;
	int y_shape_min;
	int y_shape_max;
	bool new_shape_down = false;
	std::queue <int> y_queue_delete;
	bool flag_resize = false;
	Timer time_fire_row;
	bool flag_fire_show = false;
	const int time_fire_show = 100;

public:
	Play_field() { ppf = this; }
	void init();
	int get_max_index() { return max_index; }
	bool check_cell(std::unique_ptr<Shape> &p_shape); //проверка пересечения фигуры с элементами поля
	void plus_shape(std::unique_ptr<Shape> &p_shape); //слияние фигуры с игровым полем
	void calculate_resize(); //проверка наличия заполненных рядов
	void set_score(); //начисление счета
	void tetris_resize(); //удаление заполненных рядов
	void show_fire_row(int y); //анимация удаления ряда
	void show();
	void run();
};