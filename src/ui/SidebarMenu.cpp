#include "SidebarMenu.hpp"

SidebarMenu::SidebarMenu() {
    items = {"1. Lihat Menu", "2. Buat Pesanan", "3. Lihat Antrian",
             "4. Proses Antrian", "0. Keluar"};
    selectedItem = 0;
}

void SidebarMenu::draw(WINDOW* win) {
    for (int i = 0; i < (int)items.size(); i++) {
        if (i == selectedItem) {
            wattron(win, A_REVERSE);
        }
        mvwprintw(win, i + 1, 2, "%s", items[i].c_str());

        if (i == selectedItem) {
            wattroff(win, A_REVERSE);
        }
    }
    wrefresh(win);
}

int SidebarMenu::handleInput(int ch) {
    if (ch == KEY_UP) {
        selectedItem--;
        if (selectedItem < 0) selectedItem = 0;
    } else if (ch == KEY_DOWN) {
        selectedItem++;
        if (selectedItem >= (int)items.size()) selectedItem = (int)items.size() - 1;
    } else if (ch == 10 || ch == KEY_ENTER) {
        return selectedItem; // Baru berpindah saat ENTER ditekan
    }

    return -1;
}