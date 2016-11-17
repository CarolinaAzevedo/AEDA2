/*
 * Season.h
 *
 *  Created on: 16/11/2016
 *      Author: cavac
 */

#ifndef SRC_SEASON_H_
#define SRC_SEASON_H_

#include "Libraries.h"
#include "Person.h"
#include "Song.h"

class Season
{
public:
	Season(vector<Mentor*> mentors, vector<Contestant*> contestants, vector<Song*> songs);
	vector<Mentor*> mentors;
	vector<Contestant*> contestants;
	vector<Song*> songs;

};



#endif /* SRC_SEASON_H_ */
