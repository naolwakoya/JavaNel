#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#include "UI.h"
#include "Str_Utils.h"
#include "Parse.h"

void UI::mainMenu(string& choice){
    choice = " ";
    cout << "CMD or .quit: ";

    while(choice == " ") {
        getline(cin, choice);
    }
}

void UI::readUserInput(string& c){
    ifstream file;

    if(c.substr(0,4) == "add " || c.substr(0,7) == "delete " || c.substr(0,5) == "show "){
        removeSpaces(c); 
        Parse::parseInput(c);
    }else if(c == ".help"){
        StrUtils::readHelp();
    }else if(c.substr(0,6) == ".read "){
        StrUtils::readFile(c);
    }else if(c.substr(0,5) == ".log "){
        StrUtils::logCmd(c);
    }else if(c.substr(0,13) == ".toTitleCase "){
        StrUtils::moveThe(c);
    }else if(c.substr(0,6) == ".trim "){
        c.erase(c.begin() + 0);
        c.erase(c.begin() + 0);
        c.erase(c.begin() + 0);
        c.erase(c.begin() + 0);
        c.erase(c.begin() + 0);
        removeSpaces(c);
        cout << c << endl;
    }else if(c.substr(0,12) == ".startsWith "){
        cout << "" << endl;
    }else if(c.substr(0,10) == ".endsWith "){
        cout << "" << endl;
    }else{
        cout << "INVALID INPUT" << endl;
    }
   
}

void UI::removeSpaces(string &str){
    int n = str.length(); 
    int count = 0;
    int count2 = -1; 
  
    bool space = false; 
    while (++count2 < n && str[count2] == ' '); 
    while (count2 < n){
        if (str[count2] != ' ') 
        { 
            if ((str[count2] == '.' || str[count2] == ',' || 
                 str[count2] == '?') && count - 1 >= 0 && 
                 str[count - 1] == ' ') 
                str[count - 1] = str[count2++]; 
  
            else
                str[count++] = str[count2++]; 
            space = false; 
        } 
        else if (str[count2++] == ' ') 
        { 

            if (!space) 
            { 
                str[count++] = ' '; 
                space = true; 
            } 
        } 
    } 
    if (count <= 1){
        str.erase(str.begin() + count, str.end());

    }else{
        str.erase(str.begin() + count - 1, str.end()); 
    }
} 
