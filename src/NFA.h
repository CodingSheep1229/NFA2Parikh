#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include "ExpTree.h"

#ifndef NFA_H
#define NFA_H

using namespace std;

struct transition
{
	string p;
	string a;
	string q;
};

class NFA
{
public:
	NFA(){}
	NFA(string filename);
	string ParikhImage();

private:
	vector<string> Q;
	vector<string> sigma;
	string q0;
	vector<string> T;
	vector<transition> transitions;
};



#endif
