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
#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <list>

#include "sqlite3.h"

using namespace std;

class Database{
    public:
        Database(char*);
        ~Database();
        void open(char*);
        void queryDatabase(string);
        list<list<string> > prepare(const char*);
        void close();
        void errorDectection(const char*);
    private:
        const char * db_file_name = "../beatles.db";
        sqlite3 *db; //pointer to our database
        char * zErrMsg = 0;  //will be used for query error messages
        int rc; //return code
        const char * data = "callback called"; //data passed through to callback
        sqlite3_stmt *s;

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
            /*
            for (int i=0; i<argc; i++){
            cout << argv[i] << ", ";
            }
            cout << "\n";
            */
            return 0;
            
        }
        
        
};

#endif