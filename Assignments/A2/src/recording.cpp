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
#include "recording.h"
using namespace std;

Recording::Recording(const string & aTitle,
           const string & anArtist,
           const string & aProducer,
           const string & aYear,
		   const int anID){
	cout << "Recording(string&, string&, String&, String&, int)" << endl;
	title = aTitle;
	artist = anArtist;
	producer = aProducer;
	year = aYear;
	id = anID;
	collection = vector<Track*>(MAX_NUMBER_OF_TRACKS, NULL);

	mysize = anID;
    buffer = new T*[anID];
	for(int i=0; i<mysize; i++) buffer[i] = NULL;
}
Recording::Recording(const Recording & aRecording){
	cout << "Recording(const Recording & aRecording)" << endl;
	cout << "ERROR: Recording(const Recording & aRecording) --should never run" << endl;
	mysize = aRecording.mysize;
    buffer = new T*[aRecording.mysize];
	for(int i=0; i<aRecording.mysize; i++) buffer[i] = NULL;
}
Recording::~Recording(){
	cout << "~Recording(void)" << endl;
	delete [] buffer;

}

void Recording::addTrack(Track & aTrack, int position){
	auto itr = findPosition(aTrack);
	if(itr == collection.end()) {
		if(position >=0 && position < MAX_NUMBER_OF_TRACKS)
		   collection[position] = &aTrack;
	}
}

void Recording::removeTrack(Track & aTrack){
	for (auto &i : collection)
		if(i == &aTrack) i = NULL;
}

string Recording::toString()const {
	string indent = "     ";
	string s;
	s.append(to_string(id) + " " + title + " " + artist + " " + producer + " " + year);
	s.append("\n");
	s.append(indent + "collection:\n");
	for (vector<Track*>::size_type i = 0 ; i < collection.size(); i++){
		if(collection[i] != NULL)
		   s.append(indent + to_string(i) + " " + (collection[i])->toString() + "\n");
	}

	return s;
}

ostream & operator<<(ostream & out, const Recording & aRecording){
	out << aRecording.toString() << endl;
	return out;
}
