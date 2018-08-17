#include <iostream>
#include <string>
#include "NFA.h"
#include "ExpTree.h"
#include <fstream>

using namespace std;

int main(int argc,char* argv[])
{
    string filename = argv[1];
    
    fstream file;

    file.open(filename);

    string str = "",inputStr;

    while(getline(file, inputStr))
    {
        str += inputStr;
        str += "\n";
    }
    file.close();
    //cout << str;


    NFA nfa(str);

    cout << nfa.ParikhImage() << endl;

    return 0;
}