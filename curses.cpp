#include "curses.h"
#include <iostream>

MyCurses & MyCurses::operator << (const char * str) {
	printw(str);
	updateScreen();
	return *this;
}

MyCurses & MyCurses::operator << (char c) {
	addch( c | A_BOLD );
	updateScreen();
	return *this;
}

MyCurses & MyCurses::operator << (int a) {
	printw(std::to_string(a).c_str());
	updateScreen();
	return *this;
}