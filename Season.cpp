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

