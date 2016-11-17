/*
 * Menus.cpp
 *
 *  Created on: 16/11/2016
 *      Author: cavac
 */

#ifndef SRC_MENUS_CPP_
#define SRC_MENUS_CPP_

#include "TheVoice.h"


void TheVoice::startMenu()
{

	for(unsigned int i = 0; i < contestants.size();i++)
	{
		string tmp = contestants[i]->getName();
		cout << tmp << endl;
	}
	for(unsigned int i = 0; i < mentors.size(); i++)
	{
		cout << mentors[i]->getName() << endl;
	}
	string a;
	cin >> a;
}

void Menu()
{
	unsigned int option;

	cout << "Hello and Welcome to The Voice's records" << endl;
	cout << "As a member of the general public, you can access statistics and details on previous editions.";
	cout << endl << "Which option do you want to consult?"<< endl;
	cout << "1 - Who were the mentors?" << endl;
	cout << "2 - Who were the contestants?" << endl;
	cout << "3 - What songs were covered?" << endl;
	cout << "4 - Who won?" << endl;
	cout << "5 - Which mentor was the most successful?" << endl;
	cout << "6 - Return to the login menu." << endl;

	AvailableInfo();
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

	while (option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 6)
	{
		cout << "Error! The option you've selected isn't available.";
		cout << endl << "You must press 1, 2, 3, 4, 5 or 6! Try again." << endl;
		cin >> option;
	}


	switch(option)
	{
	case 1: //mentores
		chooseSeason();

		break;

	case 2: //concorrentes
		chooseSeason();

		break;

	case 3: //musicas
		chooseSeason();

		break;

	case 4: //quem venceu
		chooseSeason();

		break;

	case 5: //mentor com mais sucesso
		chooseSeason();

		break;

	case 6: //Return to the login menu
		Menu();
		break;
	}

	/*para cada edição do concurso:
	 * que cadeiras de mentores conseguiram virar,
	 * quem foram os elementos de cada equipa
	 * em que etapa foram eliminados,
	 * que pontuações obtiveram do público*/
}

#endif /* SRC_MENUS_CPP_ */
