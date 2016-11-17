/*
 * Person.h
 *
 *  Created on: 16/11/2016
 *      Author: cavac
 */

#ifndef SRC_PERSON_H_
#define SRC_PERSON_H_

#include "Libraries.h"
#include "Song.h"

class Person {
protected:
	string name;

public:
	~Person();
	Person(string name);
	string getName() {return name;}
};

class Contestant: public Person {
	vector<Song*> songs;
	vector<float> classifications;

public:
	Contestant(string name);
	vector<Song*> getSongs();
};

class Mentor: public Person { //o valor das equipas é passado por apontador para não criar copias da mesma informação
	vector<Contestant*> teamBlind; //equipa na fase cega
	vector<Contestant*> teamBattle; //equipa na fase de batalha
	vector<Contestant*> teamGala; //equipa na fase cega

public:
	Mentor(string name);
	vector<Contestant*> getTeamBlind() {return teamBlind;}
	vector<Contestant*> getTeamBattle() {return teamBattle;}
	vector<Contestant*> getTeamGala() {return teamGala;}
};




#endif /* SRC_PERSON_H_ */
