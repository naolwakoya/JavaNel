#include "collection.h"

using namespace std;

Collection::Collection (int len) { //constructor
	cout << "\nCollection(int) CREATE COLLECTION\n";
      mysize = len;
      buffer = new T*[len];
	     for(int i=0; i<mysize; i++) buffer[i] = NULL;
}

Collection::Collection(const Collection & c) {
	cout << "\nCollection(int) CREATE COLLECTION\n";
      mysize = c.mysize;
      buffer = new T*[c.mysize];
	     for(int i=0; i<mysize; i++) buffer[i] = NULL;
}

Collection::~Collection (void) {
	  cout << "\n~Collection DELETE COLLECTION";
    delete  [] buffer;
}

Collection & Collection::operator=(const Collection & c) {

//code not shown

       if(&c != this) {
		   mysize = c.mysize;
		   buffer = new T*[c.mysize];
	     for(int i=0; i<mysize; i++) buffer[i] = NULL;

		}
		return *this;
	}

int Collection::capacity (void) { return mysize; }

Collection & Collection::addElementAt(T & x, int index) {
			if(index < mysize) buffer[index] = &x;
            return *this;
	}

T& Collection::elementAt(int index) { return *buffer[index] ;}

void Collection::printOn(ostream & o) const {
//This method should print all the non NULL
//elements in the container

	o << "Contents:\n";
	for (int i=0; i<mysize; i++)
			if(buffer[i] != NULL)
			 o << *buffer[i] << "\n";
}

ostream & operator<<(ostream & o, const Collection & c) {
	c.printOn(o);
	return o;
}
