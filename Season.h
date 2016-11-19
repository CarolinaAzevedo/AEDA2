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
	vector<Song*> songsUsed;
	
	vector<vector <int>> n_turned;
	void showMentors();
	void showContestants();
	void showSongs();
	void addteamBlind();
	Song* SongsUsed();
	bool inputCharCorrect(char c);
	vector<vector<Contestant *>> teamBattleFase(int a);
	vector<Song *> teamBattleSongs();
	void BattleFase();
	
};



#endif /* SRC_SEASON_H_ */
