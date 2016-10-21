#ifndef WORD_H
#define WORD_H

//forward declaration
class Word;


#include <iostream>
#include "Sentence.h"
#include <fstream>

using namespace std;

class Word {
public:
	Word(string w);
	//Word(const Word &s);	
	void show();

	bool empty() const;		//probably does not apply to word
	bool isPigLatin() const;
	void save(ofstream& file);
	void e2p();
	void toUpper();
	void toLower();
	~Word();


	Word &operator=(const Word &rightWord);	//creates a deep copy	
	Word &operator++(int num);
	Word &operator--(int num);
	Word &operator+(int num);
	Word &operator++();
	Word &operator--();



	friend ostream& operator<<(ostream &out, const Word &s);
	friend Sentence operator+(const Word &leftWord, const Word &rightWord);
	friend Sentence operator+(const Sentence &leftSentence, const Word &rightWord);
	friend Sentence operator+(const Word& leftWord, const Sentence& rightSentence);

	friend Word firstHelper(const Sentence& s);
	friend Sentence restHelper(const Sentence& s);
private:	
	Word* next; 
	string w;
	bool isPig;
	string prevw;

	const char vowels[10] = {'a','o','i','e','u', 'A', 'O', 'I', 'E', 'U'};
};

#endif

//October 8
	//constructor
	//copy constructor	?? should be left empty -> gets called when function returns
	//only operator=
	//don't do pigLatin and convert yet