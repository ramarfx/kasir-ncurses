#include "TerminalUI.hpp"
#include <stdlib.h>

// ==========================================
// INISIALISASI
// ==========================================
void TerminalUI::init() {
    initNcurses();
    initColors();
    initWindows();
}

void TerminalUI::initNcurses() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
}

void TerminalUI::initColors() {
    start_color();
    use_default_colors();
    init_pair(1, COLOR_BLACK, COLOR_GREEN); // Warna Highlight
    init_pair(2, COLOR_BLUE, -1);           // Warna Menu
    init_pair(3, COLOR_CYAN, -1);           // Warna Judul
}

void TerminalUI::initWindows() {
    getmaxyx(stdscr, screenHeight, screenWidth);
    
    // Proteksi layar terlalu kecil
    if (screenHeight < 10 || screenWidth < 40) {
        endwin();
        printf("Ukuran terminal terlalu kecil!\n");
        exit(1);
    }
    
    ::refresh();

    int menuWidth = screenWidth / 3;
    int middleHeight = screenHeight - HEADER_HEIGHT - STATUS_HEIGHT - INFO_HEIGHT;

    headerWin = newwin(HEADER_HEIGHT, screenWidth, 0, 0);
    menuWin   = newwin(middleHeight, menuWidth, HEADER_HEIGHT, 0);
    mainWin   = newwin(middleHeight, screenWidth - menuWidth, HEADER_HEIGHT, menuWidth);
    statusWin = newwin(STATUS_HEIGHT, screenWidth, screenHeight - INFO_HEIGHT - STATUS_HEIGHT, 0);
    infoWin   = newwin(INFO_HEIGHT, screenWidth, screenHeight - INFO_HEIGHT, 0);

    keypad(menuWin, TRUE); // Aktifkan input panah
}


// ==========================================
// HELPER
// ==========================================
void TerminalUI::drawRoundedBox(WINDOW* win) {
    int w, h;
    getmaxyx(win, h, w);

    for (int i = 1; i < w - 1; i++) {
        mvwprintw(win, 0, i, "─");
        mvwprintw(win, h - 1, i, "─");
    }
    for (int i = 1; i < h - 1; i++) {
        mvwprintw(win, i, 0, "│");
        mvwprintw(win, i, w - 1, "│");
    }
    
    mvwprintw(win, 0, 0, "╭");
    mvwprintw(win, 0, w - 1, "╮");
    mvwprintw(win, h - 1, 0, "╰");
    mvwprintw(win, h - 1, w - 1, "╯");
}

void TerminalUI::drawBoxWithTitle(WINDOW* win, const std::string& title, int colorPair) {
    drawRoundedBox(win);
    wattron(win, COLOR_PAIR(colorPair) | A_BOLD);
    mvwprintw(win, 0, 2, "─%s─", title.c_str());
    wattroff(win, COLOR_PAIR(colorPair) | A_BOLD);
}


// ==========================================
// RENDER UI
// ==========================================
void TerminalUI::drawHeader() {
    drawBoxWithTitle(headerWin, "[1] Project", 3);
    mvwprintw(headerWin, 1, 2, "Aplikasi Kasir v1.0");
    wrefresh(headerWin);
}

void TerminalUI::drawMenuBorder() {
    drawBoxWithTitle(menuWin, "[2] MENU", 2);
    wrefresh(menuWin);
}

void TerminalUI::drawMain() {
    drawBoxWithTitle(mainWin, "[3] Logs", 3);

    // 
    // 

    wrefresh(mainWin);
}

void TerminalUI::drawStatus() {
    drawRoundedBox(statusWin);
    std::string currentMsg = statusMsg.empty() ? "Ready" : statusMsg;
    
    wattron(statusWin, COLOR_PAIR(1));
    mvwprintw(statusWin, 1, 2, " STATUS: %s ", currentMsg.c_str());
    wattroff(statusWin, COLOR_PAIR(1));
    
    wrefresh(statusWin);
}

void TerminalUI::drawInfo() {
    mvwprintw(infoWin, 0, 2, "← → ↑ ↓: navigasi | q: quit | enter: pilih");
    wrefresh(infoWin);
}


// ==========================================
// PUBLIC METHODS
// ==========================================
void TerminalUI::draw() {
    drawHeader();
    drawMenuBorder();
    drawMain();
    drawStatus();
    drawInfo();
}

void TerminalUI::clearWindows() {
    werase(headerWin);
    werase(menuWin);
    werase(mainWin);
    werase(statusWin);
    werase(infoWin);
}

void TerminalUI::close() {
    delwin(headerWin);
    delwin(menuWin);
    delwin(mainWin);
    delwin(statusWin);
    delwin(infoWin);
    endwin();
}

void TerminalUI::setStatus(const std::string& msg) {
    statusMsg = msg;
}

int TerminalUI::getInput() {
    return wgetch(menuWin);
}