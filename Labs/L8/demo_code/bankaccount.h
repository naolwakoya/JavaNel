#include <string> 
  

class BankAccount { 
//    =========== 

static int nextAccountNumber; 
int accountNumber; 
float balance_; 

public: 
 BankAccount(float amount = 0.0): 
   accountNumber(nextAccountNumber++),balance_(amount) {} 

 void printOn(ostream & out) const { 
  out << "acct#" <<accountNumber << "  $" << balance_; 
 } 

 void deposit(float amount) {balance_ += amount;} 

 void withdraw(float amount) {balance_ -= amount;} 

 float balance() const {return balance_;} 
}; 

ostream & operator<< (ostream & out, const BankAccount & b) { 
 b.printOn(out); 
 return out; 
} 

int BankAccount::nextAccountNumber = 1000; 

