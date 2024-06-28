// Justin Singsanavong
#include <iostream>
#include "list342.h"
#include "child.h"
using namespace std;

int main()
{
	cout << "----------PROVIDED CHILDRENS CLASS DRIVER----------" << endl;
	Child c1("Angie", "Ham", 7), c2("Pradnya", "Dhala", 8),
		c3("Bill", "Vollmann", 13), c4("Cesar", "Ruiz", 6);
	Child c5("Piqi", "Tangi", 7), c6("Russell", "Wilson", 13),
		c7("Hank", "Aaron", 3), c8("Madison", "Fife", 7);
	Child c9("Miles", "Davis", 65), c10("John", "Zorn", 4), c11;

	
	List342<Child> class1, class2, soccer, chess, test, players1, players2;
	int a = 1, b = -1, c = 13;

	class1.Insert(&c1);
	class1.Insert(&c2);
	class1.Insert(&c3);
	class1.Insert(&c4);
	class1.Insert(&c5);
	class1.Insert(&c6);
	class1.Insert(&c5);
	cout << "class1: " << class1 << endl;

	if (!class1.Insert(&c1))
	{
		cout << "ERROR::: Duplicate" << endl;
	}

	class2.Insert(&c4);
	class2.Insert(&c5);
	class2.Insert(&c6);
	class2.Insert(&c7);
	class2.Insert(&c10);
	cout << "Class2: " << class2 << endl;
	
	class1.Merge(class2);
	class2.Merge(class1);
	class1.Merge(class2);
	class1.Merge(class1);
	cout << "class1 and 2 Merged: " << class1 << endl;

	class1.Remove(c4, c11);
	class1.Remove(c5, c11);
	class1.Remove(c11, c11);
	if (class1.Remove(c1, c11))
	{
		cout << "Removed from class1, student " << c11 << endl;
	}
	cout << "class1: " << class1 << endl;

	soccer.Insert(&c6);
	soccer.Insert(&c4);
	soccer.Insert(&c9);
	cout << "soccer: " << soccer << endl;
	soccer += class1;
	cout << "soccer += class1 : " << soccer << endl;

	List342<Child> football = soccer;
	if (football == soccer)
	{
		cout << "football: " << football << endl;
	}
	if (football.Peek(c6, c11))
	{
		cout << c11 << " is on the football team" << endl;
	}
	soccer.DeleteList();

	List342<int> numbers;
	numbers.Insert(&a);
	numbers.Insert(&b);
	numbers.Insert(&c);
	cout << "These are the numbers: " << numbers << endl;
	numbers.DeleteList();

	cout << endl;
	cout << "----------JUSTIN'S PERSONAL TEST CASES----------" << endl;
	Child b1("Lebron", "James", 23), b2("Kobe", "Bryant", 8), b3("James", "Harden", 13), 
		b4("Damian", "Lillard", 0), b5("Anthony", "Edwards", 5);
	Child  b6("Michael", "Jordan", 23), b7("Shaquille", "O'Neal", 34), b8("Victor", "Wembanyama", 1), 
		b9("Jeremy", "Lin", 7), b10("Carmelo", "Anthony", 7), b11, b12;

	cout << "BuildList test:" << endl;
	string file_name;
	cout << "Please enter file path: ";
	cin >> file_name;

	if (test.BuildList(file_name)) {
		cout << "File accessed!" << endl;
		cout << "Content inside: " << test << endl;
		test.Insert(&b1);
		test.Insert(&b7);
		test.Insert(&b3);
		cout << "New names added to file content: " << test << endl;
	}
	else {
		cout << "New names test not added to invalid file." << endl;
	}
	

	players1.Insert(&b1);
	players1.Insert(&b2);
	players1.Insert(&b3);
	players1.Insert(&b4);
	players1.Insert(&b5);
	cout << "List of team 1: " << players1 << endl;

	players2.Insert(&b6);
	players2.Insert(&b7);
	players2.Insert(&b8);
	players2.Insert(&b9);
	players2.Insert(&b10);
	cout << "List of team 2: " << players2 << endl;

	cout << "List of team 1 and team 2 added together: " << players1 + players2 << endl;
	cout << "There is " << players1.Size() + players2.Size() << " players on the court!" << endl;

	if (players1.Remove(b1, b11))
	{
		cout << "Removed from team 1, player " << b11 << endl;
	}

	cout << "Now there is " << players1.Size() + players2.Size() << " players on the court!" << endl;

	if (players2.Peek(b6, b12))
	{
		cout << b12 << " is on the basketball team" << endl;
	}
}
