#include <iostream>
#include "Blockchain.h"
#include "Wallet.h"

int main() {
    Blockchain blockchain;
    Wallet alice("Alice", blockchain, 100.0);
    Wallet bob("Bob", blockchain, 11.0);
    Wallet jack("Jack", blockchain, 50.0);

    try {
        bob.sendTransaction(alice.getAddress(), 10.0);
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        alice.sendTransaction(jack.getAddress(), 10.0);
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Alice's balance: " << alice.getAddress() << " " << alice.getBalance() << "\n";
    std::cout << "Bob's balance: " << bob.getAddress() << " " << bob.getBalance() << "\n";
    std::cout << "Jack's balance: " << jack.getAddress() << " " << jack.getBalance() << "\n";

    std::cout << "\nAll transactions:\n\n";
    blockchain.printAllTransactions();

    std::cout << "\nBlockchain stats:\n\n";
    blockchain.getBlockchainStats();

    return 0;
}