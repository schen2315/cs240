#include "Story.h"
//#include "Paragraph.h"
#include <iostream>
#include <fstream>
// #include <vector>

using namespace std;
Story::Story() {
cout << "Entering function Story::Story()" << endl;
	p = NULL;
cout << "Leaving function Story::Story()" << endl;	
}
Story::Story(string file) {
cout << "Entering function Story::Story(string file)" << endl;
	//rewrite this
	p = NULL;	
	// Word w1("dummy");
	// Word w2("ymmud");
	// Paragraph *temp = new Paragraph();
	// //Paragraph *temp2;
	// //temp2 = temp;
	// *temp = (w1 + w2) + (w2 + w1);
	// p = temp;
	//delete temp2;

	//create a istream from the file
	//this should be creating several paragraphs
	//cin words until a new line is reached
	//pass the substring into a Paragraph value constructor
	//set (*this) to the sum of an empty story and the paragraphs
	ifstream input;
	string storyi;
	// vector<string> paragraphs;
	input.open(file);
	Story s;
	while(getline(input, storyi)) {
		//cout << storyi << endl;
		//paragraphs.push_back(storyi);
		Paragraph pi(storyi);
		s = s + pi;
	}
	// for(unsigned int i=0; i < paragraphs.size(); i++) {
	// 	Paragraph pi(paragraphs[i]);
	// 	s = s + pi;
	// }
	(*this) = s;
cout << "Leaving function Story::Story(string file)" << endl;	
}
void Story::show() const {
cout << "Entering function Story::show()" << endl;
	if(p != NULL) {
		p->show();
	}
cout << "Leaving function Story::show()" << endl;	
};
void Story::save(string file) {
cout << "Entering function Story::save(string file)" << endl;
	ofstream out;
	out.open(file);
	p->save(out);
	out.close();	
cout << "Leaving function Story::save(string file)" << endl;		
};
bool Story::empty() const {
cout << "Entering function Story::empty()" << endl;

cout << "Leaving function Story::empty()" << endl;	
	return true;
};
// int Story::sizeOf() const {
// cout << "Entering function Story::sizeOf()" << endl;

// cout << "Leaving function Story::sizeOf()" << endl;	
// 	return 0;
// };
Story::~Story() {
cout << "Entering function Story::~Story()" << endl;
	if(p != NULL) delete p;
cout << "Leaving function Story::~Story()" << endl;	
}
Story &Story::operator=(const Story &rightStory) {
cout << "Entering function Story::operator=(const Story &rightStory)" << endl;
	//Paragraph *hp = NULL;
	// if(p != NULL) {
	// 	hp = p;
	// }
	if(this == &rightStory) return (*this);
	if(p != NULL) delete p;
	if(rightStory.p != NULL) {
		Paragraph *nP = new Paragraph();
		p = nP;
		*nP = *(rightStory.p);
	}
	//if(hp != NULL) delete hp;
cout << "Leaving function Story::show()" << endl;	
	return (*this);
};
// Story Story::operator+(const Story &rightStory) const {
// 	cout << "Entering function Story::operator+(const Story &rightStory)" << endl;
// 	cout << "Parameters: " << rightStory << endl;

// 	Story s;
// 	cout << "Leaving function Story::operator+(const Story &rightStory)" << endl;
// 	return s;
// };
// Story Story::operator+(const Paragraph &para) const {
// 	cout << "Entering function Story::operator+(const Paragraph &para)" << endl;
// 	cout << "Parameters: " << para << endl;

