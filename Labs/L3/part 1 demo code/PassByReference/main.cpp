#include <iostream>
#include "bankaccount.h"
using namespace std;

void initializeApp(){/*nothing to do*/ }

void runApp(){
   /* run the application */
   cout << "PASS BY REFERENCE EXAMPLE" << "\n";

   BankAccount b("Lou", 1000);  //opening balance $1000

   b.deposit(500).withdraw(700).withdraw(450);

   cout << "\n" << b << "\n"; //OUTPUTS 1500 ---What went wrong?

}

void shutdownApp() {/*nothing to do*/}

int main(void) {

	initializeApp();
	runApp();
	shutdownApp();

    //Force Console window to remain open until user types ENTER
 	const int MAX_SIZE = 80;
	char response[MAX_SIZE];
	//keep console open until user types a key and enter
	cout <<"\n" << "Press ENTER to continue";
	cin.getline(response, MAX_SIZE);

  return 0;
}
