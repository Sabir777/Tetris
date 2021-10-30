#pragma once
#include "Animation.h"


struct Coord {
	int x;
	int y;
};

class Shape {
protected:
	int id; //тип фигуры
	int color_shape; //цвет фигуры
	int state_rotate = 0; //угол поворота в пространстве
	Coord arr_cell[4]; //координаты клеток фигуры

public:
	virtual ~Shape() {}
	void shift_left(); //сдвиг влево
	void shift_right(); //сдвиг вправо
	void shift_down(); //сдвиг вниз
	virtual void rotate() = 0; //поворот на 90 градусов
	virtual Shape* clone() = 0; //динамически создать копию фигуры
	void show(int col = 0); //прорисовка фигуры
	int get_id() { return id; } //вернуть тип фигуры
	int get_color() { return color_shape; } //вернуть цвет фигуры
	bool check_left(); //проверка выхода за левую границу
	bool check_right(); //проверка выхода за правую границу
	bool check_down(); //проверка выхода за нижнюю границу
	bool operator!=(Shape& other);
	Coord& operator[](const int index);
};

class I_shape : public Shape{ //1
public:
	I_shape(int color);
	void rotate() override;
	Shape* clone() override;
};

class J_shape : public Shape { //2
public:
	J_shape(int color);
	void rotate() override;
	Shape* clone() override;
};

class L_shape : public Shape { //3
public:
	L_shape(int color);
	void rotate() override;
	Shape* clone() override;
};

class O_shape : public Shape { //4
public:
	O_shape(int color);
	void rotate() override {}
	Shape* clone() override;
};

class Z_shape : public Shape { //5
public:
	Z_shape(int color);
	void rotate() override;
	Shape* clone() override;
};

class S_shape : public Shape { //6
public:
	S_shape(int color);
	void rotate() override;
	Shape* clone() override;
};

class T_shape : public Shape { //7
public:
	T_shape(int color);
	void rotate() override;
	Shape* clone() override;
};
