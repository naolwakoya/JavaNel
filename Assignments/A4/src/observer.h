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
#ifndef OBSERVER_H
#define OBSERVER_H
#include <iostream>
#include <string.h> 

class Subject; 
class Observer { 
  public: 
  virtual void update(Subject * subject)= 0; 
  /*
  virtual void printOn(ostream & out) const = 0; 
  */
  int operator==(const Observer & obs) const { 
    return this == & obs; 
  } 

}; 
#endif
/*
ostream & operator<<(ostream & out, const Observer & obs) { 
 obs.printOn(out); 
 return out; 
} 
*/

