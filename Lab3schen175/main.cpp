//nested loop
	//the first loop is the top level menu
	//if a user logs in, call a function that holds the 2nd loop
		//the particular user/ voter should be passed by reference
		//by finding that voter in the voterDatabase
	//the 2nd loop contains the 2nd level menu
		//if a user types logout, then the function exits
		//and will go back to the first loop
	//if a user types quit in the 1st menu, main() will exit
#include <iostream>
#include "voter.h"
#include "VoterDatabase.h"
#include <vector>

using namespace std;

vector<string> commands = {
	"Login", "New", "Save", "Load", "Report", "Quit"
};

void prompt() {
	cout << "Please make a selection: [\"Login\", \"New\", \"Save\", \"Load\", \"Report\"]" << endl;
	cout << "Or type \"Quit\" to exit" << endl;
}
int retCommand(string s) {
	for(int i=0; i < commands.size(); i++) {
		if(s == commands[i]) return i;
	}
	return -1;
}	

int main(int argc, char* argv[]) {
	//argc is required
	//argv[] is not
	int quit = 0;
	string command;
	//1st level menu
	while(!quit) {
		prompt();
		cin >> command;
		switch(retCommand(command)) {
			case 0: {
				//function that holds pass by reference of the user
				//which has its own loop
				
				break;
			}
			case 1: {
				
				break;
			} 
			case 2 : {
				
				break;
			}
			case 3 : {
				break;
			}
			case 4 : {
				break;
			}
			case 5 : {
				quit = 1;
				break;
			}
			default: {
				break;
			}
		}
	}
	return 0;
}