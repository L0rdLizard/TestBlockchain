#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Transaction.h"

class Blockchain {
public:
    void addTransaction(const Transaction& transaction);
    void printAllTransactions() const;
    void getBlockchainStats() const;
    double getWalletBalance(const std::string& walletAddress) const;
    void registerWallet(const std::string& walletAddress, double initialBalance);
private:
    std::vector<Transaction> transactions;
    std::map<std::string, double> walletBalances;
};

#endif