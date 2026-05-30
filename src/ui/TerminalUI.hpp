#pragma once
#include <ncurses.h>
#include <string>

class TerminalUI {
private:
    // 1. Pointers untuk Window
    WINDOW* headerWin;
    WINDOW* menuWin;
    WINDOW* mainWin;
    WINDOW* statusWin;
    WINDOW* infoWin;

    // 2. Dimensi Layar
    int screenWidth;
    int screenHeight;

    // 3. State Aplikasi
    std::string statusMsg;

    // 4. Konstanta Layout (Ubah ukuran desain dari sini!)
    static constexpr int HEADER_HEIGHT = 3;
    static constexpr int STATUS_HEIGHT = 3;
    static constexpr int INFO_HEIGHT = 1;

    // 5. Helper Inisialisasi
    void initNcurses();
    void initColors();
    void initWindows();

    // 6. Helper Penggambaran UI
    void drawRoundedBox(WINDOW* win);
    void drawBoxWithTitle(WINDOW* win, const std::string& title, int colorPair);

    // 7. Render Masing-masing Window
    void drawHeader();
    void drawMenuBorder();
    void drawMain();
    void drawStatus();
    void drawInfo();

public:
    void init();
    void draw();
    void clearWindows(); // Diubah namanya dari refresh() agar tidak bentrok
    void close();

    void setStatus(const std::string& msg);
    int getInput();

    WINDOW* getMenuWindow() const { return menuWin; }
    WINDOW* getMainWindow() const { return mainWin; }
};