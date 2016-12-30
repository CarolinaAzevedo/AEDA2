/*
 * Parte2.cpp
 *
 *  Created on: Dec 26, 2016
 *      Author: Carolina Azevedo, Daniela João & Eduarda Cunha
 */
#include "TheVoice.h"
#include "Season.h"
#include "BST.h"
#include "Person.h"

/////////////////////////////////////////////// BST ///////////////////////////////////////////////////

bool Contestant::operator < (const Contestant &c1) const {
     return classifications < c1.classifications;
}

bool Contestant::operator == (const Contestant &c1) const {
     return classifications == c1.classifications;
}

void Season::ContestantsBST(){

	for (unsigned int i = 0; i < contestants.size(); i++)
	{
		bstContestants.insert(*contestants.at(i));
	}
}

void Season::showContestantsOrdered(){

	bstContestants.printTree();
}

void Season::auxiliarBSTTeams()
{
	for (unsigned int i = 0; i < mentors[0]->getTeamBlind().size(); i++) {
		bstTeam0.insert(*mentors[0]->getTeamBattle().at(i));
	}

	for (unsigned int i = 0; i < mentors[1]->getTeamBlind().size(); i++) {
		bstTeam1.insert(*mentors[1]->getTeamBattle().at(i));
	}

	for (unsigned int i = 0; i < mentors[2]->getTeamBlind().size(); i++) {
		bstTeam2.insert(*mentors[2]->getTeamBattle().at(i));
	}

	for (unsigned int i = 0; i < mentors[3]->getTeamBlind().size(); i++) {
		bstTeam3.insert(*mentors[3]->getTeamBattle().at(i));
	}
}

void Season::showTeamsOrdered(){

	BSTItrIn<Contestant> it(bstTeam0);
	BSTItrIn<Contestant> it1(bstTeam1);
	BSTItrIn<Contestant> it2(bstTeam2);
	BSTItrIn<Contestant> it3(bstTeam3);

	cout << mentors.at(0)->getName() << "'s team:" << endl;
	while (!it.isAtEnd()) {
		cout << it.retrieve().getName() << endl;
		it.advance();
	}

	cout << endl;
	cout << mentors.at(1)->getName() << "'s team:" << endl;
	while (!it1.isAtEnd()) {
		cout << it1.retrieve().getName() << endl;
		it1.advance();
	}

	cout << endl;
	cout << mentors.at(2)->getName() << "'s team:" << endl;
	while (!it2.isAtEnd()) {
		cout << it2.retrieve().getName() << endl;
		it2.advance();
	}

	cout << endl;
	cout << mentors.at(3)->getName() << "'s team:" << endl;
	while (!it3.isAtEnd()) {
		cout << it3.retrieve().getName() << endl;
		it3.advance();
	}

	/*BSTItrIn<Contestant> it(bstContestants);
	BSTItrIn<Contestant> it1(bstContestants);
	BSTItrIn<Contestant> it2(bstContestants);
	BSTItrIn<Contestant> it3(bstContestants);

	cout << mentors.at(0)->getName() << "'s team:" << endl;
	while (!it.isAtEnd()) {
		for (unsigned int i = 0; i < mentors.at(0)->getTeamBlind().size; i++) {
			if (it.retrieve().getName() == mentors.at(0)->getTeamBlind().at(i)->getName()) {

			}
		}
		it.advance();
	}

	cout << endl;
	cout << mentors.at(1)->getName() << "'s team:" << endl;
	while (!it1.isAtEnd()) {
		for (unsigned int i = 0; i < mentors.at(1)->getTeamBlind().size; i++) {
			if (it1.retrieve().getName() == mentors.at(1)->getTeamBlind().at(i)->getName()) {
				cout << it1.retrieve().getName() << endl;
			}
		}
		it1.advance();
	}

	cout << endl;
	cout << mentors.at(2)->getName() << "'s team:" << endl;
	while (!it2.isAtEnd()) {
		for (unsigned int i = 0; i < mentors.at(2)->getTeamBlind().size; i++) {
			if (it2.retrieve().getName() == mentors.at(2)->getTeamBlind().at(i)->getName()) {
				cout << it2.retrieve().getName() << endl;
			}
		}
		it2.advance();
	}

	cout << endl;
	cout << mentors.at(3)->getName() << "'s team:" << endl;
	while (!it3.isAtEnd()) {
		for (unsigned int i = 0; i < mentors.at(3)->getTeamBlind().size; i++) {
			if (it3.retrieve().getName() == mentors.at(3)->getTeamBlind().at(i)->getName()) {
				cout << it3.retrieve().getName() << endl;
			}
		}
		it3.advance();
	}*/
}

void Season::showContestantScore(string contestantName){

	BSTItrIn<Contestant> it(bstContestants);
	Contestant notFound = Contestant("");
	Contestant c = Contestant(contestantName);

	if (bstContestants.find(c) == notFound)
	{
		cout << "The contestant whose score you are looking for doesn't exist on our data base!" << endl;
	} else {
		while(!it.isAtEnd())
		{
			if (it.retrieve() == c)
			{
				cout << it.retrieve().getName() << "'s score is ";
				cout << it.retrieve().getclassifications() << endl;
			}
			it.advance();
		}
	}
}

void Season::showMentorSuccessfulContestant(){

	vector<Contestant> mentorsSuccessfulContestants;
	unsigned int mentor = 0;

	mentorsSuccessfulContestants.push_back(bstTeam0.findMax());
	mentorsSuccessfulContestants.push_back(bstTeam1.findMax());
	mentorsSuccessfulContestants.push_back(bstTeam2.findMax());
	mentorsSuccessfulContestants.push_back(bstTeam3.findMax());

	for (unsigned int i = 0; i < mentorsSuccessfulContestants.size(); i++)
	{
		cout << mentors.at(mentor)->getName() << "'s most successful contestant is ";
		cout << mentorsSuccessfulContestants.at(i).getName() << "." << endl;
		mentor++;
	}
}

//////////////////////////////////////////// HASH TABLE ////////////////////////////////////////////////

void Season::Hash() {

	//CRIAR A HASH TABLE A PARTIR DE TODOS OS CONCORRENTES
	for (unsigned int i = 0; i < this->contestants.size(); i++) {
		this->nomes.insert(this->contestants.at(i));
	}



	//SE TIVEREM APENAS A STRING(NOME DE JOGADOR)
	string nome = winnerFinal->getName(); //O NOME DO JOGADOR
	Contestant c(nome);
	Contestant *pp = *(this->nomes.equal_range(&c)).first;

	//MUSICAS CANTADAS SÓ NUMA FASE
	int num = 1; //numero da fase
	cout << endl << " - " << nome << " - " << endl;
	cout << "Fase " << num << " - " << pp->getSongs().at(num - 1)->getName() << endl;

	//MUSICAS CANTADAS EM TODAS AS FASES
	for (unsigned int i = 0; i < pp->getSongs().size(); i++) {
		cout << "Fase " << i + 1 << " - " << pp->getSongs().at(i)->getName() << endl;
	}

}

void Season::addNome(Contestant *p) {
	this->nomes.insert(p);
}

void Season::addPlayer(Contestant *c) {
	cmpByName temp;
	temp.c = c;
	this->p_queue.push(temp);
}

void Season::printAll() {
	priority_queue<cmpByName> temp = this->p_queue;

	while (!temp.empty()) {
		cout << temp.top().c->getName() << endl;
		temp.pop();
	}
}

bool operator<(const cmpByName c1, const cmpByName c2) {
	return c1.c->getName() > c2.c->getName();
}
