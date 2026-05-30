#include "ShowAntrianPage.hpp"
#include <ncurses.h>

void ShowAntrianPage::draw(WINDOW *win) {
  wattron(win, COLOR_PAIR(3) | A_BOLD);
  mvwprintw(win, 1, 2, "Ini Halaman: Show Antrian");
  wattroff(win, COLOR_PAIR(3) | A_BOLD);
  wrefresh(win);
}

void ShowAntrianPage::clearWin(WINDOW *win) {
  werase(win);
  wrefresh(win);
}

void ShowAntrianPage::init(WINDOW *win) {
  clearWin(win);
  draw(win);
}