#include <iostream>
#include "LastFirstVoterFunctions.h"

using namespace std;

int main() {
	string last = "";
	string first = ""; 
	int age = 0; 
	int strnum = 0; 
	string strname = "";
	string town = ""; 
	string zip = ""; 
	float donated = 0.00;
	string command;
	cout << endl;
	while(true) {
		cout << "Enter a command." << endl;
		cout << "Choose from [\"New\" \"View\" \"Update\" \"Donate\" \"Report\" \"Quit\"]" << endl;
		cout << ": ";
		cin >> command;
		if(command == "New") {
			New(last, first, age, strnum, strname, town, zip, donated);
		} else if(command == "View") {
			View(last, first, age, strnum, strname, town, zip, donated);
		} else if(command == "Update") {
			Update(last, first, age, strnum, strname, town, zip);
		} else if(command == "Donate") {
			Donate(donated);
		} else if(command == "Report") {
			Report(last, donated);
		} else if(command == "Quit") {
			break;
		} else {
			cout << "Command not recognized. Please try again." << endl;
		}
	}
	return 0;
}






