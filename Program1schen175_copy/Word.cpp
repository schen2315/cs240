#include "Word.h"
#include <iostream>
#include <fstream>


Word::Word(string word) {
cout << "Entering function Word::Word()" << endl;
	//check that word is not empty
	w = word;
	isPig = false;
	prevw = "";
	next = NULL;
cout << "Leaving function Word::Word()" << endl;
};
/*
Word::Word(const Word &rightWord) {
cout << "Entering function Word::Word(const Word &w)" << endl;
//cout << "Parameters: " << w << endl;
	//w = rightWord.w;
	//pigLatin = rightWord.pigLatin;
	//next = rightWord.next;
cout << "Leaving function Word::Word(const Word &w)" << endl;
};	
*/
void Word::show(){
//cout << "Entering function Word::show()" << endl;
	cout << w;
	if(next != NULL) {
		cout << " ";
		next->show();
	}
//cout << "Leaving function Word::show()" << endl;
};
void Word::toUpper() {
cout << "Entering function Word::toUpper()" << endl;
	for(int i=0; i < w.length(); i++) {
		if(w.at(i) >= 97 && w.at(i) <= 122) {
			char newChar = (char)(w.at(i) - 32);
			string upper(1, newChar);
			w = w.substr(0, i) + upper + w.substr(i+1, w.length() - i-1);
		}
	}
cout << "Leaving function Word::toUpper()" << endl;
}
void Word::toLower() {
cout << "Entering function Word::toLower()" << endl;
	for(int i=0; i < w.length(); i++) {
		if(w.at(i) >= 65 && w.at(i) <= 90) {
			char newChar = (char)(w.at(i) + 32);
			string lower(1, newChar);
			w = w.substr(0, i) + lower + w.substr(i+1, w.length() - i-1);
		}
	}
cout << "Leaving function Word::toLower()" << endl;
}
bool Word::empty() const {
// cout << "Entering function Word::empty()" << endl;
	
// cout << "Leaving function Word::empty()" << endl;
	return false;
};
void Word::e2p() {
cout << "Entering function Word::e2p()" << endl;
	bool isVowel = false;
	//if(w.length() > 0) {
		for(int i=0; i < 10; i++) {
			if(vowels[i] == w.at(0)) {
				isVowel = true;
				break;
			}
		}
		if(isVowel == true) {
			w = w + "way";
		} else {
			string consonant(1, w.at(0));
			w = w.substr(1, w.length()-1);
			w = w + consonant + "ay";
		}
	//} else {
	//	cout << "something is off" << endl;
	//}
cout << "Leaving function Word::e2p()" << endl;
}
void Word::save(ofstream& file) {
cout << "Entering function Word::save()" << endl;
	file << w;
	if(next != NULL) {
		file << " ";
		next->save(file);
	}
cout << "Leaving function Word::save()" << endl;	
}
Word::~Word(){
cout << "Entering function Word::~Word()" << endl;
	if(next != NULL) {
		//cout << "true" << endl;
		delete next;
	}
cout << "Leaving function Word::~Word()" << endl;
};
Word& Word::operator=(const Word &rightWord) {	
cout << "Entering function Word::operator=(const Word &rightWord)" << endl;
//cout << "this: " << *this << " Parameter: " << rightWord << endl;
	//cout << rightWord.w << endl;
	//(*this).w = "blah";
	// Word *hw = NULL;
	// if(h != NULL) {
	// 	hw = w;
	// }
	if(this == &rightWord) return (*this);
	if(next != NULL) {
		delete next;
	}
	w = rightWord.w;
	isPig = rightWord.isPig;
	prevw = rightWord.prevw;
	next = NULL;
	if(rightWord.next != NULL) {
		Word* nextWord = new Word("dummy");
		next = nextWord;
		*nextWord = *(rightWord.next);	//sort of a recursive function
	}
	//if(hw != NULL) delete hw;
cout << "Leaving function Word::operator=(const Word &rightWord)" << endl;
	return (*this);
};	//creates a deep copy 	

Word& Word::operator++(int num) {
cout << "Entering function Word::operator++(int num)" << endl;
	//test nesting works
	// w = w + "+";
	toUpper();
	if(next != NULL) (*next)++;
cout << "Leaving function Word::operator++(int num)" << endl;
	return (*this);
};

Word& Word::operator--(int num) {
cout << "Entering function Word::operator--(int num)" << endl;
	// w = w + "-";
	toLower();
	if(next != NULL) (*next)--;
cout << "Leaving function Word::operator--(int num)" << endl;
	return (*this);
};
Word& Word::operator+(int num) {
cout << "Entering function Word::operator+(int num)" << endl;
	if(num == 1) {
		if(w.at(0) >= 97 && w.at(0) <= 122) {
			char newChar = (char)(w.at(0) - 32);
			string upper(1, newChar);
			w = upper + w.substr(1, w.length() - 1);
		}
	}
	//if(next != NULL) (*next) + 1;
cout << "Leaving function Word::operator+(int num)" << endl;
	return (*this);
};	
Word& Word::operator++() {
cout << "Entering function Word::operator++()" << endl;
	// w = "+" + w;
	// if(next != NULL) ++(*next);
	if(isPig == true) {
		//do nothing
	} else {
		isPig = true;
		//if prevw is not ""
			//set a temp to prevw
			//set prevw to w
			//set w to temp
		//store w in prevw
		if(prevw != "") {
			//swap
			string temp = prevw;
			prevw = w;
			w = temp;
		} else {
			prevw = w;
			//convert w to pigLatin
			// w = "++" + w;
			e2p();
		}
	}
	if(next != NULL) ++(*next);
cout << "Leaving function Word::operator++()" << endl;
	return (*this);
};
Word& Word::operator--() {
cout << "Entering function Word::operator--()" << endl;
	// w = "-" + w;
	// if(next != NULL) --(*next);
	//check isPig
	//if false do nothing
	//else if true 
		//convert back to english
		//set isPig to false
	if(isPig == false) {
		//do nothing
	} else {
		isPig = false;
		//convert back to english
		//return prevw
		//swap
		string temp = w;
		w = prevw;
		prevw = temp;
	}
	if(next != NULL) --(*next);
cout << "Leaving function Word::operator--()" << endl;
	return (*this);
};

ostream& operator<<(ostream &out, const Word &word) {
//cout << "Entering function Word::operator<<(ostream &out, const Word &s)" << endl;
	out << word.w;
//cout << "Leaving function Word::operator<<(ostream &out, const Word &s)" << endl;
	return out;		//this is return by reference
};

