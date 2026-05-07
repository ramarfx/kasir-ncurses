#include <iostream>
#include "QueueManager.hpp"

void QueueManager::tambahAntrian(Transaction trx) {
    antrian.push(trx);
}

void QueueManager::prosesAntrian() {
    if (!antrian.empty())
    {
        antrian.pop();
    }   
}

bool QueueManager::isEmpty() const {
    return antrian.empty();
}

Transaction QueueManager::antrianDepan() {
    return antrian.front();
}