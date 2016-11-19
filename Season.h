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
	vector<Song *> songsgala;
	vector<Contestant *> gala1;
	vector<Contestant *> gala2;
	vector<Contestant *> winners;
	vector<Contestant *> winners2;
	
	vector<vector <int>> n_turned;
	void showMentors();
	void showContestants();
	void addteamBlind();
	Song* SongsUsed();
	vector<vector<Contestant *>> teamBattleFase(int a);
	vector<Song *> teamBattleSongs();
	void BattleFase();
	void showFase();
	void FinalFase();
	
};



#endif /* SRC_SEASON_H_ */
