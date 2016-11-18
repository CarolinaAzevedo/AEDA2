/*
 * Season.h
 *
 *  Created on: 16/11/2016
 *      Author: Carolina Azevedo, Daniela João & Eduarda Cunha
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
	vector<Song *> songsUsed;
	void showMentors();
	void showContestants();
	void showSongs();
	void addteamBlind();
	Song* teamBlind();
	bool inputCharCorrect(char c);

};



#endif /* SRC_SEASON_H_ */
