// Justin Singsanavong
#include "account.h"
#include <iostream>

const string& Account::getFirstName() const
{
    return firstName_;
}

const string& Account::getLastName() const
{
    return lastName_;
}

int Account::getId() const
{
    return id_;
}


Fund& Account::getFund(int index)
{
    return funds_[index];
}

const string Account::fundNames[8] = {
    "Money Market",
    "Prime Money Market",
    "Long-Term Bond",
    "Short-Term Bond",
    "500 Index Fund",
    "Capital Value Fund",
    "Growth Equity Fund",
    "Growth Index Fund"
};

Account::Account(const string& first, const string& last, int id)
    : firstName_(first), lastName_(last), id_(id), funds_(8) {}

Fund& Account::getLinkedFund(int fundId) {
    switch (fundId) {
    case 0: return funds_[1]; // Money Market linked to Prime Money Market
    case 1: return funds_[0]; // Prime Money Market linked to Money Market
    case 2: return funds_[3]; // Long-Term Bond linked to Short-Term Bond
    case 3: return funds_[2]; // Short-Term Bond linked to Long-Term Bond
    default: throw invalid_argument("No linked fund available");
    }
}

void Account::printAccountSummary() const {
    cout << "Transaction History for " << firstName_ << " " << lastName_ << " by fund." << endl;
    for (int i = 0; i < funds_.size(); ++i) {
        cout << fundNames[i] << ": $" << funds_[i].getBalance() << endl;
        funds_[i].printHistory();
    }
}

void Account::displayAccountSummary() const {
    cout << firstName_ << " " << lastName_ << " Account ID: " << id_ << endl;
    for (int i = 0; i < funds_.size(); ++i) {
        cout << fundNames[i] << ": $" << funds_[i].getBalance() << endl;
    }
    cout << endl;
}

string Account::getFundName(int index) const {
    if (index >= 0 && index < 8) {
        return fundNames[index];
    }
    return "Unknown Fund";
}
