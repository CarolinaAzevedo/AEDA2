/*
 * TheVoice.h
 *
 *  Created on: 16/11/2016
 *      Author: Carolina Azevedo, Daniela João & Eduarda Cunha
 */

#ifndef SRC_THEVOICE_H_
#define SRC_THEVOICE_H_

#include "Libraries.h"
#include "Person.h"
#include "Season.h"


class TheVoice
{
public:
	//*******************************DATA*********************************

	vector<Contestant*> contestants;
	vector<Mentor*> mentors;
	vector<Song*> songs;
	vector<Season> seasons;

	//***************************FUNCTIONS*********************************
	void newSeason();
	void showMentors();
	void MentorSuccess();


	//*******************************MENUS*********************************
	void startMenu();
	void FirstPhaseMenu();
	void SecondPhaseMenu();
	void ThirdPhaseMenu();
	void FinalPhaseMenu();
		



	//*******************************SAVES & LOADS ***************************

	void loadAll();

	void loadSongs();
	void loadContestants();
	void loadMentors();
	void loadSeasons();
	void saveSeasons();


	//************************************AUXILIAR***********

	bool inputCharCorrect(char c);
};


#endif /* SRC_THEVOICE_H_ */
