#ifndef _date_h
#define _date_h

#include <iostream>
#include <cstring>
using namespace std;

class Date{ //this class is complete
//This class represents a date

public:
	  Date(int aDay, int aMonth, int aYear);
	  Date(const Date & aDate);
	  void printOn(ostream & out) const;
private:
	  int day, month, year;
};

ostream & operator<<(ostream & ostr, const Date & d);

#endif
