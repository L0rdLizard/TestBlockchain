#include "Blockchain.h"


void Blockchain::addTransaction(const Transaction& transaction) {
    const double minBalance = 0.01;

    if ((getWalletBalance(transaction.sender) - transaction.amount < minBalance) && (transaction.sender != "Genesis")) {
        throw std::runtime_error("Transaction denied! Sender balance would fall below the minimum allowed.");
    }

    if (transaction.amount <= 0) {
        throw std::runtime_error("Transaction amount must be positive!");
    }

    transactions.push_back(transaction);
}

double Blockchain::getWalletBalance(const std::string& walletAddress) const {
    double balance = 0.0;

    for (const auto& transaction : transactions) {
        if (transaction.receiver == walletAddress) {
            balance += transaction.amount;
        }
        if (transaction.sender == walletAddress) {
            balance -= transaction.amount;
        }
    }

    return balance;
}

void Blockchain::printAllTransactions() const {
    for (const auto& transaction : transactions) {
        transaction.printTransaction();
        std::cout << "--------------------\n";
    }
}

void Blockchain::getBlockchainStats() const {
    size_t totalTransactions = transactions.size();
    double totalAmount = 0;
    for (const auto& transaction : transactions) {
        totalAmount += transaction.amount;
    }
    std::cout << "Total Transactions: " << totalTransactions << "\n"
            << "Total Amount: " << totalAmount << "\n";
}
