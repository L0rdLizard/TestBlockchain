#ifndef WALLET_H
#define WALLET_H

#include <string>
#include "Blockchain.h"

class Wallet {
    private:
        std::string address;
        Blockchain& blockchain;
    public:
        Wallet(const std::string& address, Blockchain& blockchain, double amount);
        std::string getAddress();
        void sendTransaction(const std::string& receiver, double amount);
        double getBalance() const;
};

#endif