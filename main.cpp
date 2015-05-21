// #include "main.h"
#include "curses.h"
#include "window.h"

int main(int argc,char *argv[])
{
	MyCurses a;
	a.noEcho().noCur();
	Window w(10, 10, 10, 0);
	w.Border();

	int x, y;
	w.Move(50, 50);

	getch();
}