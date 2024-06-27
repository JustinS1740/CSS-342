// Justin Singsanvong
#include <iostream>
#include "time_span.h"
using namespace std;

bool CheckValues(TimeSpan time, int hours, int minutes, int seconds)
{
	if ((time.hours() != hours) || (time.minutes() != minutes) || (time.seconds()
		!= seconds))
	{
		return false;
	}
	return true;
}

bool TestZeros()
{
	TimeSpan ts(0, 0, 0);
	return CheckValues(ts, 0, 0, 0);
}

bool TestFloatSeconds()
{
	TimeSpan ts(127.86);
	return CheckValues(ts, 0, 2, 8);
}

bool TestNegativeMinute()
{
	TimeSpan ts(8, -23, 0);
	return CheckValues(ts, 7, 37, 0);
}

bool TestNegativeHour()
{
	TimeSpan ts(-3, 73, 2);
	return CheckValues(ts, -1, -46, -58);
}

bool TestNegativeSeconds()
{
	TimeSpan ts(3, 30, -9);
	return CheckValues(ts, 3, 29, 51);
}

bool TestAdd()
{
	TimeSpan ts1, ts2(5), ts3(7, 0), ts4(4, 0, 0);
	TimeSpan add_it_up = ts1 + ts2 + ts3 + ts4;
	return CheckValues(add_it_up, 4, 7, 5);
}

bool TestMinus() 
{
	TimeSpan ts1(4, 5, 6), ts2(2, 2, 2);
	TimeSpan add_it_up = ts1 - ts2;
	return CheckValues(add_it_up, 2, 3, 4);
}

bool TestNegation()
{
	TimeSpan ts(3, 36, 23);
	return CheckValues(ts, -3, -36, -23);
}

bool TestAddInPlace()
{
	TimeSpan ts1(5, 6, 7);
	TimeSpan ts2(1, 1, 1);
	if ((!CheckValues(ts1, 5, 6, 7)) || (!CheckValues(ts2, 1, 1, 1)))
	{
		return false;
	}
	ts1 += ts2;
	if ((!CheckValues(ts1, 6, 7, 8)) || (!CheckValues(ts2, 1, 1, 1)))
	{
		return false;
	}
	return true;
}

bool TestSubtractInPlace()
{
	TimeSpan ts1(5, 6, 7);
	TimeSpan ts2(1, 1, 1);
	if ((!CheckValues(ts1, 5, 6, 7)) || (!CheckValues(ts2, 1, 1, 1)))
	{
		return false;
	}
	ts1 -= ts2;
	if ((!CheckValues(ts1, 4, 5, 6)) || (!CheckValues(ts2, 1, 1, 1)))
	{
		return false;
	}
	return true;
}

bool TestEquals() 
{
	TimeSpan ts1(3, 4, 6);
	TimeSpan ts2(2, 64, 6);
	if (ts1 == ts2) {
		return true;
	}
	return false;
}

bool TestNotEquals() 
{
	TimeSpan ts1(3, 4, 6);
	TimeSpan ts2(2, 36, 6);
	if (ts1 != ts2) {
		return true;
	}
	return false;
}

bool TestGreaterAndEqual() 
{
	TimeSpan ts1(6, 5, 4);
	TimeSpan ts2(3, 23, 55);
	TimeSpan ts3(2, 83, 55);
	if (ts1 > ts2 && ts2 >= ts3) {
		return true;
	}
	return false;
}

bool TestLessAndEqual() 
{
	TimeSpan ts1(4, 69, 78);
	TimeSpan ts2(5, 23, 55);
	TimeSpan ts3(4, 83, 55);
	if (ts1 < ts2 && ts2 <= ts3) {
		return true;
	}
	return false;
}

void TestInput() {
	TimeSpan ts;
	cout << "Enter your time (Hours, Minutes, Seconds): ";
	cin >> ts;
	cout << "Input passed- " << ts << endl;
}

int main()
{
	cout << "Testing TimeSpan Class" << endl;
	if (!TestZeros()) cout << "Failed: TestZeros" << endl;
	if (TestZeros()) cout << "Passed: TestZeros" << endl;

	if (!TestFloatSeconds()) cout << "Failed: TestFloatSeconds" << endl;
	if (TestFloatSeconds()) cout << "Passed: TestFloatSeconds" << endl;

	if (!TestNegativeMinute()) cout << "Failed: TestNegativeMinute" << endl;
	if (TestNegativeMinute()) cout << "Passed: TestNegativeMinute" << endl;

	if (!TestNegativeHour()) cout << "Failed: TestNegativeHour" << endl;
	if (TestNegativeHour()) cout << "Passed: TestNegativeHour" << endl;

	if (!TestNegativeSeconds()) cout << "Failed: TestNegativeSeconds" << endl;
	if (TestNegativeSeconds()) cout << "Passed: TestNegativeSeconds" << endl;

	if (!TestAdd()) cout << "Failed: TestAdd" << endl;
	if (TestAdd()) cout << "Passed: TestAdd" << endl;

	if (!TestMinus) cout << "Failed: TestMinus" << endl;
	if (TestMinus) cout << "Passed: TestMinus" << endl;

	if (!TestAddInPlace) cout << "Failed: TestAddInPlace" << endl;
	if (TestAddInPlace) cout << "Passed: TestAddInPlace" << endl;

	if (!TestSubtractInPlace) cout << "Failed: TestSubtractInPlace" << endl;
	if (TestSubtractInPlace) cout << "Passed: TestSubtractInPlace" << endl;

	if (!TestEquals) cout << "Failed: TestEquals" << endl;
	if (TestEquals) cout << "Passed: TestEquals" << endl;

	if (!TestNotEquals) cout << "Failed: TestNotEquals" << endl;
	if (TestNotEquals) cout << "Passed: TestNotEquals" << endl;

	if (!TestGreaterAndEqual) cout << "Failed: TestGreaterAndEqual" << endl;
	if (TestGreaterAndEqual) cout << "Passed: TestGreaterAndEqual" << endl;

	if (!TestLessAndEqual) cout << "Failed: TestLessAndEqual" << endl;
	if (TestLessAndEqual) cout << "Passed: TestLessAndEqual" << endl;

	if (!TestNegation) cout << "Failed: TestNegation" << endl;
	if (TestNegation) cout << "Passed: TestNegation" << endl;

	TestInput();
	cout << "Testing Complete" << endl;
}