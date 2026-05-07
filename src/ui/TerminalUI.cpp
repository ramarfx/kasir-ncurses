#include "TerminalUI.hpp"

#include <ncurses.h>

#include <string>

using namespace std;

void TerminalUI::init() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);

    start_color();
    use_default_colors();
    init_pair(1, COLOR_BLACK, COLOR_GREEN);

    int width, height;
    getmaxyx(stdscr, height, width);

    refresh();

    int menuWidth = width / 3;
    int statusHeight = 3;

    menuWin = newwin(height - statusHeight, menuWidth, 0, 0);
    mainWin = newwin(height - statusHeight, width - (width / 3), 0, menuWidth);
    statusWin = newwin(statusHeight, width, height - statusHeight, 0);
}

void menuWindow(WINDOW* win) {
    box(win, 0, 0);
    mvwprintw(win, 1, 2, "MENU");

    mvwprintw(win, 3, 2, "1. Lihat menu");
    mvwprintw(win, 4, 2, "2. Buat Pesanan");
    mvwprintw(win, 5, 2, "3. Lihat Antrian");
    mvwprintw(win, 6, 2, "4. Proses Antrian");
    mvwprintw(win, 7, 2, "0. Exit");

    wrefresh(win);
}

void mainWindow(WINDOW* win) {
    box(win, 0, 0);
    mvwprintw(win, 1, 2, "ANTRIAN");

    mvwprintw(win, 3, 2, "- ujang");
    mvwprintw(win, 4, 2, "- asep");
    mvwprintw(win, 5, 2, "- kekep");

    wrefresh(win);
}

void statusWindow(WINDOW* win, string& msg) {
    box(win, 0, 0);

    if (msg.empty()) {
        msg = "Ready";
    }

    mvwprintw(win, 1, 2, "%s", msg.c_str());
    wrefresh(win);
}

void TerminalUI::setStatus(const string& msg) { this->msg = msg; }

void TerminalUI::draw() {
    menuWindow(menuWin);
    mainWindow(mainWin);
    statusWindow(statusWin, msg);
}

void TerminalUI::close() {
    delwin(menuWin);
    delwin(mainWin);
    delwin(statusWin);
    endwin();
}