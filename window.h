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
	~Window() {
		delwin(w);
	}

	Window & operator << (const char *);
	Window & Box (int, int);
	Window & Border();


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
	Window & operator() () {
		mvwin(w, x0, y0);
		wrefresh(w);
		refresh();
		return *this;
	}
};
#endif