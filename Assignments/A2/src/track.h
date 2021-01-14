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

#ifndef _TRACK_H
#define _TRACK_H

#include <ostream>
#include <string>
using namespace std;

#include "song.h"
#include "data.h"

typedef Song Ss;
class Track: public data<Track> {
	
	public:
	Track(const int aTrackID, Song * songptr, const string & anMp3FileName = "Unknown" );
	~Track(void);
    Song * getSong();
    string getMp3FileName();
	string toString() const;
	private:
	Song * song;
	string mp3FileName;
	Track(const Track & aTrack);
	Ss** buffer;
	int mysize;
};
ostream & operator<<(ostream & out, const Track & aTrack);

#endif
