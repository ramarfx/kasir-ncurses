#pragma once
#include <vector>
#include "../models/MenuItem.hpp"
#include "QueueManager.hpp"

using namespace std;

class Cashier
{
private:
    vector<MenuItem> daftarMenu;
    QueueManager queueManager;
    
public:
    void seedMenu();
    void tampilkanMenu();
    void cariMenu(int id);
    void buatPesanan();
    
};

