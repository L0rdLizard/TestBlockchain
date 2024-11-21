#include "Wallet.h"
#include <iostream>

Wallet::Wallet(const std::string& address, Blockchain& blockchain, double amount)
    : address(address), blockchain(blockchain) {
    blockchain.registerWallet(address, amount);
}

std::string Wallet::getAddress(){
    return address;
}

void Wallet::sendTransaction(const std::string& receiver, double amount) {
    if (amount <= 0) {
        throw std::runtime_error("Transaction amount must be positive!");
    }
    Transaction transaction(address, receiver, amount);
    blockchain.addTransaction(transaction);
}

double Wallet::getBalance() const {
    return blockchain.getWalletBalance(address);
}