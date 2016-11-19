/*
 * Person.h
 *
 *  Created on: 16/11/2016
 *      Author: Carolina Azevedo, Daniela João & Eduarda Cunha
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
	string getName();
};

class Contestant: public Person {
	vector<Song*> songs;
	float classifications;

public:
	Contestant(string name);
	vector<Song*> getSongs();
	void setclassifications(float a);
	float getclassifications();
};

class Mentor: public Person { //o valor das equipas � passado por apontador para n�o criar copias da mesma informa��o
	vector<Contestant*> teamBlind; //equipa na fase cega
	vector<Contestant*> teamBattle; //equipa na fase de batalha
	vector<Contestant*> teamFinal; //quem ta final do mentor
	vector<Contestant*> winner; //quem ganhou a final 
	

public:
	Mentor(string name);
	vector<Contestant*> getTeamBlind() {return teamBlind;}
	vector<Contestant*> getTeamBattle() {return teamBattle;}
	vector<Contestant*> getTeamFinal() { return teamFinal; }
	vector<Contestant*> getWinner() { return winner; }

	void addTeamBlind(Contestant *c);
	void addTeamBattle(Contestant *c);
	void addTeamFinal(Contestant *c);
	void setFinal(Contestant *c);

};




#endif /* SRC_PERSON_H_ */
