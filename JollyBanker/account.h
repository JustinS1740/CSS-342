// Justin Singsanavong
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include "fund.h"
#include <iostream>
using namespace std;

class Account {
public:
    Account(const string& first, const string& last, int id);
    int getId() const;
    const string& getFirstName() const;
    const string& getLastName() const;
    Fund& getFund(int index);
    Fund& getLinkedFund(int fundId);
    void printAccountSummary() const;
    void displayAccountSummary() const;
    string getFundName(int index) const;

private:
    string firstName_;
    string lastName_;
    int id_;
    vector<Fund> funds_;
    static const string fundNames[8];
};
#endif
