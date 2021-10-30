#include "Game.h"

void Game::init() {
	print_fill(Fill(0, 54, 0, 39), 3);
	print_fill(Fill(1, 30, 1, 38), 0);
	print_fill(Fill(34, 51, 1, 10), 0);

	Position(37, 12); //счет
	color(14, 3);
	std::cout << "Cчет: 000000";

	Position(37, 14); //скорость
	color(15, 3);
	std::cout << "Cкорость: 1";
	
	//окошко сообщений
	print_fill(Fill(34, 51, 17, 25), 0);
	
	Position(38, 37); //пауза
	color(1, 3);
	std::cout << "Esc - пауза";
	Position(54, 39);
}


int Game::get_key_press() {
	if (GetAsyncKeyState(37)) return 37; //влево
	if (GetAsyncKeyState(39)) return 39; //вправо
	if (GetAsyncKeyState(38)) return 38; //вверх
	if (GetAsyncKeyState(40)) return 40; //вниз
	if (GetAsyncKeyState(27)) return 27; //Esc
	if (GetAsyncKeyState(13)) return 13; //Enter
	return 0;
}

void Game::set_game_over() {
	game_state = GAME_OVER;
	print_fill(Fill(1, 30, 15, 21), 10);
	print_fill(Fill(2, 29, 16, 20), 4);
	color(14, 4);
	Position(12, 17);
	std::cout << "GAME OVER";
	Position(5, 18);
	std::cout << "чтобы начать игру заново";
	Position(9, 19);
	std::cout << "нажмите - Enter";
	Position(54, 39);
}

void Game::show_next_shape() {
	int id = pws->get_id_next_shape();
	int col = pws->get_color_next_shape();
	if (id != id_shape_prev || col != color_shape_prev) {
		print_fill(Fill(34, 51, 1, 10), 0);

		id_shape_prev = id;
		color_shape_prev = col;
		
		switch (id) {
		case 1:
			print_fill(Fill(37, 48, 5, 6), col);

			break;
		case 2:
			print_fill(Fill(39, 47, 5, 6), col);
			print_fill(Fill(39, 41, 3, 4), col);
			break;
		case 3:
			print_fill(Fill(39, 47, 5, 6), col);
			print_fill(Fill(45, 47, 3, 4), col);
			break;
		case 4:
			print_fill(Fill(40, 45, 6, 7), col);
			print_fill(Fill(40, 45, 4, 5), col);
			break;
		case 5:
			print_fill(Fill(41, 46, 6, 7), col);
			print_fill(Fill(38, 43, 4, 5), col);
			break;
		case 6:
			print_fill(Fill(42, 47, 4, 5), col);
			print_fill(Fill(39, 44, 6, 7), col);
			break;
		case 7:
			print_fill(Fill(42, 44, 4, 5), col);
			print_fill(Fill(39, 47, 6, 7), col);
			break;
			
		}
	}
}

void Game::message_delete() {
	if (flag_message && time_message.duration() >= 1500) {
		flag_message = false;
		print_fill(Fill(34, 51, 17, 25), 0);
	}
}

void Game::print_score() {
	//счет
	int n1, n2, n3, n4, n5, n6;
	n6 = score % 10;
	n5 = (score % 100) / 10;
	n4 = (score % 1000) / 100;
	n3 = (score % 10000) / 1000;
	n2 = (score % 100000) / 10000;
	n1 = (score % 1000000) / 100000;
	Position(43, 12);
	color(14, 3);
	std::cout << n1 << n2 << n3 << n4 << n5 << n6;
	Position(54, 39);
}

void Game::set_print_score(int n) {
	flag_message = true;
	time_message.set_time_point();
	switch (n) {
	case 1500:
		Position(38, 20);
		color(12, 0);
		std::cout << "Tetris!!!!!";
		color(14, 0);
		Position(40, 21);
		std::cout << "+1500";
		break;
	case 700:
		color(14, 0);
		Position(40, 21);
		std::cout << "+700";
		break;
	case 300:
		color(14, 0);
		Position(40, 21);
		std::cout << "+300";
		break;
	case 100:
		color(14, 0);
		Position(41, 21);
		std::cout << "+100";
	}

	score += n;
	print_score();
}

void Game::show_speed() {
	color(15, 3);
	Position(47, 14);
	std::cout << speed;
	Position(54, 39);
}

void Game::set_speed() {
	switch (speed) {
	case 1:
		if (score >= 2000) {
			speed = 2;
			pws->set_speed_period(400);
			show_speed();
		}
		break;
	case 2:
		if (score >= 4000) {
			speed = 3;
			pws->set_speed_period(350);
			show_speed();
		}
		break;
	case 3:
		if (score >= 6000) {
			speed = 4;
			pws->set_speed_period(300);
			show_speed();
		}
		break;
	case 4:
		if (score >= 8000) {
			speed = 5;
			pws->set_speed_period(250);
			show_speed();
		}
		break;
	case 5:
		if (score >= 10000) {
			speed = 6;
			pws->set_speed_period(200);
			show_speed();
		}
		break;
	case 6:
		if (score >= 12000) {
			speed = 7;
			pws->set_speed_period(150);
			show_speed();
		}
		break;
	default: return;
	}
	
}

void Game::run() {
	key_press = get_key_press();
	switch (game_state) {
	case GAME:
		show_next_shape();
		message_delete();
		set_speed();
		if (key_press == 27 && key_press_prev != key_press) game_state = PAUSE;
		break;
	case PAUSE:
		if (key_press == 27 && key_press_prev != key_press) game_state = GAME;
		break;
	case GAME_OVER:
		if (key_press == 13) {
			game_state = GAME;
			score = 0;
			speed = 1;
			init();
			pws->set_speed_period(500);
			pws->init();
			ppf->init();
		}
	}
	key_press_prev = key_press;
}