#include "emailaddress.h"

using namespace std;

EmailAddress::EmailAddress( const char * aUserID, const char * aDomain) {
		userID = new char[strlen(aUserID) + 1];
		strcpy (userID, aUserID);
		domain = new char[strlen(aDomain) + 1];
		strcpy (domain, aDomain);
}
EmailAddress::EmailAddress( const EmailAddress & anEmailAddress) {

//code not shown
		userID = new char[strlen(anEmailAddress.userID) + 1];
		strcpy (userID, anEmailAddress.userID);
		domain = new char[strlen(anEmailAddress.domain) + 1];
		strcpy (domain, anEmailAddress.domain);
}
EmailAddress & EmailAddress::operator=(const EmailAddress & anEmailAddress) {

//code not shown

       if(&anEmailAddress != this) {
		   delete [] userID;
		   delete [] domain;
		   userID = new char[strlen(anEmailAddress.userID) + 1];
		   strcpy (userID, anEmailAddress.userID);
		   domain = new char[strlen(anEmailAddress.domain) + 1];
		   strcpy (domain, anEmailAddress.domain);

		}
		return *this;
	}
EmailAddress::~EmailAddress(){
         delete [] userID;
         delete [] domain;
}
void EmailAddress::printOn(ostream & ostr) const {ostr << userID << "@" << domain;}


ostream & operator<<(ostream & ostr, const EmailAddress & anEmailAddress) {
	anEmailAddress.printOn(ostr);  return ostr;
}
