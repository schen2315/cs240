#include "Voter.h"
class VoterDatabase {
public:
	VoterDatabase();
	~VoterDatabase();
	Voter Login();
	void New();	//do type checking 
				//create a new Voter object
				//then pass the new voter to _add func
				//to save the voter to the database
	void Save();
	void Load();
	void Report();
private:
	void _add(Voter v);
	Voter* database[];
};