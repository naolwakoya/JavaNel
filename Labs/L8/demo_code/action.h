
  

class Action : public Observer { 
//    ======= 
protected: 
  Stock & stock;  //stock to buy or sell
  Portfolio & portfolio; //portfolio in which stock is bought and sold
  float action_price;  //price at which stock is to be bought or sold
                       //action is immediate if price = 0.0
  int num_shares;  //number of shares to buy or sell.
public: 
 Action(Stock & aStock, Portfolio & p, int num, float price = 0.0) : 
    stock(aStock), portfolio(p), action_price(price), num_shares(num) { 
      stock.attach(*this);
 } 

virtual void update(Subject * s) {
  cout << "update() in Action";
}
 virtual void execute(){}; //execute the action on the portfolio
                           //do nothing, sublclassses should override this
                         

 virtual void printOn(ostream & out) const { 
         out << "Action " << this << "\n";} 

}; 

ostream & operator<<(ostream & out, Action & act) { 
 act.printOn(out); 
 return out; 
} 

class BuyAction :public Action { 
//    ========== 
/*
A BuyAction will buy stock in a portfolio using money from the account of the portfolio.

*/
public: 
 BuyAction(Stock & stock, Portfolio & p, int num, float price = 0.0) : 
   Action(stock, p, num, price) {} 

virtual void execute(){
	//execute the action --actually buy the stock
	portfolio.buy(stock, num_shares);  //buy stock
}

virtual void update(Subject * s){
  if(action_price <= 0.0){
    execute();
    stock.dettach(*this);
  }
  else if(stock.getMarketValue() <= action_price){
    execute();
    stock.dettach(*this);
  }
}


}; 

class SellAction :public Action { 
//    =========== 
/*
A SellAction will sell stock in a portfolio using money from the account of the portfolio.

*/
public: 
 SellAction(Stock & stock, Portfolio & p, int num, float price = 0.0) : 
     Action(stock, p, num, price) {} 

 virtual void execute(){
	 //execute the action --actually sell the stocks
	 portfolio.sell(stock, num_shares); //sell stocks
 }

 virtual void update(Subject * s){
   if(action_price <= 0.0){
     execute();
     stock.dettach(*this);
   }
 }
 
}; 

