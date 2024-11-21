#include <iostream>
#include "Blockchain.h"
#include "Wallet.h"

int main() {
    Blockchain blockchain;
    Wallet alice("Alice", blockchain, 100.0);
    Wallet bob("Bob", blockchain, 11.0);

    bob.sendTransaction(alice.getAddress(), 12.0);
    std::cout << "Alice's balance: " << alice.getAddress() << " " << alice.getBalance() << "\n";
    std::cout << "Bob's balance: " << bob.getAddress() << " " << bob.getBalance() << "\n";

}