#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

#include "Control.h"

Control::Control(){

}

Control::~Control(){

}

void Control::launch(){
    
    string c;
    char y;

    while(1){
        c = " "; 
        ui.mainMenu(c);
        if (c == ".quit"){
            break;
        }
        else{
            ui.readUserInput(c);

        }
        
    }

}