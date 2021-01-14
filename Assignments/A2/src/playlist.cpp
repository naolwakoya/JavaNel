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
#include "playlist.h"

using namespace std;
	
Playlist::Playlist(const string & aPlaylistName){
	cout << "Playlist(string&)" << endl;
	name = aPlaylistName;
}
Playlist::Playlist(const Playlist & aPlaylist){
	cout << "Playlist(const Playlist & aPlaylist)" << endl;
	cout << "ERROR: Playlist(const Playlist & aPlaylist) --should never run" << endl;
}

Playlist::~Playlist(){
	cout << "~Playlist(void)" << endl;
}

string Playlist::getName(){return name;}

vector<Track*> & Playlist::getTracks(){return collection;}

void Playlist::addTrack(Track & aTrack){
    auto itr = findPosition(aTrack);
	if(itr == collection.end()) {
		collection.push_back(&aTrack);
	}	
}

void Playlist::removeTrack(Track & aTrack){
    auto itr = findPosition(aTrack);
	if(itr != collection.end()) {
		collection.erase(itr);
	}
}

string Playlist::toString()const {
    string indent = "     ";
    string s;
    s.append(name);
    s.append("\n");
    s.append(indent + indent + "Playlist Tracks:\n");
    for (vector<Track *>::size_type i = 0; i < collection.size(); i++) {
        s.append(indent + indent + to_string(i) + " " + (collection[i])->toString() + "\n");
    }

    return s;
}