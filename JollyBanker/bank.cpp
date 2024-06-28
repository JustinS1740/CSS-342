// Justin Singsanavong
#include <iostream>
#include "jolly_banker.h"

int main(int argc, char* argv[])
{
    JollyBanker bank;
    bank.readTransactions(argv[1]);
    bank.processTransactions();
    bank.displayAllAccounts();
}
