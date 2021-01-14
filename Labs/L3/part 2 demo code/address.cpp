#include <iostream>
#include <string>
using namespace std;

#include "address.h"

address::address(){
        street_number = 0;
        street = "unknown";
        city = "unknown";
        postal_code = "unknown";
        cout << "\nCONSTRUCT address: @" << this << "\n";
}

address::address(int aStreetNumber, string aStreet, string aCity, string aPostalCode){
        street_number = aStreetNumber;
        street = aStreet;
        city = aCity;
        postal_code = aPostalCode;
        cout << "\nCONSTRUCT address: @" << this << "\n";
}

address::~address(){
    cout << "\nDESTRUCT address: @" << this << "\n";
}

void address::printOn(ostream & out){
        out << street_number << " " << street << ", " << city << ", " << postal_code;
}

ostream & operator<<(ostream & stream, address & a){
        a.printOn(stream);
        return stream;
}
