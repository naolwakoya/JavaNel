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
#include <iostream>
#include <sstream>
#include <string>
#include "database.h"
using namespace std;

Database::Database(char* fn){
	open(fn);
}

Database::~Database(){}

void Database::queryDatabase(string queryString){
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

void Database::open(char* fn){
	if(sqlite3_open(fn, &db) == SQLITE_OK){
		cout << "CONNECTED TO DATABASE\n";
	}else{
		cout << "NOT CONNECTED TO DATABASE\n";	
	}  
}

void Database::errorDectection(const char* q){
	string err = sqlite3_errmsg(db);

}

list<list<string> > Database::prepare(const char* q){
	list<list<string> > list_2D;
    list<string> l;

	if(SQLITE_OK == (sqlite3_prepare(db, q, -1, &s, NULL))){
		for(int i = 0; i <= list_2D.size(); i++){
			if(SQLITE_ROW == (sqlite3_step(s))){
				for(int j = 0; j < sqlite3_column_count(s); j++){
					l.push_back((char*)sqlite3_column_text(s, j));
				}
				list_2D.push_back(l);
			}else{
				cout<<"DONE"<<endl;   
			}
		}
		if(q != NULL){
			sqlite3_finalize(s);
		}
		
	}
	errorDectection(q);
	close();
	return list_2D;  
}


void Database::close(){
	sqlite3_close(db);   
}