/*
 * Menus.cpp
 *
 *  Created on: 16/11/2016
 *      Author: Carolina Azevedo, Daniela João & Eduarda Cunha
 */

#ifndef SRC_MENUS_CPP_
#define SRC_MENUS_CPP_

#include "TheVoice.h"


void TheVoice::startMenu()
{

	newSeason();
	seasons.at(0).addteamBlind();
}

void Menu()
{
	unsigned int option;

	cout << "Hello and Welcome to The Voice's records" << endl;
	cout << "As a member of the general public, you can access statistics and details on previous editions.";
	cout << endl << "Which option do you want to consult?"<< endl;

	cout << "1 - Who were the mentors?" << endl;
	cout << "2 - Who were the contestants?" << endl;
	cout << "3 - Who won?";

	//AvailableInfo();
}

int chooseSeason()
{
	unsigned int season;

	cout << "Which season?" << endl;
	cin >> season;

	while (cin.fail())
	{
		cout << "Error! You can type digits only! Try again." << endl;
		cout << "Type in option again: ";
		cin >> season;
	}

	while (season != 1) //mudar condicao para x temporadas +1
	{
		cout << "Error! The option you've selected isn't available.";
		cout << endl << "You must press 1, 2 or 3! Try again." << endl;
		cin >> season;
	}

	return season;
}

void AvailableInfo()
{
	unsigned int option;

	cin >> option;

	while (cin.fail())
	{
		cout << "Error! You can type digits only! Try again." << endl;
		cout << "Type in option again: ";
		cin >> option;

	}

	while (option != 1 && option != 2 && option != 3)
	{
		cout << "Error! The option you've selected isn't available.";
		cout << endl << "You must press 1, 2 or 3! Try again." << endl;
		cin >> option;
	}


	switch(option)
	{
	case 1: //mentores
		chooseSeason();

		cout << "Which option do you want to consult?" << endl;

		cout << "1 - What was their team?" << endl;
		cout << "2 - Which was the most successful mentor?" << endl;

		cout << "3 - Return to starting menu.";

		break;

	case 2: //concorrentes
		chooseSeason();

		cout << "Which option do you want to consult?"<< endl;

		cout << "1 - Which songs were sung?" << endl;
		cout << "2 - Which chairs were turned?" << endl;
		cout << "3 - In which season were they eliminated?" << endl;

		cout << "4 - Return to starting menu.";
		break;

	case 3: //vencedores
		chooseSeason();

		break;
	}
}

void menuMentors()
{
	unsigned int option;
	cin >> option;

	while (cin.fail())
	{
		cout << "Error! You can type digits only! Try again." << endl;
		cout << "Type in option again: ";
		cin >> option;
	}

	while (option != 1 && option != 2 && option != 3) {
		cout << "Error! The option you've selected isn't available.";
		cout << endl << "You must press 1, 2 or 3! Try again." << endl;
		cin >> option;
	}

	switch (option) {
	case 1: //equipas
		chooseSeason();

		break;
	case 2: //mais bem sucedido

		break;
	case 3:
		Menu();
		break;
	}
}

void menuContestants()
{
	unsigned int option;
	cin >> option;

	while (cin.fail())
	{
		cout << "Error! You can type digits only! Try again." << endl;
		cout << "Type in option again: ";
		cin >> option;
	}

	while (option != 1 && option != 2 && option != 3 && option != 4) {
		cout << "Error! The option you've selected isn't available.";
		cout << endl << "You must press 1, 2, 3 or 4! Try again." << endl;
		cin >> option;
	}

	switch (option) {
	case 1: //musicas
		chooseSeason();

		break;
	case 2: //cadeiras que virou
		chooseSeason();

		break;
	case 3: //etapa em que foi eliminado
		chooseSeason();

		break;
	case 4:
		Menu();
		break;
	}
}

#endif /* SRC_MENUS_CPP_ */