// 	Story s;
// 	cout << "Leaving function Story::operator+(const Paragraph &para)" << endl;
// 	return s;
// };
//postfix
Story &Story::operator++(int num) {
cout << "Entering function Story::operator++(int num)" << endl;
	if(p != NULL) (*p)++;
cout << "Leaving function Story::operator++(int num)" << endl;	
	return (*this);
};
Story &Story::operator--(int num) {
cout << "Entering function Story::operator--(int num)" << endl;
	if(p != NULL) (*p)--;	
cout << "Leaving function Story::operator--(int num)" << endl;	
	return (*this);
};
Story &Story::operator+(int num) {
cout << "Entering function Story::operator+(int num)" << endl;
	if(num == 1) {
		if(p != NULL) (*p)+1;
	}
cout << "Leaving function Story::operator+(int num)" << endl;	
	return (*this);
};
//prefix
Story &Story::operator++() {
cout << "Entering function Story::operator++()" << endl;
	if(p != NULL) ++(*p);
cout << "Leaving function Story::operator++()" << endl;	
	return (*this);
};
Story &Story::operator--() {
cout << "Entering function Story::operator--()" << endl;
	if(p != NULL) --(*p);
cout << "Leaving function Story::operator--()" << endl;	
	return (*this);
};



Paragraph Story::first() const {
cout << "Entering function Story::first()" << endl;

cout << "Leaving function Story::first()" << endl;
	return firstHelper(*this);
};
Story Story::rest() const {
cout << "Entering function Story::rest()" << endl;
cout << "Leaving function Story::rest()" << endl;
	return restHelper(*this);
};


ostream& operator<<(ostream &out, const Story &s) {
cout << "Entering function operator<<(ostream &out, const Story &s)" << endl;
	s.show();
cout << "Leaving function Story::out()" << endl;
	return out;
};


Story operator+(const Story &leftStory, const Paragraph &rightParagraph) {
cout << "Entering function operator+(const Story &leftStory, const Paragraph &rightParagraph)" << endl;
	Story copy;
	copy = leftStory; 	//deep copy

	Paragraph* rightCopy = new Paragraph();		//do we wanna check if rightParagraph is null
	*rightCopy = rightParagraph;	//deep copy of Paragraph
	Paragraph *temp;
	temp = copy.p;
	if(temp != NULL) {
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = rightCopy;
	} else {
		copy.p = rightCopy;
	}
	//run through each paragraph
cout << "Leaving function operator+(const Story &leftStory, const Paragraph &rightParagraph)" << endl;
	return copy;
};
Story operator+(const Paragraph &leftParagraph, const Story &rightStory) {
cout << "Entering function operator+(const Paragraph &leftParagraph, const Story &rightStory)" << endl;
	Story copy;
	copy = rightStory;
	Paragraph* leftCopy = new Paragraph();
	*leftCopy = leftParagraph;
	leftCopy->next = copy.p;
	copy.p = leftCopy;
cout << "Leaving function operator+(const Paragraph &leftParagraph, const Story &rightStory)" << endl;
	return copy;
};
Story operator+(const Story &leftStory, const Story &rightStory) {
cout << "Entering function operator+(const Story &leftStory, const Story &rightStory)" << endl;
	Story leftCopy;
	leftCopy = leftStory;
	Paragraph *rightCopy = NULL;
	
	if(rightStory.p != NULL) {
		Paragraph* nP = new Paragraph();
		rightCopy = nP;
		*rightCopy = *(rightStory.p);		//deep copy should be made
	}
	Paragraph* temp = leftCopy.p;
	if(temp != NULL) {
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = rightCopy;
	} else {
		leftCopy.p = rightCopy;
	}
	
cout << "Leaving function operator+(const Story &leftStory, const Story &rightStory)" << endl;
	return leftCopy;
};
Paragraph firstHelper(const Story& st) {
	Paragraph copy("This is some dummy paragraph. I need more sentences. Because this is a Paragraph");
	if(st.p != NULL) {
		copy = *(st.p);
	}
	Paragraph *temp = copy.next;
	copy.next = NULL;
	delete temp;
	return copy;
};
Story restHelper(const Story& st) {
	Story copy;
	copy = st;
	Paragraph *first = copy.p;
	copy.p = (copy.p)->next;
	first->next = NULL;
	delete first;
	return copy;
};


