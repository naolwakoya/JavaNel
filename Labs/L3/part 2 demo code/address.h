#ifndef ADDRESS_H
#define ADDRESS_H

class address {

private:
int street_number;
string street;
string city;
string postal_code;

public:
address();
address(int, string, string, string);
~address();
void printOn(ostream&);
friend ostream & operator<<(ostream & stream, address & a);

};
#endif

