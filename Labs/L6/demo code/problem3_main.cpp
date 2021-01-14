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

//demo2_main.cpp
#include <iostream>
#include <string>
using namespace std;
#include "sqlite3.h"


string input; //user input from console
const char * db_file_name = "beatles.db";
sqlite3 *db; //pointer to our database
char * zErrMsg = 0; //pointer to error returned by sqlite
int rc; //return code

const char * sql = "SELECT * FROM recordings"; //SQL Query String
const char * data = "call back function called"; //passed back on callback;

static int callback(
  //callback funtion that will be called by sqlite3_exec() when SQL
  //query has completed
  void * data, //data provided to sqlite3_exec() [4th argument]
  int argc, //Number of columns in answer table row
  char ** argv, //array of string representing table row values
  char ** azColName //array of strings representing column names
  ){
    //cout << (const char *) data << "\n";
    for (int i=0; i<argc; i++){
      cout << argv[i] << ", ";
    }
    cout << "\n";
    return 0;
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
  else {
    cout << "\nSUCCESSFULLY OPENED DATABASE: " << db_file_name << "\n\n";
    rc = sqlite3_exec(db, sql, callback, (void *) data, &zErrMsg);
    if( rc != SQLITE_OK) {
      cout << "ERROR EXECUTING SQL: " << zErrMsg;
      sqlite3_free(zErrMsg);
    }
    else {
      cout << "\nSQL QUERY SUCCEEDED\n";
    }

  }
  //close database connection
  sqlite3_close(db);


  //keep console open until user presses a key
  cout << "\n\n" << "Press any key to continue";
  getline(cin, input);
  return 0;
}
