#ifndef _emailaddress_h
#define _emailaddress_h

#include <iostream>
#include <cstring>
using namespace std;

class EmailAddress{
//To represent someone's email address as a userid and domain
public:
EmailAddress( const char * aUserID, const char * aDomain);
EmailAddress( const EmailAddress & anEmailAddress);
EmailAddress & operator=(const EmailAddress & anEmailAddress);
~EmailAddress();
void printOn(ostream & ostr) const;

private:
	char * userID; //points to character array on the heap
	char * domain; //point to character array on the heap
};

ostream & operator<<(ostream & ostr, const EmailAddress & anEmailAddress);

#endif
