// Justin Singsanavong
#include "fund.h"

bool Fund::deposit(int amount, const string& transaction) {
    if (amount < 0) {
        cerr << "ERROR: Negative amount not allowed. " << endl;
        logTransaction(transaction + " (Failed)");
        return false;
    }
    balance_ += amount;
    logTransaction(transaction);
    return true;
}

bool Fund::withdraw(int amount, Fund& fund, const string& transaction) {
    if (balance_ >= amount) {
        balance_ -= amount;
        logTransaction(transaction);
        return true;
    }
    else if (fund.getBalance() == 0) {
        logTransaction(transaction);
        return true;
    }
    logTransaction(transaction + " (Failed)");
    return false;
}

bool Fund::withdraw(int accountId, int fundId, int amount, Fund& fund, Fund& linkedFund, const string& transaction) {
    if (balance_ >= amount) {
        balance_ -= amount;
        logTransaction(transaction);
        return true;
    }
    else {
        int totalAvailable = balance_ + linkedFund.getBalance();
        if (totalAvailable >= amount) {
            int neededFromLinked = amount - balance_;
            linkedFund.withdraw(neededFromLinked, linkedFund, "W " + to_string(accountId) + " " + to_string(fundId) + " " + to_string(neededFromLinked));
            fund.withdraw(neededFromLinked, fund, "W " + to_string(accountId) + " " + to_string(fundId) + " " + to_string(balance_));
            fund.balance_ = 0;
            return true;
        }
    }
    logTransaction(transaction + " (Failed)");
    return false;
}

int Fund::getBalance() const
{
    return balance_;
}

void Fund::logTransaction(const string& transaction) {
    history_.push_back(transaction);
}

void Fund::printHistory() const {
    for (int i = 0; i < history_.size(); i++) {
        cout << "  " << history_[i] << endl;
    }
}
