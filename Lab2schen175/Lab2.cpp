#include <iostream>
#include "LastFirstVoterFunctions.h"

using namespace std;

int main() {
	string last;
	string first; 
	int age; 
	int strnum; 
	string strname;
	string town; 
	string zip; 
	float donated;
	string command;
	while(true) {
		cout << "Enter a command." << endl;
		cout << "Choose from [New View Update Deposit Report Quit]" << endl;
		cin >> command;
		if(command == "New") {
			New(last, first, age, strnum, strname, town, zip, donated);
		} else if(command == "View") {
			View(last, first, age, strnum, strname, town, zip, donated);
		} else if(command == "Update") {
			Update(last, first, age, strnum, strname, town, zip, donated);
		} else if(command == "Deposit") {
			Donate(donated);
		} else if(command == "Report") {
			Report(last, donated);
		} else if(command == "quit") {
			break;
		}
	}
	return 0;
}






