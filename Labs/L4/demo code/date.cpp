#include "date.h"

using namespace std;

Date::Date(int aDay, int aMonth, int aYear) : day(aDay), month(aMonth), year(aYear) {}
Date::Date(const Date & aDate) :  day(aDate.day), month(aDate.month), year(aDate.year) {};
void Date::printOn(ostream & out) const {out << day <<"/" << month << "/" << year;}

ostream & operator<<(ostream & ostr, const Date & d) {
	  d.printOn(ostr);
	  return ostr;
}
