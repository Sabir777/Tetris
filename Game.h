#pragma once
#include "Tetris.h"
#include "Animation.h"
#include "Timer.h"
#include "Wrapper_shape.h"

class Game : protected Tetris {
private:
	int key_press_prev;
	int id_shape_prev;
	int color_shape_prev;
	Timer time_message;
	bool flag_message = false;

public:
	Game() { pgm = this; }
	void init();
	int get_key_press();
	void set_game_over();
	void message_delete();
	void print_score();
	void set_print_score(int n);
	void show_next_shape();
	void set_speed();
	void show_speed();
	void run();
};
