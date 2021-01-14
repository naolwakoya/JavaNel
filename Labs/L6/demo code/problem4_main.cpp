/*
Accessing SQLite Database from C++
===================================
This is a simple example of connecting to an sqlite database from c++
and allowing the user to make sql queries against it.
It uses the beatles.db database from Assignemnt #2.

Examine the database with the sqlite3.exe CLI program to
learn more about the database before using this code

The c API for accessing the SQLite database from c programs is
documented here
http://www.sqlite.org/cintro.html

sqlite3.h provides a c++ interface to these c API functions

Things to notice:
1)SQLite api uses c-style strings (char *) and not string objects

2)Our first cast in the course (but it's not our code.) Why do you
think the cast to a void * is being done?

3)Passing a function as argument to another function (i.e. callback)

4)c-code accessed from c++ code
*/

#include <iostream>
#include <string>
using namespace std;

#include "sqlite3.h"


const char * db_file_name = "beatles.db";
sqlite3 *db; //pointer to our database
char * zErrMsg = 0;  //will be used for query error messages
int rc; //return code
const char * data = "callback called"; //data passed through to callback

static int callback(
  //callback function that will be called by sqlite3_exec() for each
  //row in the query result table when the query has completed.
  void * data, //pass through data provided to sqlite3_exec() [4th argument]
  int argc, //Number of columns in answer table row
  char ** argv, //array of strings representing table row values
  char ** azColName //array of strings representing column names
  ){
    //cout << (const char *) data << "\n";
	//print values for the row
    for (int i=0; i<argc; i++){
      cout << argv[i] << ", ";
    }
    cout << "\n";
    return 0;
  }


void queryDatabase(string queryString){
	  //execute SQL queryString against the database
	  if(queryString.empty()) return;
	  const char * sqlQuery = queryString.c_str();
      rc = sqlite3_exec(db, sqlQuery, callback, (void *) data, &zErrMsg);
      if( rc != SQLITE_OK) {
          cout << "ERROR EXECUTING SQL: " << zErrMsg;
          sqlite3_free(zErrMsg);
      }
      else {
         cout << "\nSQL QUERY SUCCEEDED\n";
      }
 }
int main(void){

  cout << "Hello SQLite\n";

  //establish connection to database
  rc = sqlite3_open(db_file_name, &db);
  if(rc){
    cout << "ERROR: Could Not Open Database: "
         << sqlite3_errmsg(db);
    cout << "\nEXITING\n";
    return 0;
  }

  cout << "\nSUCCESSFULLY OPENED DATABASE: " << db_file_name << "\n\n";

  //Do initial query
  string sql = "SELECT * FROM recordings"; //SQL Query String
  queryDatabase(sql);


  //Run UI to prompt for more SQL queries
  string input;
  while (true) {
    cout << ("Enter SQL Command or .quit >");
	getline(cin, input);
	if(input.compare(".quit") == 0) break;
	queryDatabase(input);
  }

  //close database connection
  cout << "closing database:  " << db_file_name << "\n";
  sqlite3_close(db);

  return 0;
}
