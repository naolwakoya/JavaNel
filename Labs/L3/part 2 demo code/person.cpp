#include <iostream>
#include <string>
using namespace std;

#include "person.h"
#include "address.h"

//constructor
person::person(string aName, string anEmailAddress, string aPhoneNumber, address anAddress){
        name = aName;
        email_address = anEmailAddress;
        phone_number = aPhoneNumber;
        home_address = anAddress;

        cout << "\nCONSTRUCT person: @" << this << "\n";
}
//destructor
person::~person(){
        cout << "\nDESTRUCT person: @" << this << "\n";
}

void person::printOn(ostream & out){
        out << name << "  email:" << email_address << "  phone:" << phone_number << " address:" << home_address;
}

ostream & operator<<(ostream & stream, person & p){
        p.printOn(stream);
        return stream;
}