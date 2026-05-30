#include "AppController.hpp"

void AppController::run() {
    ui.init();
    bool isRunning = true;

    while (isRunning) {
        ui.draw();
        sidebar.draw(ui.getMenuWindow());

        int ch = ui.getInput();
        int action = sidebar.handleInput(ch);

        if (ch == 'q' || ch == KEY_EXIT) {
            isRunning = false;
        } else if (action != -1) {
            ui.setStatus(std::to_string(action));
        }

        ui.clearWindows();
    }

    ui.close();
}