#include "person.h"

using namespace std;


Person::Person(const char * aName, const char * userID, const char * domain, Date aDate) {
//This constructor should create heap objects

	name = new char[strlen(aName) + 1];
    strcpy (name, aName);
	emailAddress = new EmailAddress(userID, domain);
	birthday = new Date(aDate);

	cout << "\nPerson(...) CREATING: ";
	printOn(cout);
}

Person::Person(const Person & p) {
	name = new char[strlen(p.name) + 1];
	strcpy(name, p.name);
	emailAddress = new EmailAddress(*p.emailAddress);
	birthday = p.birthday;
	cout << "\nPerson(...) CREATING: ";
	printOn(cout);
}

Person::~Person() {
   //notice the destructor expects these to be on the heap
	cout << "\n~Person() DELETING: ";
	printOn(cout);

  delete birthday;
	delete emailAddress;
	delete [] name;
}


void Person::printOn(ostream & ostr) const {
  ostr << name << " (" << *birthday << ") " << *emailAddress;
}

ostream & operator<<(ostream & out, const Person & p) {
   p.printOn(out);
   return out;
}
