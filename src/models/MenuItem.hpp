#pragma once
#include <string>

using namespace std;

class MenuItem
{
private:
    int id;
    string nama;
    int harga;

public:
    MenuItem();
    MenuItem(int id, string nama, int harga);

    int getId() const;
    string getNama() const;
    int getHarga() const;
};

