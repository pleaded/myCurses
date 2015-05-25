#ifndef WINDOW_H
#define WINDOW_H
#include "main.h"
class Window
{
	int row, col, y0, x0;
	WINDOW * w;
public:
	Window() { 
		getmaxyx(stdscr, row, col); 
		w = newwin(row, col, 0, 0); 
	}
	Window(int row, int col, int y0, int x0) : row(row), col(col), y0(y0), x0(x0) {
		w = newwin(row, col, y0, x0);
	}
	Window & operator << (const char * str) {
		wprintw(w, str);
		wrefresh(w);
		return *this;
	}
	Window & Box (int y = 0, int x = 0) {
		box(w, y, x);
		wrefresh(w);
		return *this;
	}
	Window & Border() {
		wborder(w, '|', '|', '-', '-', '+', '+', '+', '+');
		wrefresh(w);
		return *this;	
	}
	Window & operator() (int y, int x) {
		for(int i = x0; i < x0 + col; i++) {
			for(int j = y0; j < y0 + row; j++) {
				/** TODO: a(i, j) << ' '; */
				mvaddch(j, i, ' ');
			}
		}
		refresh(); // to make the window clean

		y0 = y; x0 = x;
		mvwin(w, y0, x0);
		wrefresh(w);
		return *this;
	}
};
#endif