/*
 * Season.cpp
 *
 *  Created on: 16/11/2016
 *      Author: Carolina Azevedo, Daniela João & Eduarda Cunha
 */

#include "Season.h"
#include <iomanip>



Season::Season(vector<Mentor*> mentors, vector<Contestant*> contestants, vector<Song*> songs){

	this->mentors = mentors;
	this->contestants = contestants;
	this->songs = songs;
}

void Season::showMentors() {

	cout << setw(18) << " MENTORS " << endl;
	cout << setw(18) << "__________________" << endl;
	for (unsigned int i = 0; i < mentors.size(); i++) {
		cout << setw(18) << mentors.at(i)->getName << endl;
	}
}

void Season::showContestants() {

	cout << setw(18) << " CONTESTANTS " << endl;
	cout << setw(18) << "__________________" << endl;
	for (unsigned int i = 0; i < contestants.size(); i++) {
		cout << setw(18) << contestants.at(i)->getName() << endl;
	}
}

void Season::addteamBlind(vector<Contestant*> contestants, vector<Mentor*> mentors) {
	bool random = true;
	vector<Contestant*> teamBlindTmp;
	vector<int>tmp;
	vector<Contestant*> contestantscopy = contestants;



	for (int k = 0; k < mentors.size(); k++)
	{
		for (int i = 0; i < contestantscopy.size(); i++) {
			while (1) {
				int r = rand() % 13;
				random = true;
				for (int j = 0; j < tmp.size(); j++) {
					if (r == tmp[j]) {
						random = false;
					}
					if (random) {
						tmp.push_back(r);
						break;
					}

				}
			}
		}
		for (unsigned int i = 0; i < tmp.size(); i++) {
			teamBlindTmp.push_back(contestantscopy[tmp[i]]);
			contestantscopy.erase(contestantscopy.begin() + tmp[i]);
		}

		//mentors[k].getTeamBlind()->teamBlindTmp;
	}
}



