#include <iostream>
#include "ui/TerminalUI.hpp"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");
    TerminalUI ui;
    ui.init();

    bool isRunning = true;

    while (isRunning) {
        ui.draw();

        int ch = ui.getInput();

        switch (ch) {
            case KEY_UP:
                ui.setStatus("Ke atas");
                break;

            case KEY_DOWN:
                ui.setStatus("Ke bawah");
                break;

            case 10:
            case KEY_ENTER:
                ui.setStatus("Enter ditekan");
                break;

            case '0':
            case 'q':
                isRunning = false;
                break;
        }

        ui.refresh();
    }

    ui.close();

    return 0;
}