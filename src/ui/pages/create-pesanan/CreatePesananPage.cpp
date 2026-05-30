#include "CreatePesananPage.hpp"
#include <ncurses.h>

void CreatePesananPage::draw(WINDOW *win) {
    wattron(win, COLOR_PAIR(3) | A_BOLD);
    mvwprintw(win, 1, 2, "Ini Halaman: BUAT PESANAN");
    wattroff(win, COLOR_PAIR(3) | A_BOLD);
    wrefresh(win);
}

void CreatePesananPage::clearWin(WINDOW *win) {
    werase(win);
    wrefresh(win);
}

void CreatePesananPage::init(WINDOW *win) {
    clearWin(win);
    draw(win);
}