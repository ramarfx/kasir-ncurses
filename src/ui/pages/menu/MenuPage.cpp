#include "MenuPage.hpp"

void MenuPage::draw(WINDOW *win) {
    wattron(win, COLOR_PAIR(3) | A_BOLD);
    mvwprintw(win, 1, 2, "Ini Halaman: LIHAT MENU");
    wattroff(win, COLOR_PAIR(3) | A_BOLD);
    wrefresh(win);
}

void MenuPage::clearWin(WINDOW *win) {
    werase(win);
    wrefresh(win);
}

void MenuPage::init(WINDOW *win) {
    clearWin(win);
    draw(win);
}