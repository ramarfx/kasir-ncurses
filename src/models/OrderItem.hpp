#pragma once
#include "MenuItem.hpp"

class OrderItem
{
private:
    MenuItem item;
    int qty;
public:
    OrderItem(MenuItem item, int qty);

    int getSubtotal() const;
    int getItem() const;
    int getQty() const;
};
