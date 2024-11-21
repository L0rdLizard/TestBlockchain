#include "Wallet.h"
#include <iostream>

Wallet::Wallet(const std::string& address, Blockchain& blockchain, double amount)
    : address(address), blockchain(blockchain) {
        Transaction transaction( "Genesis", address, amount);
        blockchain.addTransaction(transaction);
        updateBalance(amount);
    }

std::string Wallet::getAddress(){
    return address;
}

void Wallet::sendTransaction(const std::string& receiver, double amount) {
    if (amount <= 0) {
        throw std::runtime_error("Transaction amount must be positive!");
    }
    updateBalance(-amount);
    Transaction transaction(address, receiver, amount);
    try {
        blockchain.addTransaction(transaction);
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}

double Wallet::getBalance() {
    balance = blockchain.getWalletBalance(address);
    return balance;
}

void Wallet::updateBalance(double amount) {
    /*  
        данная проверка требуется по заданию, но не имеет смысла,
        так как эта провера происходит на стороне блокчейна
    */
    if (balance + amount < 0) {
        throw std::runtime_error("Wallet balance is negative!");
    }
    balance += amount;
}
