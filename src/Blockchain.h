#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H


#include "Transaction.h";

class Blockchain {
public:
    void addTransaction(const Transaction& transaction);
    void printAllTransactions() const;
    void getBlockchainStats() const;
private:
    std::vector<Transaction> transactions;
};

#endif