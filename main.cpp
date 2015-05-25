// #include "main.h"
#include "curses.h"
#include "window.h"

int main(int argc,char *argv[])
{
	int x, y;
	x = 25; y = 5;

	MyCurses a;
	a.noEcho().noCur();
	Window w(10, 10, y, x);
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
		w(y, x);
	}
	getch();
}