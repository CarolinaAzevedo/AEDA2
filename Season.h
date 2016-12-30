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
#include <unordered_set>
#include <queue>

struct cmpByName {
	Contestant *c;
};

bool operator<(const cmpByName c1, const cmpByName c2);

struct cmpContestants {
	int operator() (const Contestant *p1)  const {
		return 0;
	}

	bool operator() (const Contestant *p1, const Contestant *p2) const {
		return p1->getName() == p2->getName();
	}

};


class Season
{
public:
	/**
	 * @brief Construtor da classe Season
	 * @param mentors Vetor com mentores da temporada
	 * @param contestants Vetor com concorrentes da temporada
	 * @param songs Vetor com músicas da temporada
	 */
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
	Contestant * winnerFinal;
	vector<vector <int>> n_turned;

	BST<Contestant> bstContestants;
	BST<Contestant> bstTeam0;
	BST<Contestant> bstTeam1;
	BST<Contestant> bstTeam2;
	BST<Contestant> bstTeam3;

	priority_queue< cmpByName > p_queue;

	unordered_set<Contestant *, cmpContestants, cmpContestants> nomes;
	
	/**
	 * @brief Mostra na consola todos os mentores da temporada
	 */
	void showMentors();
	/**
	 * @brief Mostra na consola todos os concorrentes da temporada
	 */
	void showContestants();
	/**
	 * @brief Associa cada música a um concorrente na primeira fase e associa cada concorrente a um mentor consoante ele vira ou não a sua cadeira
	 */
	void addteamBlind();
	/**
	 * @brief Determina aleatoriamente músicas a ser usadas
	 */
	Song* SongsUsed();
	/**
	 * @brief Permite escolher os dois concorrentes que vão participar nas batalhas de um mentor
	 * @param a Determina o mentor em cuja equipa estamos a fazer escolhas
	 * @return Vetor que contem todos os pares
	 */
	vector<vector<Contestant *>> teamBattleFase(int a);
	/**
	 * @brief Escolhe 7 músicas para a fase de Batalha, a partir do vetor de músicas usadas
	 * @return Vetor com as 7 músicas
	 */
	vector<Song *> teamBattleSongs();
	/**
	 * @brief Mostra quem está a competir na fase de Batalha, que música está a cantar e o deixa o utilizador decidir quem ganha
	 */
	void BattleFase();
	/**
	 * @brief Mostra quem chegou à fase de Galas, a música que cantam, a média da pontuação dos mentores, público e final; Mostra ainda 5 melhores concorrentes de cada gala (2 galas)
	 */
	void showFase();
	/**
	 * @brief Mostra quem chegou à Final, a música que cantam, a pontuação dos mentores, público e final; Mostra também vencedor (concorrente com melhor pontuação nesta fase)
	 */
	void FinalFase();
	


	//************************************PARTE 2***********

/////////////////////////////////////////////// BST ///////////////////////////////////////////////////

	/**
	 * @brief Mete todos os concorrentes de uma temporada numa Binary Search Tree
	 */
	void ContestantsBST();

	/**
	 * @brief Mostra todos os concorrentes de uma temporada de acordo com as suas pontuações.
	 */
	void showContestantsOrdered();

	/**
	 * @brief Mostra as equipas de uma temporada de acordo com as suas pontuações.
	 */
	void showTeamsOrdered();

	/**
	 * @param contestantName Nome do concorrente cuja pontuação se quer saber.
	 * @brief Mostra as pontuações de um concorrente.
	 */
	void showContestantScore(string contestantName);

	/**
	 * @brief Mostra concorrente com mais sucesso de cada mentor.
	 */
	void showMentorSuccessfulContestant();

	/**
	 * @brief Mete concorrentes em BSTs separadas para as equipas dos 4 mentores.
	 */
	void auxiliarBSTTeams();

//////////////////////////////////////////// HASH TABLE ////////////////////////////////////////////////

	/**
	 * @brief Cria a tabela de dispersão das atuações (concorrentes e música associada).
	 */
	void Hash();

	void addNome(Contestant *p1);

	void addPlayer(Contestant *c);

	void printAll();
};



#endif /* SRC_SEASON_H_ */
