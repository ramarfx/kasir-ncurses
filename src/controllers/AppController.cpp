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
            // CONTROLLER MENYURUH UI BERGANTI HALAMAN (Polymorphism/Routing Trigger)
            ui.setActiveMenu(static_cast<Menu>(action));
            
            // Opsional: Bikin teks status keren di bawah
            ui.setStatusMsg("Berpindah ke menu...");
        }

        ui.clearWindows();
    }

    ui.close();
}