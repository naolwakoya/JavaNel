#include <iostream>
#include <fstream>
#include <string>

#include "Str_Utils.h"

using namespace std;

string toTitleCase(string str){
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

string moveThe(string str){
    
    std::string s = str.substr(0,4);
    if (s.compare("The ") == 0)
    {
        str.erase(0,3);
        return str.append(", " + s);
    }
    return str;
}



int main(){

    string input; 

    string file12;
    cout << "Enter the filename: ";
    cin >> file12;


    string filename;
    cout << "Enter an output filename: ";
    cin >> filename;

    ifstream file1(file12, ifstream::in);
    ofstream file2(filename, ofstream::out);

    if (!file1)
    {
        cout << "ERROR: could not open file " << file12 << "  ...exiting\n";
		return 0;
    }
    else{
        cout << "Now check " << filename << "\n";
        
    }
    
    while(true){
		getline(file1, input); 
		if(input.compare("quit") == 0) break;
		else file2 << moveThe(toTitleCase(StrUtils::toUpperCase(input))) << endl;

	}

    file1.close();
    file2.close(); 
  
	return 0;
}