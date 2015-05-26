#include "window.h"

Window & Window::operator << (const char * str) {
	wprintw(w, str);
	wrefresh(w);
	return *this;
}
Window & Window::Box (int y = 0, int x = 0) {
	box(w, y, x);
	wrefresh(w);
	return *this;
}
Window & Window::Border() {
	wborder(w, '|', '|', '-', '-', '+', '+', '+', '+');
	wrefresh(w);
	return *this;	
}