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

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "playlist.h"
#include "playlists.h"
#include "user.h"

Playlists::Playlists(){
}
Playlists::~Playlists(void){
	for(int i=0; i<collection.size(); i++)
		delete collection[i]; //delete Playlists in this container
}
vector<Playlist*> Playlists::getCollection(){return collection;}

vector<Playlist*>::iterator Playlists::findPosition(Playlist & aPlaylist){
	for (vector<Playlist*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if(*it == &aPlaylist) return it;
	return collection.end();
}
Playlist * Playlists::findByID(int anID){
	for (vector<Playlist*>::iterator it = collection.begin() ; it != collection.end(); ++it)
		if((*it)->getID() == anID) return *it;
	return NULL;
}
void Playlists::add(Playlist & aPlaylist){
	collection.push_back(&aPlaylist);
}
void Playlists::remove(Playlist & aPlaylist){
	vector<Playlist*>::iterator index = findPosition(aPlaylist);
	if(index != collection.end()) {
		Playlist * thePlaylist = *index;
		collection.erase(index);
		delete thePlaylist; //free the memory of thePlaylist
	}
}
void Playlists::showOn(UI & view)  {
  view.printOutput("Playlists:");
  for(int i=0; i<collection.size(); i++){
       view.printOutput((*collection[i]).toString());
  }
}
void Playlists::showOn(UI & view, int memberID)  {
  view.printOutput("Playlists:");
  Playlist * p = findByID(memberID);
  if( p != NULL)
       view.printOutput(p->toString());
}