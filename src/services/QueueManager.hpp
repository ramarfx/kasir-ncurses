#pragma once
#include <queue>
#include "../models/Transaction.hpp"

using namespace std;

class QueueManager
{
private:
    queue<Transaction> antrian;

public:
  void tambahAntrian(Transaction trx);
  void prosesAntrian();
  bool isEmpty() const;

  Transaction antrianDepan();
};
