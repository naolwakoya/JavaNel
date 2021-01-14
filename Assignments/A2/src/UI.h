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

#ifndef UI_H
#define UI_H

#include <string>
#include <sstream>
using namespace std;
#include "command.h"


class MyTunes; //forward declaration needed

class UI
{
  public:
   UI(MyTunes * anOwner);
   void run();
   void printOutput(string message);

  private:
   MyTunes * owner; //owner app
   enum LogMode {OFF, COMMAND, OUTPUT, BOTH};
   LogMode logging;
   vector<string> logs;
   void promptForStr(string, string&);
   void pause();
   void printError(string err);
   void printMessage(string message);
   void executeCommand(Command aCommand);
   void executeDevCommand(Command aCommand);
   void executeUIREAD(Command cmd);
   void executeUILOG(Command cmd);
   void executeUIHELP(Command cmd);
};

#endif
