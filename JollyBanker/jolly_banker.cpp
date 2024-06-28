// Justin Singsanavong
#include "jolly_banker.h"
#include <fstream>
#include <sstream>

void JollyBanker::readTransactions(const string& filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        transactions_.push(line);
    }
}

void JollyBanker::processTransactions() {
    while (!transactions_.empty()) {
        string transaction = transactions_.front();
        transactions_.pop();
        char type = transaction[0];
        switch (type) {
        case 'O': openAccount(transaction); break;
        case 'D': deposit(transaction); break;
        case 'W': withdraw(transaction); break;
        case 'T': transfer(transaction); break;
        case 'A': displayHistory(transaction); break;
        case 'F': displayFundHistory(transaction); break;
        default: cerr << "Unknown transaction type: " << type << endl;
        }
    }
}

void JollyBanker::displayAllAccounts() const {
    accounts_.Display();
    cout << "--------------------------------------------------------------------------------------------------------------" << endl;
}

void JollyBanker::openAccount(const string& transaction) {
    istringstream ss(transaction);
    char type;
    int id;
    string first, last;
    ss >> type >> id >> last >> first;
    Account* account = new Account(first, last, id);
    if (!accounts_.Insert(account)) {
        cerr << "ERROR: Account " << id << " already exists. Transaction Refused." << endl;
        delete account;
    }
}

void JollyBanker::deposit(const string& transaction) {
    istringstream ss(transaction);
    char type;
    int id, fundId, amount;
    ss >> type >> id >> fundId >> amount;
    Account* account;
    if (accounts_.Retrieve(id, account)) {
        account->getFund(fundId).deposit(amount, transaction);
    }
    else {
        cerr << "ERROR: Account " << id << " not found." << endl;
    }
}

void JollyBanker::withdraw(const string& transaction) {
    istringstream ss(transaction);
    char type;
    int id, fundId, amount;
    ss >> type >> id >> fundId >> amount;
    Account* account;
    if (accounts_.Retrieve(id, account)) {
        try {
            Fund& fund = account->getFund(fundId);
            Fund& linkedFund = account->getLinkedFund(fundId);
            if (!fund.withdraw(id, fundId, amount, fund, linkedFund, transaction)) {
                cerr << "ERROR: Not enough funds to withdraw " << amount << " from "
                    << account->getFirstName() << " " << account->getLastName() << " " << account->getFundName(fundId) << endl;
            }
        }
        catch (const invalid_argument& e) {
            if (!account->getFund(fundId).withdraw(amount, account->getFund(fundId), transaction)) {
                cerr << "ERROR: Not enough funds to withdraw " << amount << " from "
                    << account->getFirstName() << " " << account->getLastName() << " " << account->getFundName(fundId) << endl;
            }
        }
    }
    else {
        cerr << "ERROR: Account " << id << " not found." << endl;
    }
}

void JollyBanker::transfer(const string& transaction) {
    istringstream ss(transaction);
    char type;
    int fromId, fromFundId, toId, toFundId, amount;
    ss >> type >> fromId >> fromFundId >> toId >> toFundId >> amount;
    Account* fromAccount = nullptr;
    Account* toAccount = nullptr;
    bool fromAccountFound = accounts_.Retrieve(fromId, fromAccount);
    bool toAccountFound = accounts_.Retrieve(toId, toAccount);

    if (fromAccountFound && toAccountFound) {
        try {
            Fund& fromFund = fromAccount->getFund(fromFundId);
            Fund& linkedFund = fromAccount->getLinkedFund(fromFundId);
            if (fromFund.withdraw(fromId, fromFundId, amount, fromFund, linkedFund, transaction)) {
                toAccount->getFund(toFundId).deposit(amount, transaction);
            }
            else {
                cerr << "ERROR: Not enough funds to withdraw " << amount << " from " << fromAccount->getFirstName()
                    << " " << fromAccount->getLastName() << " " << fromAccount->getFundName(fromFundId) << endl;
            }
        }
        catch (const invalid_argument& e) {
            if (fromAccount->getFund(fromFundId).withdraw(amount, fromAccount->getFund(fromFundId), transaction)) {
                toAccount->getFund(toFundId).deposit(amount, transaction);
            }
            else {
                cerr << "ERROR: Not enough funds to withdraw " << amount << " from " << fromAccount->getFirstName()
                    << " " << fromAccount->getLastName() << " " << fromAccount->getFundName(fromFundId) << endl;
            }
        }
    }
    else {
        if (!fromAccountFound) {
            cerr << "ERROR: Account " << fromId << " not found. Transfer unsuccessful." << endl;
        }
        if (!toAccountFound) {
            cerr << "ERROR: Account " << toId << " not found. Transfer unsuccessful." << endl;
        }
    }
}

void JollyBanker::displayHistory(const string& transaction) {
    istringstream ss(transaction);
    char type;
    int id;
    ss >> type >> id;
    Account* account;
    if (accounts_.Retrieve(id, account)) {
        account->printAccountSummary();
        cout << "--------------------------------------------------------------------------------------------------------------" << endl;
    }
    else {
        cerr << "ERROR: Account " << id << " not found." << endl;
    }
}

void JollyBanker::displayFundHistory(const string& transaction) {
    istringstream ss(transaction);
    char type;
    int id, fundId;
    ss >> type >> id >> fundId;
    Account* account;
    if (accounts_.Retrieve(id, account)) {
        cout << "Transaction History for " << account->getFirstName() << " " << account->getLastName() << " " << account->getFundName(fundId) 
            << ": " << account->getFund(fundId).getBalance() << endl;
        account->getFund(fundId).printHistory();
        cout << "--------------------------------------------------------------------------------------------------------------" << endl;
    }
    else {
        cerr << "ERROR: Account " << id << " not found." << endl;
    }
}
