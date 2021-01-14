#include <string>

/*
This class represent a holding of shares of stocks
*/
class Stock : public Subject{ 
//    ===== 
string exchange; //not used for this assignment 
string symbol; //stock exchange symbol for stock
int shares;  //number of shares
float market_value;  //current market value

public: 
 Stock(string sym = "ACME", float price = 0.0, int num_shares = 0, string xch = "NASDAQ" ): 
   exchange(xch), symbol(sym), shares(num_shares), market_value(price) { } 

 Stock (const Stock & s) : exchange(s.exchange), symbol(s.symbol), shares(s.shares), market_value(s.market_value) { } 

 Stock & operator=(const Stock & s) 
 { 
    if (this != &s) { 
        symbol = s.symbol;
		exchange = s.exchange;
        market_value = s.market_value; 
        shares = s.shares; 

    } 
    

 return *this; 
 
 } 
  

 ~Stock(void) { 
 } 
 void printOn(ostream & out) const { 
  out << symbol << "  " << shares << " $" << market_value; 
  
 } 
 int operator==(const Stock & s) const { 
  return symbol.compare(s.symbol) == 0;
 } 

 void setMarketValue(float newprice) { 
  market_value = newprice; 
  notify();
 } 
 float getMarketValue() const {return market_value;} 

 void setShares(int n) { shares = n; } 

 int getShares(void) const {return shares;} 

 string getSymbol() const {return symbol;} 

}; 
ostream & operator<< (ostream & out, const Stock & s) { 
 s.printOn(out); 
 return out; 
} 

