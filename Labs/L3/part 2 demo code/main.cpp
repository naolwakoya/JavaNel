#include <iostream>
using namespace std;

#include "address.h"
#include "person.h"

void runApp(){
//create some address and person objects
        address lou_address(1125, "Colonel By Drive", "Ottawa", "K1S 5B6");
        person lou("Lou", "ldnel@carleton.ca", "613 520-2600", lou_address); //creates a person object on the stack
        address sue_address(24, "Sussex Drive", "Ottawa", "K1A 2B2");

        person sue("Sue", "sue@gmail.com", "555-1234", sue_address);

        address john_address(104, "Yonge St", "Toronto", "M2A 2Y2");
        person  * john;//create a pointer to a person
        john = new person("John", "john@cmail.ca", "416 555-2235", john_address); //creates a person object on the heap

//use the person objects
        cout << "\n";
        cout << lou << "\n" << sue << "\n" << *john;
        cout << "\n";

//remove any heap-based person objects
        delete john;

}
int main(void){

        const int MAX_SIZE = 80;
        char response[MAX_SIZE];

        cout << "Hello World";

        runApp();

//keep console open until user types a key and enter
        cout <<"\n\n" << "Press ENTER to continue";
        cin.getline(response, MAX_SIZE);
        return 0;

}
