/*
 * TheVoice.h
 *
 *  Created on: 16/11/2016
 *      Author: Carolina Azevedo, Daniela João & Eduarda Cunha
 */

#ifndef THEVOICE_H
#define THEVOICE_H

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
	/**
	 * @brief Gera a temporada em si
	 */
	void newSeason();
	void showMentors();
	void MentorSuccess();


	//*******************************MENUS*********************************
	/**
	 * @brief Menu que permite ao utilizador escolher quantas temporadas quer simular e as cria.
	 */
	void startMenu();
	/**
	 * @brief Menu que permite ao utilizador saber mais sobre as Provas Cegas (1ª Fase).
	 */
	void BlindAuditionsMenu();
	/**
	 * @brief Menu que permite ao utilizador saber mais sobre a Ronda de Batalhas (2ª Fase).
	 */
	void BattleRoundsMenu();
	/**
	 * @brief Menu que permite ao utilizador saber mais sobre as Galas (3ª Fase).
	 */
	void GalasMenu();
	/**
	 * @brief Menu que permite ao utilizador saber mais sobre a Final.
	 */
	void FinalPhaseMenu();

	//*******************************SAVES & LOADS ***************************
	/**
	 * @brief Faz com que todos os loads se efetuem
	 */
	void loadAll();
	/**
	 * @brief Mete num vetor todas as músicas disponíveis no documento songs.txt
	 */
	void loadSongs();
	/**
	 * @brief Mete num vetor todos os concorrentes disponíveis no documento contestants.txt
	 */
	void loadContestants();
	/**
	 * @brief Mete num vetor todos os mentores disponíveis no documento mentors.txt
	 */
	void loadMentors();
};


#endif /* SRC_THEVOICE_H_ */
