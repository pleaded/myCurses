#ifndef WINDOW_H
#define WINDOW_H
#include "main.h"
class Window
{
	int row, col, x0, y0;
	WINDOW * w;
public:
	Window() { 
		getmaxyx(stdscr, row, col); 
		w = newwin(row, col, 0, 0); 
	}
	Window(int row, int col, int x0, int y0) : row(row), col(col), x0(x0), y0(y0) {
		w = newwin(row, col, y0, x0);
	}
	Window & operator << (const char * str) {
		wprintw(w, str);
		wrefresh(w);
		return *this;
	}
	Window & Box (int x = 0, int y = 0) {
		box(w, x, y);
		wrefresh(w);
		return *this;
	}
	Window & Border() {
		wborder(w, '|', '|', '-', '-', '+', '+', '+', '+');
		wrefresh(w);
		return *this;	
	}
	Window & Move(int x, int y) {
		for(int i = x0; i < x0 + col; i++) {
			for(int j = y0; j < y0 + row; j++) {
				/** TODO: a(j,i) << ' '; */
				mvaddch(j, i, ' ');
			}
		}
		refresh();
		mvwin(w, x, y);
		x0 = x; y0 = y;
		wrefresh(w);
		return *this;	
	}
};
#endif