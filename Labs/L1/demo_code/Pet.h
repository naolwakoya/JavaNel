#include <iostream>
#include <string>
using namespace std;

class Pet {
private:
  string name;
  string type;

public:
  Pet(string aName, string aType);
  void printOn(ostream & out);

};