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
    init_pair(2, COLOR_BLUE, -1);
    
    int width, height;
    getmaxyx(stdscr, height, width);
    
    ::refresh();
    
    int menuWidth = width / 3;
    int statusHeight = 3;
    int infoWinHeight = 1;
    
    menuWin = newwin(height - statusHeight - infoWinHeight, menuWidth, 0, 0);
    mainWin = newwin(height - statusHeight - infoWinHeight, width - menuWidth, 0, menuWidth);
    statusWin = newwin(statusHeight, width, height - statusHeight - infoWinHeight , 0);
    infoWin = newwin(infoWinHeight, width, height - infoWinHeight, 0);
    
    keypad(menuWin, TRUE);
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

void infoWindow(WINDOW* win) {
    wattron(win, COLOR_PAIR(2));
    mvwprintw(win, 0, 2, "← → ↑ ↓ navigasi | q: quit | STATUS: ");
    wattroff(win, COLOR_PAIR(2));
    wrefresh(win);
}

void TerminalUI::setStatus(const string& msg) { this->msg = msg; }

void TerminalUI::draw() {
    menuWindow(menuWin);
    mainWindow(mainWin);
    statusWindow(statusWin, msg);
    infoWindow(infoWin);
}

void TerminalUI::refresh() {
    werase(menuWin);
    werase(mainWin);
    werase(statusWin);
    werase(infoWin);
}

void TerminalUI::close() {
    delwin(menuWin);
    delwin(mainWin);
    delwin(statusWin);
    delwin(infoWin);
    endwin();
}

int TerminalUI::getInput() {
    return wgetch(menuWin);
}