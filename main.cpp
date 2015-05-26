// #include "main.h"
#include "curses.h"
#include "window.h"

int main(int argc,char *argv[])
{
	GUI::Init();
	GUI::noCur();
	GUI::noEcho();
	GUI::yesKeypad();
	GUI::yesColor();
	GUI::useDefaultColor();

	int x, y;
	x = 25; y = 5;

	MyCurses a;
	Window w(10, 10, y, x);
	Window s(10, 10, x + 5, y + 5);
	s.Border();
	s();
	w.Border();
	a(5, 7);
	a.vLine('@', 10);

	char c = 0;
	while(c != 'q') {
		c = getch();
		switch(c) {
			case 'w' : {
				y--;
				break;
			}
			case 'a' : {
				x--;
				break;
			}
			case 's' : {
				y++;
				break;
			}
			case 'd' : {
				x++;
				break;
			}
		}
		s();
		w(y, x);
	}
	getch();
	GUI::End();
}