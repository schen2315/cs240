#ifndef VOTER_H
#define VOTER_H
#include <string>
#include <vector>

using namespace std;
enum State { PA, NY, ME, NH, VT, MA, RI, CT, NJ, DE, MD };

class Voter {
public:
	Voter(string L, string F, string usr, 
		string pass, int a, int n, string str, string t, State state,
		string z, float d);
	~Voter();
	void Update();
	void Passwd();
	void View();
	void Donate();
	void Report();
private:
	string Last;
	string First;
	string userid;
	string password;
	int age;
	int strNum;
	string strname;
	string town;
	string zip;
	State state;
	float donated;

	int _isValid(string L, string F, string u, string p, int a, int snum, 
		string sname, string t, State state, string z, float d);

	vector<string> commands = {"last", "first", "userid", "password", "age", "strnum", 
						"strname", "town", "state", "zip", "finish"
						};
	void _prompt();
	int _retCommand(string s);
};

#endif