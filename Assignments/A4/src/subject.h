/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Author:   Louis Nel								               */
/*  Students: Kaleb Tesfay, Naol Gushu		           */
/*                                                   */
/*  (c) 2019 Louis Nel                               */
/*  All rights reserved.  Distribution and           */
/*  reposting, in part or in whole, requires         */
/*  written consent of the author.                   */
/*                                                   */
/*  COMP 2404 students may reuse this content for    */
/*  their course assignments without seeking consent */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef SUBJECT_H
#define SUBJECT_H
#include <iostream>
#include <iterator>

#include "observer.h"
#include "arraylist.h"

using namespace std;

class Subject { 
//    ======= 
ArrayList<Observer> observers; 
public: 
  void attach(Observer &obs) { 
    observers.add(obs); 
    cout << "\nAttach: " << " observers size: " << observers.size() << "\n";
    notify();

  } 
  void dettach(Observer &obs) { 
    observers.remove(obs);
    cout << "\nDettach: " << " observers size: " << observers.size() << "\n";
    notify();
  } 

protected: 
  void notify() { 

   //notify all observers that something about the subject they
   //are watching has changed. concrete subclasses should call
   //this method whenever a state change has ocurred that
   //observers might be interested in

   //Note: observer collection is copied and the copy 
   //iterated over so that observers can dettach 
   //when they are being notified (i.e. double buffering)

   //In the Gamma pattern this is not done and that code will
   //blow up in a situtation where observers choose to detach as
   //a result of being notified
   ArrayList<Observer> observers_copy = observers; //make copy to iterate over
   for(ArrayList<Observer>::iterator itr = observers_copy.begin(); itr != observers_copy.end(); itr++) { 
      (*itr).update((Subject*) this); 
   }
  }

}; 
#endif
