/*
 Sample code last compiled with
 g++ -g -Wall -std=c++11 main.cpp
*/

#include <iostream>
#include <fstream> 
#include <string> 

using namespace std;

string dataFileName = "stockdata.txt"; //file to read stock quotes from

ofstream file ("simulationResults.txt"); //file to write simulation output to 

#include "arraylist.h" 
#include "bankaccount.h" 
#include "observer.h" 
#include "subject.h"
#include "stock.h" 
#include "portfolio.h" 
#include "action.h" 
  
  

int main() { 
  
 
   BankAccount account; 
   Portfolio portfolio("Lou", account); 

   account.deposit(10000.00); //opening balance 
  
   //create stocks we are interested in and set their current value
   Stock s1("entu", 43.0); 
   Stock s2("nortel", 44.0); 
   Stock s3("newbridge", 47.0); 
   Stock s4("xerox", 49.0); 

   //add stocks we want to trade in portfolio 
   portfolio.add(s1); 
   portfolio.add(s2); 
   portfolio.add(s3); 
   portfolio.add(s4); 

  
   //print portfolio at start 
   file << portfolio << "\n"; 
  
   //create buy and sell actions to buy and sell stocks 
   //when appropriate. actions with price of 0.0 are traded 
   //at the current market value of the stock 

   //create actions as annonymous stack objects
   BuyAction(s1, portfolio, 20); 
   BuyAction(s2, portfolio, 30); 
   BuyAction(s3, portfolio, 30); 
   BuyAction(s1, portfolio, 20, 18.0 ); 
   BuyAction(s2, portfolio, 40, 20.0); 
   SellAction(s1, portfolio, 30, 98.0); 
   SellAction(s2, portfolio, 40, 75.0); 
  

   //read stock market data simulation file and 
   //react to stock price changes 

   //open simulation stock quote file
   ifstream infile(dataFileName, ifstream::in); 
   if (!infile) { 
      cerr << "simulation data file: " << dataFileName << " could not be opened" << endl; 
	  //keep console open until user types a key and enter
     const int MAX_INPUT_SIZE = 100;
     cout <<"\n\n" << "Press ENTER to continue";
     char user_input[MAX_INPUT_SIZE]; //buffer to hold input of input typed by user
     cin.getline(user_input, MAX_INPUT_SIZE);

     exit(1); 
 } 

   char stockSymbol[80]; 
   float stockValue; 

   //read simulation of stock price changes and inform portfolio of them
   while (infile >> stockSymbol >> stockValue) { 
      cout << stockSymbol << "  $" << stockValue << "\n"; 
      file << stockSymbol << "  $" << stockValue << "\n"; 
      portfolio.priceChange(stockSymbol, stockValue); 
 } 

   //output final portfolio value 
   file << "\n"; 
   file << portfolio; 
  
   infile.close(); 
   file.close(); 

   //keep console open until user types a key and enter
  const int MAX_INPUT_SIZE = 100;
  cout <<"\n\n" << "Press ENTER to continue";
  char user_input[MAX_INPUT_SIZE]; //buffer to hold input of input typed by user
  cin.getline(user_input, MAX_INPUT_SIZE);
   
  return 0; 
} 

