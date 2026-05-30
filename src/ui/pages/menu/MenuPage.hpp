#pragma once
#include "../IPage.hpp"
#include <ncurses.h>

class MenuPage : public IPage {
public:
  void draw(WINDOW *win) override;
  void init(WINDOW *win) override;
  void clearWin(WINDOW *win) override;
};