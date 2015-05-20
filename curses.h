#ifndef CURSES_H
#define CURSES_H
#include <ncurses.h>
#include <sstream>
#include <iostream>
using namespace std;
class Curses
{
public:
	Curses(int x, int y) : Curses() { (*this)(x, y); }
	Curses() { initscr(); }
	~Curses() { endwin(); }

	Curses & operator << (const char * str) {
		printw(str);
		updateScreen();
		return *this;
	}

	Curses & operator << (char c) {
		addch( c | A_BOLD );
		updateScreen();
		return *this;
	}

	Curses & operator << (int a) {
		printw(to_string(a).c_str());
		updateScreen();
		return *this;
	}

	Curses & operator () (int x, int y) { move(y, x); return *this; }
	Curses & operator ~  () { clear(); return *this; }

	Curses & noCur()  { curs_set(0); return *this; }
	Curses & noEcho() { noecho(); return *this; }

	void updateScreen() { refresh(); }
};
#endif