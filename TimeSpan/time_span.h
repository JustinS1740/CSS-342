// Justin Singsanvong
#ifndef TIME_SPAN_H_
#define TIME_SPAN_H_
#include <iostream>
#include <cmath>
using namespace std;

class TimeSpan
{
public:
	//constructors
	TimeSpan();
	TimeSpan(float hours, float minutes, float seconds);
	TimeSpan(float minutes, float seconds);
	TimeSpan(float seconds);

	//getters
	int hours() const;
	int minutes() const;
	int seconds() const;

	//setters
	void set_time(int hours, int minutes, int seconds);

	//additional operators
	bool operator==(const TimeSpan& rhs) const;
	TimeSpan operator+(const TimeSpan& rhs) const;
	TimeSpan operator-(const TimeSpan& rhs) const;
	TimeSpan operator-() const; // Unary Negation
	bool operator!=(const TimeSpan& rhs) const;
	bool operator<(const TimeSpan& rhs) const;
	bool operator<=(const TimeSpan& rhs) const;
	bool operator>(const TimeSpan& rhs) const;
	bool operator>=(const TimeSpan& rhs) const;
	TimeSpan& operator+=(const TimeSpan& rhs);
	TimeSpan& operator-=(const TimeSpan& rhs);
	friend ostream& operator<<(ostream& stream, const TimeSpan& t); //output
	friend istream& operator>>(istream& stream, TimeSpan& t); //input


private:
	//data members
	int hours_;
	int minutes_;
	int seconds_;
};
#endif