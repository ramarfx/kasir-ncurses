#pragma once
#include "ncurses.h"

class IPage {
public:
  virtual void draw(WINDOW *win) = 0;
  virtual void clearWin(WINDOW *win) = 0;
  virtual void init(WINDOW *win) = 0;
  
  virtual ~IPage() {}
};