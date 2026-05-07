#pragma once
#include <ncurses.h>

class TerminalUI {
    public:
        void init();
        void menuWindow(WINDOW* win);
        void mainWindow(WINDOW* win);
        void close();
};