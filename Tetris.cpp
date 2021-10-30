#include "Tetris.h"

int Tetris::key_press = 0;
State Tetris::game_state = GAME;
int Tetris::score = 0;
int Tetris::speed = 1;
Game* Tetris::pgm = nullptr;
Wrapper_shape* Tetris::pws = nullptr;
Play_field* Tetris::ppf = nullptr;