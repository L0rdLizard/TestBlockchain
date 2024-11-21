#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>

struct Transaction
{
    std::string sender;
    std::string receiver;
    double amount;
    time_t timestamp;

    Transaction(const std::string &sender, const std::string &receiver, double amount)
        : sender(sender), receiver(receiver), amount(amount), timestamp(std::time(nullptr)) {}

    void printTransaction() const
    {
        std::cout << "Sender: " << sender << "\n"
                << "Receiver: " << receiver << "\n"
                << "Amount: " << amount << " TON\n"
                << "Timestamp: " << std::ctime(&timestamp) << "\n";
    }
};

#endif