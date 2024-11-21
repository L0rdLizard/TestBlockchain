#ifndef WALLET_H
#define WALLET_H

#include <string>
#include "Blockchain.h"

class Wallet {
    private:
        std::string address;
        Blockchain& blockchain;
        // в реальном блокчейне нет необходимости хранить баланс в кошельке
        double balance;
    public:
        Wallet(const std::string& address, Blockchain& blockchain, double amount);
        std::string getAddress();
        void sendTransaction(const std::string& receiver, double amount);
        double getBalance();
    private:
        void updateBalance(double amount);
};

#endif