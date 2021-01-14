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