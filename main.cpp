#include "curses.h"

int main(int argc,char *argv[])
{
	int x = 10;
	int y = 20;
	MyCurses a(x, y);
	a.noEcho().noCur();
	while(true) {
		a(x, y) << "Hello";
		char c;
		c = getch();
		~a;
		switch(c) {
			case 'w': {
				y--;
				break;
			}
			case 's': {
				y++;
				break;
			}
			case 'a': {
				x--;
				break;
			}
			case 'd': {
				x++;
				break;
			}
		}
	}
	getch();
}