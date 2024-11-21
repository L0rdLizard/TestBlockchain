#include "Blockchain.h"


void Blockchain::addTransaction(const Transaction& transaction) {
    if (walletBalances[transaction.sender] < transaction.amount) {
        throw std::runtime_error("Insufficient funds for transaction!");
    }

    transactions.push_back(transaction);
    walletBalances[transaction.sender] -= transaction.amount;
    walletBalances[transaction.receiver] += transaction.amount;
}

double Blockchain::getWalletBalance(const std::string& walletAddress) const {
    auto it = walletBalances.find(walletAddress);
    return it != walletBalances.end() ? it->second : 0.0;
}

void Blockchain::registerWallet(const std::string& walletAddress, double initialBalance = 0.0) {
    if (walletBalances.count(walletAddress)) {
        throw std::runtime_error("Wallet already exists!");
    }
    walletBalances[walletAddress] = initialBalance;
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
