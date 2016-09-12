#include <iostream>
#include "LastFirstVoterFunctions.h"

using namespace std;
void New(string &last, string &first, int &age, int &strnum, string &strname,
	string &town, string &zip, float &donated){
	cout << "Last Name: ";
	cin >> last;
	cout << "First Name: ";
	cin >> first;
	cout << "Age: ";
	cin >> age;
	cout << "Street Name: ";
	cin >> strname;
	cout << "House Number: ";
	cin >> strnum;
	cout << "Town: ";
	cin >> town;
	cout << "Zip Code: " << endl; 
	cin >> zip;
	donated = 0;
};

void Update(string &last, string &first, int &age, int &strnum, string &strname,
	string &town, string &zip){
	cout << "Last Name: ";
	cin >> last;
	cout << "First Name: ";
	cin >> first;
	cout << "Age:";
	cin >> age;
	cout << "Street Name: ";
	cin >> strname;
	cout << "House Number: ";
	cin >> strnum;
	cout << "Town: ";
	cin >> town;
	cout << "Zip Code: " << endl; 
	cin >> zip;
};

void View(string &last, string &first, int &age, int &strnum, string &strname,
	string &town, string &zip, float &donated){
	cout << "Voter Info" << endl;
	cout << last << " " << first << ": age " << age << endl;
	cout << strnum << " " << strname << endl;
	cout << town << ", NY " << zip << endl;
	cout << "Current Amount Donated: $" << donated << endl << endl;
};

void Donate(float &donated){
	float toAdd;
	cout << endl << "Enter Amount to Donate: " ;
	cin >> toAdd;
	donated += toAdd;
	cout << "$" << toAdd << " donated." << endl << endl;
};

void Report(string &last, float &donated){
	cout << last << " $" << donated << endl << endl;
};
