#include "Shape.h"

void Shape::shift_left() {
for (int i = 0; i < 4; ++i)
--arr_cell[i].x;		
}

void Shape::shift_right() {
for (int i = 0; i < 4; ++i)
++arr_cell[i].x;
}

void Shape::shift_down() {
for (int i = 0; i < 4; ++i)
--arr_cell[i].y;
}

void Shape::show(int col) {
	int x, y;
	for (int i = 0; i < 4; ++i) {
		x = arr_cell[i].x;
		y = arr_cell[i].y;
		if (y < 19) print_coord_field(x, y, col);
	}
	Position(54, 39);
}

bool Shape::check_left() {
	for (int i = 0; i < 4; ++i)
		if (arr_cell[i].x < 0) return true;
	return false;
}

bool Shape::check_right() {
	for (int i = 0; i < 4; ++i)
		if (arr_cell[i].x > 9) return true;
	return false;
}

bool Shape::check_down() {
	for (int i = 0; i < 4; ++i)
		if (arr_cell[i].y < 0) return true;
	return false;
}

bool Shape::operator!=(Shape& other) {
	Coord* arr_other = other.arr_cell;
	for (int i = 0; i < 4; ++i) {
		if (arr_cell[i].x != arr_other[i].x) return true;
		if (arr_cell[i].y != arr_other[i].y) return true;
	}
	return false;
}

Coord& Shape::operator[](int index) {
	return arr_cell[index];
}

//I_Shape(1)
I_shape::I_shape(int col){
	color_shape = col;
	int x = 3, y = 18;
	for (int i = 0; i < 4; ++i) {
		arr_cell[i].x = x + i;
		arr_cell[i].y = y;
	}
}

void I_shape::rotate() {
			switch(state_rotate) { 
			case 0: // исходное положение - горизонтальное
				++arr_cell[0].x;
				--arr_cell[0].y;
				--arr_cell[2].x;
				++arr_cell[2].y;
				arr_cell[3].x -= 2;
				arr_cell[3].y += 2;
				state_rotate = 1;
				return;
			case 1:
				--arr_cell[3].x;
				--arr_cell[3].y;
				++arr_cell[1].x;
				++arr_cell[1].y;
				arr_cell[0].x += 2;
				arr_cell[0].y += 2;
				state_rotate = 2;
				return;
			case 2:
				--arr_cell[0].x;
				++arr_cell[0].y;
				++arr_cell[2].x;
				--arr_cell[2].y;
				arr_cell[3].x += 2;
				arr_cell[3].y -= 2;
				state_rotate = 3;
				return;
			case 3:
				++arr_cell[3].x;
				++arr_cell[3].y;
				--arr_cell[1].x;
				--arr_cell[1].y;
				arr_cell[0].x -= 2;
				arr_cell[0].y -= 2;
				state_rotate = 0;
				return;
			}
			
}

Shape* I_shape::clone() {
	return new I_shape(*this);
}

//J_Shape(2)
J_shape::J_shape(int col) {
	color_shape = col;
	int x = 4, y = 18;
	for (int i = 0; i < 3; ++i) {
		arr_cell[i].x = x + i;
		arr_cell[i].y = y;
	}

	arr_cell[3].x = 4;
	arr_cell[3].y = 19;
}


void J_shape::rotate() {
	switch (state_rotate) {
	case 0:
		++arr_cell[0].x;
		++arr_cell[0].y;
		--arr_cell[2].x;
		--arr_cell[2].y;
		arr_cell[3].x += 2;
		state_rotate = 1;
		return;
	case 1:
		++arr_cell[0].x;
		--arr_cell[0].y;
		--arr_cell[2].x;
		++arr_cell[2].y;
		arr_cell[3].y -= 2;
		state_rotate = 2;
		return;
	case 2:
		--arr_cell[0].x;
		--arr_cell[0].y;
		++arr_cell[2].x;
		++arr_cell[2].y;
		arr_cell[3].x -= 2;
		state_rotate = 3;
		return;
	case 3:
		--arr_cell[0].x;
		++arr_cell[0].y;
		++arr_cell[2].x;
		--arr_cell[2].y;
		arr_cell[3].y += 2;
		state_rotate = 0;
		return;
	}

}

Shape* J_shape::clone() {
	return new J_shape(*this);
}

//L_Shape(3)
L_shape::L_shape(int col) {
	color_shape = col;
	int x = 4, y = 18;
	for (int i = 0; i < 3; ++i) {
		arr_cell[i].x = x + i;
		arr_cell[i].y = y;
	}
	arr_cell[3].x = 6;
	arr_cell[3].y = 19;
}


void L_shape::rotate() {
	switch (state_rotate) {
	case 0:
		++arr_cell[0].x;
		++arr_cell[0].y;
		--arr_cell[2].x;
		--arr_cell[2].y;
		arr_cell[3].y -= 2;
		state_rotate = 1;
		return;
	case 1:
		++arr_cell[0].x;
		--arr_cell[0].y;
		--arr_cell[2].x;
		++arr_cell[2].y;
		arr_cell[3].x -= 2;
		state_rotate = 2;
		return;
	case 2:
		--arr_cell[0].x;
		--arr_cell[0].y;
		++arr_cell[2].x;
		++arr_cell[2].y;
		arr_cell[3].y += 2;
		state_rotate = 3;
		return;
	case 3:
		--arr_cell[0].x;
		++arr_cell[0].y;
		++arr_cell[2].x;
		--arr_cell[2].y;
		arr_cell[3].x += 2;
		state_rotate = 0;
		return;
	}
}

