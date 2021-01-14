/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Author:   Louis Nel								               */
/*  Students: Kaleb Tesfay, Naol Gushu		           */
/*                                                   */
/*  (c) 2019 Louis Nel                               */
/*  All rights reserved.  Distribution and           */
/*  reposting, in part or in whole, requires         */
/*  written consent of the author.                   */
/*                                                   */
/*  COMP 2404 students may reuse this content for    */
/*  their course assignments without seeking consent */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef MYTUNES_H
#define MYTUNES_H
#include <sstream>
#include "UI.h"
#include "command.h"
#include "song.h"
#include "recording.h"
#include "track.h"
#include "user.h"
#include "mytunes_collection.h"

using namespace std;


class MyTunes
{
  public:
    MyTunes();
    void run();
    void executeCommand(Command cmd);
  private:
    UI view;
		int nextAvailableSongID;
		int nextAvailableRecordingID;
		int nextAvailableTrackID;
		mytunes_collection<Song> songs;
		mytunes_collection<Recording> recordings;
		mytunes_collection<Track> tracks;
		mytunes_collection<User> users;

    void executeCMDADD(Command cmd);
    void executeCMDDELETE(Command cmd);
    void executeCMDSHOW(Command cmd);
		void executeAddSong(Command cmd);
		void executeAddRecording(Command cmd);
		void executeAddTrack(Command cmd);
		void executeAddUser(Command cmd);
		void executeAddPlaylist(Command cmd);
		void executeAddPlaylistTrack(Command cmd);
		void executeDeleteRecording(Command cmd);
		void executeDeleteUser(Command cmd);
		void executeDeleteUserPlaylist(Command cmd);
		void executeDeleteUserPlaylistTrack(Command cmd);
		void executeDeleteTrack(Command cmd);
		void executeDeleteSong(Command cmd);

};
#endif
