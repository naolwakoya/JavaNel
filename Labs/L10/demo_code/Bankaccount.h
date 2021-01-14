#include <iostream>
#include <string>

using namespace std;

class BankAccount{
    double balance;
    string owner;

public:
    BankAccount(double anAmount, string anOwner):balance(anAmount), owner(anOwner) {}
	bool operator== (const BankAccount & b) {
        return(this->balance == b.balance && this->owner == b.owner);
    }
	bool operator!= (const BankAccount & b) {
        return(this->balance != b.balance || this->owner != b.owner);
    }
	void printOn(ostream & o) const { o << owner << ": $" << balance << "\n"; }

};
ostream & operator<<(ostream & o, const BankAccount & b){
	b.printOn(o);
	return o;
}