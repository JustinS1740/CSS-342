// Justin Singsanvong
#ifndef VENDING_BANK_H_
#define VENDING_BANK_H_
#include <iostream>
using namespace std;

class VendingBank
{
public:
	//constructors
	VendingBank();
	VendingBank(int id, int quarters, int dimes, int nickels, int pennies);

	//getters
	int id() const;
	int quarters() const;
	int dimes() const;
	int nickels() const;
	int pennies() const;

	//setters
	void set_id(int id);
	bool set_quarters(int amount);
	bool set_dimes(int amount);
	bool set_nickels(int amount);
	bool set_pennies(int amount);

	//public functions
	void Deposit(int amount) const;
	void Withdraw(int amount) const;
	int GetBalance() const;

private:
	// data members
	int id_;
	int quarters_;
	int dimes_;
	int nickels_;
	int pennies_;
};
#endif