#pragma once
#include <ncurses.h>
#include <string>

using namespace std;

class TerminalUI {
    private:
        WINDOW* menuWin;
        WINDOW* mainWin;
        WINDOW* statusWin;
        WINDOW* infoWin;
        string msg;

    public:
        void init();
        void draw();
        void refresh();
        void close();

        void setStatus(const string& msg);
        int getInput();
};