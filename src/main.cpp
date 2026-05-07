#include <iostream>
#include "ui/TerminalUI.hpp"

int main() {
    TerminalUI ui;

    ui.init();
    ui.draw();

    getch();

    ui.close();

    return 0;
}