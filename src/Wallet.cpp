#include "Wallet.h";
#include <iostream>

void Wallet::updateBalance(double amount){
    if (balance + amount < 0){
        std::cout << "Not enough funds!\n";
        return;
    }
    balance += amount;
}

double Wallet::getBalance(){
    return balance;
}

std::string Wallet::getOwner(){
    return owner;
}

void Wallet::sendTransaction(Blockchain& blockchain, const std::string& receiver, double amount) {
    const double minBalance = 0.01;
    if (amount <= 0) {
        throw std::runtime_error("Transaction denied! Amount must be positive\n");
    }
    if (balance - amount < minBalance) {
        throw std::runtime_error("Transaction denied! Minimum balance requirement not met\n");
    }
    Transaction transaction(owner, receiver, amount);
    blockchain.addTransaction(transaction);
    updateBalance(-amount);
}

void Wallet::receiveTransaction(double amount) {
    if (amount < 0) {
        throw std::runtime_error("Invalid incoming transaction amount! Transaction must be positive\n");
    }
    updateBalance(amount);
}