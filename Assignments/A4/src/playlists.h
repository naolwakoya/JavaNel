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

#ifndef _PLAYLISTS_H
#define _PLAYLISTS_H

#include <ostream>
#include <vector>
#include <string>
using namespace std;
#include "UI.h"
#include "playlist.h"
#include "user.h"

class Playlists {

	public:
	Playlists();
	~Playlists(void);
	Playlist * findByID(int anID);
	vector<Playlist*> getCollection();
	void add(Playlist & aPlaylist);
	void remove(Playlist & aPlaylist);
	void showOn(UI & aView);
	void showOn(UI & aView, int memberID);

	private:
	vector<Playlist*> collection;
	vector<Playlist*>::iterator findPosition(Playlist & aPlaylist);
};

#endif