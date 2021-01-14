#include <string>

class Portfolio { 
//    ========= 

/*
This class represents a portfolio of stock market stocks. It consists of a collection of stocks and
a bank account out of which buy and sell costs will be deposited and withdrawn
*/

string owner; //owner of the portfolio
int portfolio_id;         //unique id for portfolio
BankAccount & account;    //bank account from which buy and sell will be paid for or credited
ArrayList<Stock> stocks;  //collection of stock holdings in this portfolio
static int next_portfolio_id; //used to initialize new portfolios
static float service_charge;  //$ amount charged for each buy and sell transaction


//portfolio assignment not allowed hence private 
Portfolio & operator=(const Portfolio & p){return *this;}  //don't allow assignment of portfolios
Portfolio (const Portfolio & p): account(p.account){}  //don't allow copy construction of portfolios
  

public: 
 Portfolio(string customer, BankAccount & acct): 
   owner(customer), portfolio_id(next_portfolio_id++), account(acct) { 
 } 

 /*
 Portfolio (const Portfolio & p) : owner(p.owner), account(p.account), portfolio_id(next_portfolio_id++) 
 { 
    ArrayList<Stock> & p_stocks = (ArrayList<Stock>) p.stocks; 
    for(ArrayList<Stock>::iterator itr = p_stocks.begin(); itr != p_stocks.end(); itr++) 
        stocks.add(*itr); 
 } 
 */

 ~Portfolio(void) { } 

 void priceChange(string stock_symbol, float price) { 
    //change the price of any stock with symbol stock_symbol 
   for(ArrayList<Stock>::iterator itr = stocks.begin(); itr != stocks.end(); itr++) 
    if((*itr).getSymbol().compare(stock_symbol)==0) { 
        (*itr).setMarketValue(price); 

    } 

 } 

 float market_value() const { 
	//answer the value of the portfolio based on the current market value of each stock
	//in the portfolio

    float value = account.balance(); 
    for(const ArrayList<Stock>::iterator itr = stocks.begin(); itr != stocks.end(); itr++) 
    value += ((*itr).getMarketValue() * (*itr).getShares()); 
    return value; 

 } 

 void printOn(ostream & out) const { 
  out << "Portfolio#" << portfolio_id << "  "<< account << "\n"; 
  for(ArrayList<Stock>::iterator itr = stocks.begin(); itr != stocks.end(); itr++) 
         out << *itr << "\n"; 
  out << "portfolio value $" << market_value() << "\n"; 
  

 } 


 void add(Stock &s) {stocks.add(s);} 

 void remove(Stock & s) {stocks.remove(s);} 

 void buy(Stock & s, int ns) { 
    //buy ns shares of stock s owned by this portfolio. Take the money from the bankaccount
	//associated with portfolio and withdraw service charge from the same account

    int found = 0; 
    for(ArrayList<Stock>::iterator itr = stocks.begin(); itr != stocks.end(); itr++) 
        if(((*itr) == s) && !found) { 
           found = 1; 
           account.withdraw((*itr).getMarketValue() * ns); 
           account.withdraw(service_charge); 
           (*itr).setShares((*itr).getShares() + ns); 
           cout << "TRANSACTION: BUY " << ns << " shares of " << s << " portfolio $" << market_value()  << "\n"; 
           file << "TRANSACTION: BUY " << ns << " shares of " << s << " portfolio $" << market_value()  << "\n"; 

       } 
 } 

 void sell(Stock & s, int ns) { 
    //sell up to ns shares of stock s owned by this portfolio and deposit money from sale into
	//the bank account associated with this portfolio
    //withdraw the service charge amount for the transaction from the same bank account

    int found = 0; 
    for(ArrayList<Stock>::iterator itr = stocks.begin(); itr != stocks.end(); itr++) 
       if(((*itr) == s) && !found) { 
          found = 1; 
		  int numberOfShares = ns;
		  if(itr->getShares() < ns) numberOfShares = itr->getShares();
          account.deposit((*itr).getMarketValue() * numberOfShares); 
          account.withdraw(service_charge); 
          (*itr).setShares((*itr).getShares() - numberOfShares); 
          cout << "TRANSACTION: SELL " << numberOfShares << " shares of " << s << " portfolio $" << market_value() <<"\n"; 
          file << "TRANSACTION: SELL " << numberOfShares << " shares of " << s << " portfolio $" << market_value() <<"\n"; 

     }   
} 

}; 

ostream & operator<< (ostream & out, const Portfolio & p) { 
 p.printOn(out); 
 return out; 
} 

//initialize static variables. Must be done outside the class
int Portfolio::next_portfolio_id = 100; 
float Portfolio::service_charge = 30.00; 

