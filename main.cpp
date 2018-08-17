#include <iostream>
#include <string>
#include "NFA.h"
#include "ExpTree.h"
#include <gtest/gtest.h>
#include <fstream>

using namespace std;

int main(int argc,char* argv[])
{
	string filename = argv[1];
	//string filename = "7 1 3 10 q0 q1 q2 q3 q4 q5 q6 q0 q4 a b c q0 a q1 q1 a q0 q0 b q2 q2 b q0 q0 c q3 q3 c q4 q4 a q5 q5 a q4 q4 b q6 q6 b q4";

	fstream file;

	file.open(filename);

	string str = "",inputStr;


	while(getline(file, inputStr)){
        str += inputStr;
    }
    file.close();


	NFA nfa(str);

	cout << nfa.ParikhImage() << endl;

	return 0;
}