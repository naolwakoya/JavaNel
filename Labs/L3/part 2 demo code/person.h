#ifndef PERSON_H
#define PERSON_H
#include "address.h"

class person {

private:
string name;
string email_address;
string phone_number;
address home_address;

public:
person(string, string, string, address);
~person();
void printOn(ostream&);
friend ostream & operator<<(ostream & stream, person & p);

};
#endif

