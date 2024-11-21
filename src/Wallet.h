#ifndef WALLET_H
#define WALLET_H

#include <string>
#include "Blockchain.h"

class Wallet {
    public:
        Wallet(const std::string& owner, double initialBalance = 0.0)
            : owner(owner), balance(initialBalance) {}
        double getBalance();
        std::string getOwner();
        void sendTransaction(Blockchain& blockchain, const std::string& receiver, double amount);
        void receiveTransaction(double amount);
    private:
        void updateBalance(double amount);
        std::string owner;
        double balance;
};

#endif