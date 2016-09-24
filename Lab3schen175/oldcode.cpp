if(command == "Last") {
	int valid;
	string input;
	cin >> input;
	/*
	do {
		valid = 1;
		cout << "Last: ";
		cin  >> input;
		
		for(int i=0; i < input.length(); i++) {
			if((input.at(i) <= 'A' && input.at(i) >= 'Z')
				&& (input.at(i) <= 'a' && input.at(i) >= 'z')) {
				cout << "Invalid Last name, only letters allowed" << endl;
				cout << ": " ;
				valid = 0;
				break;
			} 
		}
		
	} while(!valid);
	*/
	Last = input;
	cout << "Last name updated to " << Last << endl;
} else if(command == "First") {
	int valid;
	string input;
	cin >> input;
	/*
	do {
		valid = 1;
		cout << "First: ";
		cin  >> input;
		
		for(int i=0; i < input.length(); i++) {
			if((input.at(i) <= 'A' && input.at(i) >= 'Z')
				&& (input.at(i) <= 'a' && input.at(i) >= 'z')) {
				cout << "Invalid First name, only letters allowed" << endl;
				cout << ": " ;
				valid = 0;
				break;
			} 
		}  
		
	} while(!valid);
	*/
	First = input;
	cout << "First name updated to " << First << endl;
} else if(command == "userid") {
	int valid;
	string input;
	cin >> input;
	/*
	do {
		valid = 1;
		cout << "userid: ";
		cin  >> input;
		
		if(input.length() >= 5 && input.length() <= 10) {
			for(int i=0; i < input.length(); i++) {
				if((input.at(i) <= 'A' && input.at(i) >= 'Z')
					&& (input.at(i) <= 'a' && input.at(i) >= 'z') 
					&& (input.at(i) <= '0' && input.at(i) >= '9')) {	//if the character is not a letter or digit
					cout << "Invalid userid name, only letters and numbers allowed" << endl;
					cout << ": " ;
					valid = 0;
					break;
				} 
			}
		} else {
			valid = 0;
			cout << "Invalid userid name, must contain at least 5 letters and at most 10 letters" << endl;
		}
		
	} while(!valid);
	*/
	userid = input;
	cout << "userid name updated to " << userid << endl;					
} else if(command == "password") {
	int valid;
	string new_pass;
	string curr_pass;
	int digit = 0;
	int specialChar = 0;
	cout << "Type current password: ";
	cin >> curr_pass;
	cout << endl;
	cout << "New Password: " ;
	cin >> new_pass;
	password = new_pass;
	/*
	do {
		valid = 1;
		cout << "Type current password: ";
		cin >> curr_pass;
		
		if(curr_pass != password) {
			valid = 0;
			cout << "Incorrect password. Try again" << endl;
			cout << ": ";
			continue;
		}
		cout << "New Password: " ;
		cin >> input;
		if(input.length() > 6) {
			for(int i=0; i < input.length(); i++) {
				if(input.at(i) >= '0' && input.at(i) <= '9') digit = 1;	//if we have at least 1 digit
				if(input.at(i) <= 'A' && input.at(i) >= 'Z')
					&& (input.at(i) <= 'a' && input.at(i) >= 'z') 
					&& (input.at(i) <= '0' && input.at(i) >= '9') {
						specialChar = 1;	//at least one char not a letter or number
					}
			}
			if(digit && specialChar) {
				valid = 1;
				cout << "Type password again: " << endl;
				cin >> input2;
				if(input1 == input2) {
					password = input1;
					cout << "Password updated" << endl;
					break;
				} else {
					cout << "Password mismatch" << endl;
					continue;
				}
			} else {
				cout << "Invalid password, must contain at least 6 characters" << endl;
				cout << "Must contain at least one digit and one character that is neither a letter nor a digit" << endl;	
			}
		} else {
			cout << "Invalid password, must contain at least 6 characters" << endl;
			cout << "Must contain at least one digit and one character that is neither a letter nor a digit" << endl;
		}
		
	} while(!valid)
	*/
		
} else if(command == "age") {
	int valid;
	int input;
	cout << "age: ";
	cin >> input;
	age = input;
	cout << "age updated to " << age << endl;
	/*
	do {
		valid = 1;
		cout << "age: ";
		cin >> input;
		
		if(cin.fail()) {
			cout << "invalid age. Try again." << endl;
			valid = 0;
		} else if (input < 18) {
			cout << "You are underage. Contact your parents" << endl;
		} else {
			age = input;
			cout << "age updated to " << age << endl;
		}
		
		} while(!valid)
		*/
} else if(command == "strNum") {
	int input;
	cout << "Street Number: " << endl;
	cin >> input;
	strNum = input;

} else if(command == "strName") {
	string input;
	cout << "Street Name: " << endl;
	cin >> input;
	strNum = input;
} else if(command == "zip") {

} else if(command == "donated") {

} else if(command == "finish") {
	finish = 1;
}