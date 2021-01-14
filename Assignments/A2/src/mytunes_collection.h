/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Author:   Louis Nel								 */
/*  Students: Kaleb Tesfay, Naol Gushu		         */
/*                                                   */
/*  (c) 2019 Louis Nel                               */
/*  All rights reserved.  Distribution and           */
/*  reposting, in part or in whole, requires         */
/*  written consent of the author.                   */
/*                                                   */
/*  COMP 2404 students may reuse this content for    */
/*  their course assignments without seeking consent */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */


#ifndef MYTUNESCOLLECTION_H
#define MYTUNESCOLLECTION_H

#include "UI.h"
#include <typeinfo>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class mytunes_collection {
public:
    ~mytunes_collection() {
        for (int i=0; i<collection.size(); i++)
            delete collection[i]; // Free up used memory
    }
    // This is one uniform protocol that all the collections can use
    template <typename V>
    T * findByID(V anID) const {
        return compareID(anID);
    }
    // Compare string input to existing username's
    T * compareID(const string& anID) const {
        for (typename vector<T*>::const_iterator itr = collection.begin(); itr != collection.end(); ++itr)
            if((*itr)->getUserID() == anID) return *itr;
    }
    // Compare id input to Track/Song/Recording id
    T * compareID(const int& anID) const {
        for (typename vector<T *>::const_iterator i = collection.begin(); i != collection.end(); ++i)
            if ((*i)->getID() == anID){
              return *i;
            }

    }
    // Add the item to the collection
    void add(T &item) {
        collection.push_back(&item);
    }
    // Remove the item from the collection
    void remove(T &item) {
        typename vector<T*>::iterator index = findPosition(item); // Find the item in the collection
        if (index != collection.end()) {
            T * theItem = *index;
            collection.erase(index); // Free the memory allocated to the item
            delete theItem;
        }
    }
    // Print to the UI
    void showOn(UI & aView) {
        aView.printOutput("Print:");
        for (int i=0; i<collection.size(); i++)
            aView.printOutput((*collection[i]).toString());
    }
    // This function takes a generic parameter and calls the .toString() function inside their class
    template<typename V>
    void showOn(UI & aView, V memberID) {
        T * item = findByID(memberID);
        if (item != NULL)
            aView.printOutput(item->toString());
    }
    // Refactored Code
    friend std::ostream& operator<<(ostream& out, const T& t) {
        return out << t.toString() << endl;
    }
    // This exists so that classes can iterate through the collection without changing any data
    vector<T*> getCollection() const {
        return collection;
    }
    typename vector<T*>::iterator findPosition(T &item) {
        for(typename vector<T*>::iterator it = collection.begin(); it != collection.end(); ++it)
            if (*it == &item) return it;
        return collection.end();
    }

private:
    vector<T*> collection;
};

#endif 
