#include <iostream>
#include <string>
#include "Pet.h"
using namespace std;

  Pet::Pet(string aName, string aType){
    name = aName;
    type = aType;

  }
  void Pet::printOn(ostream & out){
    out << name
        << "  type: "
        << type;
  }