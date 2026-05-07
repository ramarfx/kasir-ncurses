#include "TerminalUI.hpp"
#include <ncurses.h>

void TerminalUI::init() {
    initscr();
    cbreak();
    noecho();
}

void TerminalUI::menuWindow(WINDOW* win) {
    box(win, 0, 0);
    mvwprintw(win, 1, 2, "MENU");

    mvwprintw(win, 3, 2, "1. Lihat menu");
    mvwprintw(win, 4, 2, "2. Buat Pesanan");
    mvwprintw(win, 5, 2, "3. Lihat Antrian");
    mvwprintw(win, 6, 2, "4. Proses Antrian");
    mvwprintw(win, 7, 2, "0. Exit");

    wrefresh(win);
}

void TerminalUI::mainWindow(WINDOW* win) {
    box(win, 0, 0);
    mvwprintw(win, 1, 2, "ANTRIAN");

    mvwprintw(win, 3, 2, "ujang");
    mvwprintw(win, 4, 2, "asep");
    mvwprintw(win, 5, 2, "kekep");

    wrefresh(win);
}

void TerminalUI::close() {
    endwin();
}