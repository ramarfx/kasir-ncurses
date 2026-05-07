#include <iostream>
#include <ncurses.h>
#include "ui/TerminalUI.hpp"

int main() {
    TerminalUI ui;
    int width, height;
    getmaxyx(stdscr, height, width);

    WINDOW* menuWin = newwin(height, width / 3, 0, 0);
    WINDOW* mainWin = newwin(height, width - (width/3), 0, 0);

    ui.init();

    ui.menuWindow(menuWin);
    ui.mainWindow(mainWin);

    getch();

    ui.close();

    return 0;
}