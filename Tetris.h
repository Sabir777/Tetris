#pragma once

enum State { GAME, PAUSE, GAME_OVER };
class Game;
class Wrapper_shape;
class Play_field;

class Tetris{
protected:
	static int key_press;
	static State game_state;
	static int score;
	static int speed;
	static Game* pgm;
	static Wrapper_shape* pws;
	static Play_field* ppf;
};