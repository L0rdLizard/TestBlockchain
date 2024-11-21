#include "Blockchain.h";


void Blockchain::addTransaction(const Transaction& transaction) {
    transactions.push_back(transaction);
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
