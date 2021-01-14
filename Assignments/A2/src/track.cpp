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
using namespace std;

#include "track.h"

Track::Track(const int aTrackId, Song * songptr, const string & anMp3FileName ){
	cout << "Track(int, Song*, string&)" << endl;
	id = aTrackId;
	song = songptr;
	mp3FileName = anMp3FileName;

	mysize = aTrackId;
    buffer = new Ss*[aTrackId];
	for(int i=0; i<mysize; i++) buffer[i] = NULL;
}
Track::Track(const Track & aTrack){
	cout << "Track(const Track & aTrack)" << endl;
	cout << "ERROR: Track(const Track & aTrack) --should never run" << endl;

	mysize = aTrack.mysize;
    buffer = new Ss*[aTrack.mysize];
	for(int i=0; i<aTrack.mysize; i++) buffer[i] = NULL;
}
Track::~Track(){
	cout << "~Track(void)" << endl;
	delete [] buffer;
}

Song * Track::getSong(){return song;}
string Track::getMp3FileName(){return mp3FileName;}

string Track::toString()const {
	return to_string(id) + ": " + song->getTitle() + " mp3: " + mp3FileName;
}

ostream & operator<<(ostream & out, const Track & aTrack){
	out << aTrack.toString() << endl;
	return out;
}
