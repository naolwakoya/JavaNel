#ifndef _person_h
#define _person_h

#include <iostream>
#include <cstring>
#include "date.h"
#include "emailaddress.h"


using namespace std;

class Person
{
public:
Person(const char * aName, const char * userID, const char * domain, Date aDate) ;
Person(const Person & p);
~Person();

void printOn(ostream & ostr) const;

private:
   char * name; //pointer to a person's name
   EmailAddress * emailAddress; //pointer to a person's email address
   Date * birthday; //pointer to persons birthday

}; //end class Person

ostream & operator<<(ostream & out, const Person & p);

#endif
