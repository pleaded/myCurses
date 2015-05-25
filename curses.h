#ifndef CURSES_H
#define CURSES_H
#include "main.h"

class MyCurses
{
public:
	MyCurses & operator << (const char * str);
	MyCurses & operator << (char c);
	MyCurses & operator << (int a);

	MyCurses & operator () (int y, int x) { move(y, x); return *this; }
	MyCurses & operator ~  () { clear(); return *this; }

	MyCurses & vLine(char background_char, int quantity) {
		vline(background_char, quantity);
		return *this;
	}
	MyCurses & hLine(char background_char, int quantity) {
		hline(background_char, quantity);
		return *this;
	}

	void updateScreen() { refresh(); }
};
#endif