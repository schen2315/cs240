#include "Voter.h"
#include <iostream>
using namespace std;


Voter::Voter(string L, string F, string usr, 
		string pass, int a, int n, string str, string t, State state,
		string z, float d) {
	Last = L;
	First = F;
	userid = usr;
	password = pass;
	age = a;
	strNum = n;
	strname = str;
	town = t;
	zip = z;
	donated = d;
}
void Voter::_prompt() {
	cout << "Please choose a field to update: ";
	for(int i=0; i< commands.size(); i++) {
		cout << "\"" << commands[i] << "\",";
	}
	
	cout << endl;
	cout << "Or enter \"finish\" to finish updating" << endl;
	cout << ": ";
}
int Voter::_retCommand(string s) {
	for(int i=0; i< commands.size(); i++) {
		if(commands[i] == s) return i;
	}
	return -1;
}
//destructor goes here
void Voter::Update() {
	int finish = 0;
	string command;
	while(!finish) {
		_prompt();
		cin >> command;
		cout << endl;
		//do type checking
		switch(_retCommand(command)) {
			case 0 : {
				string input;
				cin >> input;
				Last = input;
				cout << "Last name updated to " << Last << endl;
			}
			case 1 : {
				string input;
				cin >> input;
				First = input;
				cout << "First name updated to " << First << endl;
			}
			case 2 : {
				string input;
				cin >> input;
				userid = input;
				cout << "userid name updated to " << userid << endl;
			}
			case 3 : {
				string new_pass;
				string curr_pass;
				cout << "Type current password: ";
				cin >> curr_pass;
				cout << endl;
				cout << "New Password: " ;
				cin >> new_pass;
				password = new_pass;
			}
			case 4 : {
				int input;
				cout << "age: ";
				cin >> input;
				age = input;
				cout << "age updated to " << age << endl;
			}
			case 5 : {
				int input;
				cout << "Street Number: " << endl;
				cin >> input;
				strNum = input;
				cout << "Street Number updated to" << strNum << endl;
			}
			case 6 : {
				string input;
				cout << "Street Name: " << endl;
				cin >> input;
				strname = input;
				cout << "Street Name updated to " << strname << endl;
			}
			case 7 : {
				string input;
				cout << "Town: " << endl;
				cin >> input;
				town = input;
				cout << "Town updated to " << town << endl;
			}
			case 8 : {

			}
			case 9 : {
				string input;
				cout << "Zip: " << endl;
				cin >> input;
				zip = input;
				cout << "Zip Code updated to " << zip << endl; 
			}
			case 10: {
				finish = 1;
			}
			default : {
				cout << "Error. Your imput did not match a command" << endl;
			}
		}
	}
}
/*
int _isValid(string L, string F, string u, string p, int a, int snum, 
		string sname, string t, string z, float d) {

};
*/


