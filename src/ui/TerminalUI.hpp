#pragma once
#include <ncurses.h>
#include <string>
#include "../utils/MenuEnums.hpp"

#include "pages/antrian/ProcessAntrianPage.hpp"
#include "pages/antrian/ShowAntrianPage.hpp"
#include "pages/create-pesanan/CreatePesananPage.hpp"
#include "pages/menu/MenuPage.hpp"

class TerminalUI {
private:
    // 1. Pointers untuk Window
    WINDOW* headerWin;
    WINDOW* menuWin;
    WINDOW* mainWin;
    WINDOW* statusWin;
    WINDOW* infoWin;
    WINDOW* contentWin;

    // 2. Dimensi Layar
    int screenWidth;
    int screenHeight;

    // 3. State Aplikasi (Dipisahkan agar tidak campur aduk)
    std::string statusMsg;              // Khusus untuk teks notifikasi di bawah
    Menu activeMenu = Menu::LihatMenu;  // Khusus untuk menyimpan status halaman apa yang sedang aktif

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

    // 8. Objek Halaman dan Router
    MenuPage menuPage; 
    CreatePesananPage createPesananPage;
    ShowAntrianPage showAntrianPage;
    ProcessAntrianPage processAntrianPage;
    
    IPage* currentPage = nullptr; 

public:
    void init();
    void draw();
    void clearWindows(); // Diubah namanya dari refresh() agar tidak bentrok
    void close();

    void setStatusMsg(const std::string& msg);
    void setActiveMenu(Menu menu);
    int getInput();

    WINDOW* getMenuWindow() const { return menuWin; }
    WINDOW* getMainWindow() const { return mainWin; }
};