#include <iostream>
#include <string>

using namespace std;

class BankAccount{
public:

BankAccount (string customer, float opening_balance = 0.0) {
   owner = customer;
   balance = opening_balance;
   cout << "\n" << "CONSTRUCT: BankAccount @" << this;
}
BankAccount (BankAccount & b) {  //copy constructor
   owner = b.owner;
   balance = b.balance;
   cout << "\n" << "COPY CONSTRUCT: BankAccount @" << this;
}

~BankAccount(){
  cout << "\n" << "DESTRUCT: BankAccount @" << *this << " balance: $" << balance;
}  

float getBalance() {return balance; }
void printOn(ostream & outstream){
	outstream << "\n" << "BankAccount: " << owner << " $" << balance;
}

BankAccount deposit(float amount) {
   balance += amount; return *this;}

BankAccount withdraw(float amount) {
   balance -= amount; return *this;}

private:
   string owner;
   float balance;
};

ostream & operator<<(ostream & outstream, BankAccount & aBankAccount){
	aBankAccount.printOn(outstream);
	return outstream;
}
