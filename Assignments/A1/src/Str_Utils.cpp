#include <iostream>
#include <fstream>
#include <string>

#include "Str_Utils.h"

using namespace std;

string StrUtils::toUpperCase(string str){
	string s;
	for(char & c : str){
		s.append(1,toupper(c));
	}
	return s;
}

string StrUtils::toTitleCase(string str){
    string s;
    s.append(1, str[0]);
    
    for (int i=1; i<str.length(); i++){
        if (str[i-1] == ' '){
            s.append(1,toupper(str[i]));
            
        }
        else
        {
            s.append(1,tolower(str[i]));
        }
        
    }
    return s;

}

string StrUtils::moveThe(string str){
    str.erase(str.begin() + 0);
    str.erase(str.begin() + 0);
    str.erase(str.begin() + 0);
    str.erase(str.begin() + 0);
    str.erase(str.begin() + 0);
    str.erase(str.begin() + 0);
    str.erase(str.begin() + 0);
    str.erase(str.begin() + 0);
    str.erase(str.begin() + 0);
    str.erase(str.begin() + 0);
    str.erase(str.begin() + 0);
    str.erase(str.begin() + 0);
    str.erase(str.begin() + 0);

    string s = str.substr(0,4);
    if (s.compare("The ") == 0)
    {
        str.erase(0,3);
        return str.append(", " + s);
    }
    return str;
    cout << str << endl;
}

void StrUtils::readHelp(){
    ifstream f("../help.txt");

    if(f.is_open()){
        cout << f.rdbuf();
    }
}

void StrUtils::readFile(string input){
   input.erase(input.begin() + 0);
   input.erase(input.begin() + 0);
   input.erase(input.begin() + 0);
   input.erase(input.begin() + 0);
   input.erase(input.begin() + 0);
   input.erase(input.begin() + 0);

   ifstream f(input);
   if(f.is_open()){
       cout << f.rdbuf() << endl;
   }

}

void StrUtils::logCmd(string in){
    in.erase(in.begin() + 0);
    in.erase(in.begin() + 0);
    in.erase(in.begin() + 0);
    in.erase(in.begin() + 0);
    in.erase(in.begin() + 0);

    fstream ofs;

    if(in == "clear"){
        ofs.open("log.txt", ios::out | ios::trunc);
        ofs.close();
        cout << "Contents cleared..." << endl;
    }
    if(in == "start"){
        cout << "Start typing: " << endl;
    }
    if(in == "start_output"){
        cout << "Logged output..." << endl;
    }
    if(in == "start_both"){
        cout << "Hey" << endl;
    }
    if(in == "stop"){
        cout << "Stopped..." << endl;
    }
    if(in == "save"){
        cout << "Saved..." << endl;
    }
    if(in == "show"){
        ifstream f("log.txt");
        if(f.is_open()){
            cout << f.rdbuf() << endl;
        }

    }

}
