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

#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>
using namespace std;


//Application commands
const string CMD_ADD = "add"; //add items to collections
const string CMD_DELETE = "delete"; //delete items from collections
const string CMD_SHOW = "show"; //display collections

//UI shell only commands
const string UICMD_LOG = ".log"; //log comands and output
const string UICMD_HELP = ".help"; //show command help documentation
const string UICMD_QUIT = ".quit"; //quit the application
const string UICMD_READ = ".read"; //read commands from script file

//Developer commands (for debugging)
const string DEV_trim = ".trim";
const string DEV_endsWith = ".endsWith";
const string DEV_startsWith = ".startsWith";
const string DEV_toTitleCase = ".toTitleCase";

const string UICommands[] = {
	UICMD_QUIT,
	UICMD_LOG,
	UICMD_HELP,
	UICMD_READ
	};
const int NumberOfUICommands = 4;
const string AppCommands[] = {
	CMD_ADD,
	CMD_DELETE,
	CMD_SHOW,
	};
const int NumberOfAppCommands = 3;

const string DevCommands[] = {
	DEV_trim,
	DEV_startsWith,
	DEV_endsWith,
    DEV_toTitleCase
	};
const int NumberOfDevCommands = 4;


class Command
{
  public:
   Command(string cmdStr);
   string getCommandString();
   string getCommandName();
   bool hasToken(string s); 
   int indexOfToken(string s);
   string getToken(int i);
   string getToken(string s); //get token indexed by string s
   bool isCommand(string aCommandName);
   bool isTokenAt(int index, const string & s);
   bool isValidIndex(string anIndex);
   bool isUICommand();
   bool isAppCommand();
   bool isDevCommand();

  private:
   string commandString;
   vector<string> tokens;
   void parse(string commandString);

};

#endif
