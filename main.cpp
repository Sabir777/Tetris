#include "main.h"
#include <thread>

using namespace std::chrono_literals;

int main() {
	system("mode con cols=55 lines=40");
	SetConsoleOutputCP(866);
	setlocale(LC_ALL, "");
	Game gm; Wrapper_shape ws; Play_field pf;
	gm.init();
	ws.init();
	for (;;) {
		std::this_thread::sleep_for(25ms);
		gm.run();
		ws.run();
		pf.run();
	}
}