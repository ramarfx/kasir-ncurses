#pragma once
#include "../ui/TerminalUI.hpp"
#include "../ui/SidebarMenu.hpp"

class AppController {
    private:
        TerminalUI ui;
        SidebarMenu sidebar;

    public:
        void run();
};