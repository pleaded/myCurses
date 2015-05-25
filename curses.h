#ifndef CURSES_H
#define CURSES_H
#include "main.h"
class MyCurses
{
public:
	MyCurses(int y, int x) : MyCurses() { (*this)(y, x); }
	MyCurses() { initscr(); updateScreen(); }
	~MyCurses() { endwin(); }

	MyCurses & operator << (const char * str);
	MyCurses & operator << (char c);
	MyCurses & operator << (int a);

	MyCurses & operator () (int y, int x) { move(y, x); return *this; }
	MyCurses & operator ~  () { clear(); return *this; }

	MyCurses & noCur() { curs_set(0); return *this; }
	MyCurses & noEcho() { noecho(); return *this; }
	MyCurses & yesKeypad() { keypad(stdscr, TRUE); return *this; }
	MyCurses & yesColor() { start_color(); return *this; }
	MyCurses & useDefaultColor() { use_default_colors(); return *this; }

	void updateScreen() { refresh(); }
};
#endif