#include <iostream>
#include <string>
#include <vector>
#include "Libraries.h"
#include "TheVoice.h"
#include <ctime>

TheVoice programa;
int main()
{
	cout << "  _____ _            _   _       _" << endl;
	cout << " |_   _| |          | | | |     (_)" << endl;
	cout << "   | | | |__   ___  | | | | ___  _  ___ ___" << endl;
	cout << "   | | |  _ \ / _ \ | | | |/ _ \| |/ __/ _ \ " << endl;
	cout << "   | | | | | |  __/ \ \_/ / (_) | | (_|  __/" << endl;
	cout << "   \_/ |_| |_|\___|  \___/ \___/|_|\___\___|" << endl;
	cout << "The Voice is a competition which intends to find the best unknown voices in the country!" << endl;
	cout << "Four famous personalities search for the best voices and will mentor singers into becoming artists." << endl;

	srand((unsigned int)time(NULL));
	programa.loadAll();
	programa.startMenu();

	//começa a consulta de informação
	cout << "Now that all the seasons have been created, you can consult information about them." << endl;
	menuConsulta();

	cout << "Wait on for the next season \n Auditions will begin next Summer" << endl;
	cout << "All you have to do is register as an Artist Account at www.nbcthevoice.com and the following steps will be provided.";
	cout << endl << endl << endl;
	cout << "Executive Producers \n Carolina Azevedo, Daniela Joao and Eduarda Cunha" << endl;
	cout << endl << "Supervising Producers \n Ana Paula Rocha, Henrique Lopes Cardoso and Rosaldo Rossetti" << endl;
	char option;

	system("pause");
	return 0;
}

void menuConsulta()
{
	unsigned int option, season, option1;

	cout << "1 - All seasons." << endl;
	cout << "2 - Specific seasons." << endl;

	cin >> option;

	while (cin.fail() || (option != 1 && option != 2)) {
		cout << "You can only type in the unsigned integer numbers 1 and 2. Try again." << endl;
		cin >> option;
	}

	switch(option)
	{
	case 1:
		menuAllSeasons();
		break;
	case 2:

		cout << "Which season do you want to consult?";
		cin >> season;

		while (cin.fail() || (season > programa.seasons.size())) {
			cout << "You can only type in the unsigned integer numbers relating to each season created. Try again." << endl;
			cin >> season;
		}

		menuSpecificSeason(season);
		break;
	}
}

void menuAllSeasons()
{
	unsigned int option;

	cout << "1 - Show all performances' list." << endl;
	cout << "2 - Go back to start menu." << endl;
	cin >> option;

	while (cin.fail() || (option > 5)) {
		cout << "You can only type in the unsigned integer numbers 1 and 2. Try again." << endl;
		cin >> option;
	}

	switch(option)
	{
	case 1: //DANIELAECAROLINA
		break;
	case 2:
		menuConsulta();
		break;
	}
}

void menuSpecificSeason(unsigned int season)
{
	unsigned int option;
	string name;

	programa.seasons[season - 1].auxiliarBSTTeams();

	cout << "1 - Show performances' list for season " << season << "." << endl;
	cout << "2 - Show contestants' list for season " << season << ", in order according to their scores." << endl;
	cout << "3 - Show teams for season " << season << ", in order according to their scores." << endl;
	cout << "4 - Show mentors for season " << season << "." << endl;
	cout << "5 - Show contestant's scores." << endl;
	cout << "6 - Show most successful contestant for each mentor." << endl;
	cout << "7 - Go back to start menu." << endl;
	cin >> option;

	while (cin.fail() || (option > 8)) {
		cout << "You can only type in the unsigned integer numbers 1 to 7. Try again." << endl;
		cin >> option;
	}

	switch(option)
	{
	case 1://DANIELAECAROLINA
		break;
	case 2:
		programa.seasons[season - 1].showContestantsOrdered();
		break;
	case 3:
		programa.seasons[season - 1].showTeamsOrdered();
		break;
	case 4:
		programa.seasons[season - 1].showMentors();
		break;
	case 5:
		cout << "Which contestant's score do you wish to know?" << endl;
		cin >> name;

		while (cin.fail()) {
			cout << "You can only type in strings. Try again." << endl;
			cin >> name;
		}

		programa.seasons[season - 1].showContestantScore(name);
		break;
	case 6:
		programa.seasons[season - 1].showMentorSuccessfulContestant();
		break;
	case 7:
		menuConsulta();
		break;
	}
}

