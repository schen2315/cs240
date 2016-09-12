#include <iostream>
#include "LastFirstVoterFunctions.h"

using namespace std;
void New(string &last, string &first, int &age, int &strnum, string &strname,
	string &town, string &zip, float &donated){
	donated = 0;
	cout << "Last Name:" << endl;
	cout << "First Name" << endl;
	cout << "Age:" << endl;
	cout << "Street Name:" << endl;
	cout << "Street Number:" << endl;
	cout << "Town:" << endl;
	cin >> last >> first >> age >> strname >> strnum >> town >> zip;
	donated = 0;
};

void Update(string &last, string &first, int &age, int &strnum, string &strname,
	string &town, string &zip, float &donated){
	cout << "Last Name:" << endl;
	cout << "First Name" << endl;
	cout << "Age:" << endl;
	cout << "Street Name:" << endl;
	cout << "Street Number:" << endl;
	cout << "Town:" << endl;
	cin >> last >> first >> age >> strname >> strnum >> town >> zip;
};

void View(string &last, string &first, int &age, int &strnum, string &strname,
	string &town, string &zip, float &donated){

};

void Donate(float &donated){

};

void Report(string &last, float &donated){

};
