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

#ifndef _RECORDING_H
#define _RECORDING_H

#include <ostream>
#include <string>
#include <vector>

#include "track.h"
typedef Track T;

const int MAX_NUMBER_OF_TRACKS = 25;

class Recording: public data<Track> {

	public:
	Recording(const string & aTitle,
	          const string & anArtist,
              const string & aProducer,
              const string & aYear,
			  int anId = -1);
	~Recording();
	void removeTrack(Track & aTrack);
	void addTrack(Track & track, int position);
    string toString() const;
		int mysize;

	private:
	string title, artist, producer, year;
	Recording(const Recording & aRecording);
	T** buffer;
};
ostream & operator<<(ostream & out, const Recording & aRecording);

#endif
