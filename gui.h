#ifndef GUI_H
#define GUI_H
#include "main.h"

/*! Signleton helper */
// class OnlyOne
// {
// public:
//     static OnlyOne& Instance()
//     {
//         static OnlyOne theSingleInstance;
//         return theSingleInstance;
//     }
// private:        
//     OnlyOne(){}
//     OnlyOne(const OnlyOne& root);
//     OnlyOne& operator=(const OnlyOne&);
// };

/** TODO: make static class or singleton */

class GUI
{
public:
	static void noCur() { curs_set(0); }
	static void noEcho() { noecho(); }
	static void yesKeypad() { keypad(stdscr, TRUE); }
	static void yesColor() { start_color(); }
	static void useDefaultColor() { use_default_colors(); }
	static void Init() { initscr(); }
	static void End() { endwin(); }
};
#endif