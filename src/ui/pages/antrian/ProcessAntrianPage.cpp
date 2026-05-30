#include "ProcessAntrianPage.hpp"
#include <ncurses.h>

void ProcessAntrianPage::draw(WINDOW *win) {
  wattron(win, COLOR_PAIR(3) | A_BOLD);
  mvwprintw(win, 1, 2, "Ini Halaman: Process Antrian");
  wattroff(win, COLOR_PAIR(3) | A_BOLD);
  wrefresh(win);
}

void ProcessAntrianPage::clearWin(WINDOW *win) {
  werase(win);
  wrefresh(win);
}

void ProcessAntrianPage::init(WINDOW *win) {
  clearWin(win);
  draw(win);
}