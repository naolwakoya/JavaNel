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

#ifndef DATA_H
#define DATA_H

#include <vector>

template <typename T>
class data {
public:
    int id;
    vector<T*> collection;
    int getID() const {
        return id;
    }
    typename vector<T*>::iterator findPosition(T &item) {
        for(typename vector<T*>::iterator it = collection.begin(); it != collection.end(); ++it)
            if (*it == &item) return it;
        return collection.end();
    }
};


#endif 
