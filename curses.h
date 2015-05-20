#ifndef CURSES_H
#define CURSES_H
#include <ncurses.h>

using namespace std;
class MyCurses
{
public:
	MyCurses(int x, int y) : MyCurses() { (*this)(x, y); }
	MyCurses() { initscr(); }
	~MyCurses() { endwin(); }

	MyCurses & operator << (const char * str);
	MyCurses & operator << (char c);
	MyCurses & operator << (int a);

	MyCurses & operator () (int x, int y) { move(y, x); return *this; }
	MyCurses & operator ~  () { clear(); return *this; }

	MyCurses & noCur() { curs_set(0); return *this; }
	MyCurses & noEcho() { noecho(); return *this; }

	void updateScreen() { refresh(); }
};
#endif