#include <string.h> 

class Subject; 
class Observer { 
  public: 
  virtual void update(Subject * subject)= 0; 

  virtual void printOn(ostream & out) const = 0; 

  int operator==(const Observer & obs) const { 
    return this == & obs; 
  } 

}; 

ostream & operator<<(ostream & out, const Observer & obs) { 
 obs.printOn(out); 
 return out; 
} 

