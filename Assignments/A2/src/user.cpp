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
using namespace std;

#include "user.h"

int User::nextUserNumericID = 1000;

User::User(const string & aUserID, const string & aName){
	cout << "User(string&, string&, int)" << endl;
	userid = aUserID;
	name = aName;
	id = nextUserNumericID++;
}
User::User(const User & aUser){
	cout << "User(const User & aUser)" << endl;
	cout << "ERROR: User(const User & aUser) --should never run" << endl;
}
User::~User(){
	cout << "~User(void)" << endl;
	for(int i=0; i<collection.size(); i++)
		delete collection[i];

}

string User::getUserID(){return userid;}

Playlist* User::findPlaylist(const string & aPlaylistName){
	for (auto itr = collection.begin() ; itr != collection.end(); ++itr)
		if(((*itr)->getName()) == aPlaylistName) return *itr;
	return NULL;
}

void User::addPlaylist(Playlist & aPlaylist){
	auto itr = findPosition(aPlaylist);
	if(itr == collection.end()) {
		collection.push_back(&aPlaylist);
	}
}

void User::removePlaylist(Playlist & aPlaylist){
	auto itr = findPosition(aPlaylist);
	if(itr != collection.end()) {
	   Playlist * playlist = *itr;
	   collection.erase(itr);
	   delete playlist;
	}
}

void User::removeTrack(Track & aTrack){
	for (auto itr = collection.begin() ; itr != collection.end(); ++itr){
		Playlist * playlist = *itr;
		playlist->removeTrack(aTrack);
	}

}
string User::toString()const {
	string indent = "     ";
	string s;
	s.append(userid + " " + name);
	s.append("\n");
	s.append(indent + "Playlists:\n");
	for (vector<Playlist*>::size_type i = 0 ; i < collection.size(); i++){
		   s.append(indent + to_string(i) + " " + (collection[i])->toString() + "\n");
		   s.append("\n");
	}

	return s;
}

ostream & operator<<(ostream & out, const User & aUser){
	out << aUser.toString() << endl;
	return out;
}
