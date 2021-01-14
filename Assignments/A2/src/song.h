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

#ifndef _SONG_H
#define _SONG_H

#include <ostream>
#include <string>
#include "data.h"
#include "str_util.h"

typedef StrUtil S;
class Song: public data<Song> {
	
	public:
	Song(const string & aTitle, const string & aComposer, const int anId = -1);
	~Song(void);
	string getTitle()const;
    string toString() const;
	private:
	string title;
	string composer;
	Song(const Song & aSong);
	S** buffer;
	int mysize;

};
ostream & operator<<(ostream & out, const Song & aSong);

#endif
