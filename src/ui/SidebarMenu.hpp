#pragma once
#include <ncurses.h>
#include <vector>
#include <string>

using namespace std;

class SidebarMenu {
    private:
        vector<string> items;
        int selectedItem;
    
    public:
        SidebarMenu();
        void draw(WINDOW* win);
        int handleInput(int ch);
};