#include <iostream>

#include "Bankaccount.h"
#include "OrderedCollection.h"

using namespace std;

//Example of how the collection and iterator could be used
int main() {
BankAccount b1(100.0, "Lou"), b2(50.0, "Madison"), b3(200.0, "Billy"), b4(150.0, "Rick");
OrderedCollection<BankAccount> accounts;
accounts.addLast(b1).addLast(b2).addLast(b3).addLast(b4).addLast(b2);

for(OrderedCollection<BankAccount>::iterator itr = accounts.begin();
			    itr != accounts.end(); itr++)

	 cout << *itr;
accounts.print();
accounts.remove(b2);
accounts.print();
return 0;
}//end main
