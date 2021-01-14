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

#include "song.h"

Song::Song(const string & aTitle, const string & aComposer, const int anID){
	cout << "Song(string&, string&, int)" << endl;
	title = aTitle;
	composer = aComposer;
	id = anID;

	mysize = anID;
    buffer = new S*[anID];
	for(int i=0; i<mysize; i++) buffer[i] = NULL;
}
Song::Song(const Song & aSong){
	cout << "Song(const Song & aSong)" << endl;
	cout << "ERROR: Song(const Song & aSong) --should never run" << endl;

	mysize = aSong.mysize;
    buffer = new S*[aSong.mysize];
	for(int i=0; i<aSong.mysize; i++) buffer[i] = NULL;
}
Song::~Song(){
	cout << "~Song(void)" << endl;
	delete [] buffer;
}

string Song::getTitle() const {return StrUtil::toTitleCase(title);}

string Song::toString()const {
	return to_string(id) + " " + getTitle() + " " + composer;
}

ostream & operator<<(ostream & out, const Song & aSong){
	out << aSong.toString() << endl;
	return out;
}