Shape* L_shape::clone() {
	return new L_shape(*this);
}

//O_Shape(4)
O_shape::O_shape(int col) {
	color_shape = col;
	int x = 5, y = 18;
	for (int i = 0; i <= 1; ++i) {
		arr_cell[i].x = x + i;
		arr_cell[i].y = y;
	}
	y = 19;
	for (int i = 2; i <= 3; ++i) {
		arr_cell[i].x = x + i - 2;
		arr_cell[i].y = y;
	}
}

Shape* O_shape::clone() {
	return new O_shape(*this);
}

//Z_Shape(5)
Z_shape::Z_shape(int col) {
	color_shape = col;
	int x = 6, y = 18;
	for (int i = 0; i <= 1; ++i) {
		arr_cell[i].x = x - i;
		arr_cell[i].y = y;
	}
	y = 19;
	for (int i = 2; i <= 3; ++i) {
		arr_cell[i].x = x - i + 1;
		arr_cell[i].y = y;
	}
}

void Z_shape::rotate() {
	switch (state_rotate) {
	case 0:
		--arr_cell[0].x;
		--arr_cell[0].y;
		++arr_cell[2].x;
		--arr_cell[2].y;
		arr_cell[3].x += 2;
		state_rotate = 1;
		return;
	case 1:
		--arr_cell[0].x;
		++arr_cell[0].y;
		--arr_cell[2].x;
		--arr_cell[2].y;
		arr_cell[3].y -= 2;
		state_rotate = 2;
		return;
	case 2:
		++arr_cell[0].x;
		++arr_cell[0].y;
		--arr_cell[2].x;
		++arr_cell[2].y;
		arr_cell[3].x -= 2;
		state_rotate = 3;
		return;
	case 3:
		++arr_cell[0].x;
		--arr_cell[0].y;
		++arr_cell[2].x;
		++arr_cell[2].y;
		arr_cell[3].y += 2;
		state_rotate = 0;
		return;
	}
}

Shape* Z_shape::clone() {
	return new Z_shape(*this);
}

//S_Shape(6)
S_shape::S_shape(int col) {
	color_shape = col;
	int x = 4, y = 18;
	for (int i = 0; i <= 1; ++i) {
		arr_cell[i].x = x + i;
		arr_cell[i].y = y;
	}
	y = 19;
	for (int i = 2; i <= 3; ++i) {
		arr_cell[i].x = x + i - 1;
		arr_cell[i].y = y;
	}
}

void S_shape::rotate() {
	switch (state_rotate) {
	case 0:
		++arr_cell[0].x;
		++arr_cell[0].y;
		++arr_cell[2].x;
		--arr_cell[2].y;
		arr_cell[3].y -= 2;
		state_rotate = 1;
		return;
	case 1:
		++arr_cell[0].x;
		--arr_cell[0].y;
		--arr_cell[2].x;
		--arr_cell[2].y;
		arr_cell[3].x -= 2;
		state_rotate = 2;
		return;
	case 2:
		--arr_cell[0].x;
		--arr_cell[0].y;
		--arr_cell[2].x;
		++arr_cell[2].y;
		arr_cell[3].y += 2;
		state_rotate = 3;
		return;
	case 3:
		--arr_cell[0].x;
		++arr_cell[0].y;
		++arr_cell[2].x;
		++arr_cell[2].y;
		arr_cell[3].x += 2;
		state_rotate = 0;
		return;
	}
}

Shape* S_shape::clone() {
	return new S_shape(*this);
}

//T_Shape(7)
T_shape::T_shape(int col) {
	color_shape = col;
	int x = 4, y = 18;
	for (int i = 0; i < 3; ++i) {
		arr_cell[i].x = x + i;
		arr_cell[i].y = y;
	}
	arr_cell[3].x = 5;
	arr_cell[3].y = 19;
}

void T_shape::rotate() {
	switch (state_rotate) {
	case 0:
		++arr_cell[0].x;
		++arr_cell[0].y;
		--arr_cell[2].x;
		--arr_cell[2].y;
		++arr_cell[3].x;
		--arr_cell[3].y;
		state_rotate = 1;
		return;
	case 1:
		++arr_cell[0].x;
		--arr_cell[0].y;
		--arr_cell[2].x;
		++arr_cell[2].y;
		--arr_cell[3].x;
		--arr_cell[3].y;
		state_rotate = 2;
		return;
	case 2:
		--arr_cell[0].x;
		--arr_cell[0].y;
		++arr_cell[2].x;
		++arr_cell[2].y;
		--arr_cell[3].x;
		++arr_cell[3].y;
		state_rotate = 3;
		return;
	case 3:
		--arr_cell[0].x;
		++arr_cell[0].y;
		++arr_cell[2].x;
		--arr_cell[2].y;
		++arr_cell[3].x;
		++arr_cell[3].y;
		state_rotate = 0;
		return;
	}
}

Shape* T_shape::clone() {
	return new T_shape(*this);
}