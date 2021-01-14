#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#include "Parse.h"

void Parse::parseInput(string c){
    string ch = "";
    cout << "PARSED COMMAND: " << endl;
    string input = c;
    for(auto x : c){
        if(x == ' '){
            c.erase(remove(c.begin(), c.end(), '\"'), c.end());
            cout << ch << endl;
            ch = "";
        }else{
            ch = ch + x;
        }
    }
    cout << ch << endl;
    cout << "EXECUTING: " << input << endl;
}