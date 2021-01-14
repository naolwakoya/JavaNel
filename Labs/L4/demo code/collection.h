#ifndef _collection_h
#define _collection_h

#include <iostream>
#include <cstring>
#include "person.h"

using namespace std;

const int INITIAL_COLLECTION_SIZE = 12;

typedef Person T;
class  Collection {

public:

Collection (int len = INITIAL_COLLECTION_SIZE);
Collection(const Collection & c);
~Collection (void);
int capacity (void);
Collection & addElementAt(T & x, int index);
T& elementAt(int index);
Collection & operator=(const Collection & c);
void printOn(ostream & o) const;

private:
   int mysize;
	 T **buffer;

}; //end class Collection

ostream & operator<<(ostream & o, const Collection & c);

#endif
