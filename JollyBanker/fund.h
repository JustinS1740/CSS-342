// Justin Singsanavong
#ifndef FUND_H
#define FUND_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Fund {
public:
    Fund() : balance_(0) {}

    bool deposit(int amount, const string& transaction);
    bool withdraw(int amount, Fund& fund, const string& transaction);
    bool withdraw(int accountId, int fundId, int amount, Fund& fund, Fund& linkedFund, const string& transaction);

    int getBalance() const;
    void logTransaction(const string& transaction);
    void printHistory() const;

private:
    int balance_;
    vector<string> history_;
};

#endif
