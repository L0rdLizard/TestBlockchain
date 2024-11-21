#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Transaction.h"

class Blockchain {
public:
    void addTransaction(const Transaction& transaction);
    void printAllTransactions() const;
    void getBlockchainStats() const;
    double getWalletBalance(const std::string& walletAddress) const;
private:
    std::vector<Transaction> transactions;
};

#endif