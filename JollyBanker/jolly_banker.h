// Justin Singsanavong
#ifndef JOLLY_BANKER_H
#define JOLLY_BANKER_H

#include "account.h"
#include "bs_tree.h"
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class JollyBanker {
public:
    void readTransactions(const string& filename);
    void processTransactions();
    void displayAllAccounts() const;

private:
    void openAccount(const string& transaction);
    void deposit(const string& transaction);
    void withdraw(const string& transaction);
    void transfer(const string& transaction);
    void displayHistory(const string& transaction);
    void displayFundHistory(const string& transaction);

    queue<string> transactions_;
    BSTree accounts_;
};

#endif
