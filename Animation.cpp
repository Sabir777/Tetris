//    #define BLACK 0	#define RED        4	#define DARK_GRAY    8		#define LIGHT_RED     12
//    #define BLUE  1	#define MAGENTA    5	#define LIHGT_BLUE   9		#define LIGHT_MAGENTA 13
//    #define GREEN 2	#define OLIVEN     6	#define LIGHT_GREEN  10		#define YELLOW        14
//    #define CYAN  3	#define LIGHT_GRAY 7	#define LIGHT_CYAN   11		#define WHITE         15

#include "Animation.h"

//определение контрола консоли
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

//настройка цвета курсора и заливки
void color(int i_text, int i_fill)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((i_fill << 4) | i_text));
}

//установить позицию курсора
void Position(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(hStdOut, coord);
}

Fill::Fill(int x1, int x2, int y1, int y2)
	: x1(x1), x2(x2), y1(y1), y2(y2) {}

//закрасить область
void print_fill(Fill f, int i) {
	color(i, i);
	for (int y = f.y1; y <= f.y2; y++) {
		Position(f.x1, y);
		for (int x = f.x1; x <= f.x2; x++)
			std::cout << " ";
	}
	Position(54, 39);
}

//закрасить ¤чейку с координатами х, y цветом col
void print_coord_field(int x, int y, int col) {
	int x1 = x * 3 + 1;
	int x2 = x1 + 2;
	int y1 = 37 - 2 * y;
	int y2 = y1 + 1;

	print_fill(Fill(x1, x2, y1, y2), col);
}