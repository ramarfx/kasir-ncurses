#pragma once
#include <vector>
#include "OrderItem.hpp"

using namespace std;

class Transaction
{
private:
    int nomorAntrian;
    vector<OrderItem> items;
public:
    Transaction(int nomor);
    
    void tambahItem(OrderItem item);
    int hitungTotal() const;
    int getNomorAntrian() const;
    vector<OrderItem> getItems() const;
};