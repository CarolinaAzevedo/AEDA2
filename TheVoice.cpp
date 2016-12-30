 /*
 * TheVoice.cpp
 *
 *  Created on: 16/11/2016
 *      Author: Carolina Azevedo, Daniela João & Eduarda Cunha
 */
#include "TheVoice.h"

void TheVoice::newSeason()
{

	vector<int> tmp;
	vector<Mentor *> mentorsTmp;
	vector<Contestant *> contestantsTmp;
	vector<Contestant *> teamBlindTmp;
	vector<Song*> songsTmp;
	bool random = true;

	//Load dos concorrentes para o vetor

	for(int i = 0; i < 56; i++)
	{
		while(1)
		{
			int r = rand() %199;
			random = true;
			for (int j = 0; j < tmp.size(); j++)
			{
				if(r == tmp[j])
				{
					random = false;
				}
			}
			if(random)
			{
				tmp.push_back(r);
				break;
			}

		}
	}
	for(unsigned int i = 0; i < tmp.size(); i++)
	{
		contestantsTmp.push_back(contestants[tmp[i]]);
	}
	tmp.clear();


	// Load dos mentores para o vetor
	for(int i = 0; i < 4; i++)
	{
		while(1)
		{
			int r = rand() %9;
			random = true;
			for(int j = 0; j < tmp.size(); j++)
			{
				if(r == tmp[j])
				{
					random = false;
				}
			}
			if(random)
			{
				tmp.push_back(r);
				break;
			}
		}
	}
	for(unsigned int i = 0; i < tmp.size(); i++)
	{
		mentorsTmp.push_back(mentors[tmp[i]]);
	}

	Season a1 (mentorsTmp, contestantsTmp, songs);
	seasons.push_back(a1);
}

void TheVoice::startMenu()
{
	unsigned int nSeasons;

	cout << "Here, we give you the opportunity to simulate seasons!!" << endl << "How many seasons do you want to simulate? " << endl;
	cin >> nSeasons;

	while (cin.fail())
	{
		cout << "You can only type in integer numbers. Try again." << endl;
		cin >> nSeasons;
	}

	for (int i = 0; i < nSeasons; i++)
	{
		newSeason();
		BlindAuditionsMenu();
		seasons.at(i).addteamBlind();
		BattleRoundsMenu();
		seasons.at(i).BattleFase();
		GalasMenu();
		seasons.at(i).showFase();
		FinalPhaseMenu();
		seasons.at(i).FinalFase();
	}
}

void TheVoice::BlindAuditionsMenu()
{
	char choice;
	cout << "Be ready for the FIRST PHASE - The Blind Auditions!" << endl;
	cout << "Do you know what The Blind Auditions are? (y/n)" << endl;
	cin >> choice;

	while (cin.fail() || (choice != 'y' && choice != 'n'))
	{
		cout << "You can only type in the chars 'y' for yes and 'n' for no. Try again." << endl;
		cin >> choice;
	}

	if (choice == 'n') {
		cout << "The contestant performs a song, while the mentors, with their backs turned, " << endl;
		cout << "consider whether or not the vocal talent of the contestant is enough to get them a place on their team.";
		cout << endl << "If the mentor wants the contestant to be on his team,  " << endl;
		cout << "he presses the button, which makes the chair rotate." << endl;
		cout << "If  more than one mentor rotate their chair, it is up to the contestant to choose the team he prefers." << endl;
		cout << endl << "The Blind Auditions are now starting..." << endl;
	}
	else
	{
		cout << "The Blind Auditions are now starting..." << endl;
	}
}

void TheVoice::BattleRoundsMenu()
{
	char choice;
	cout << "Be ready for the SECOND PHASE - The Battle Rounds!" << endl << endl;
	cout << "Do you know what The Battle Rounds are? (y/n)" << endl;
	cin >> choice;

	while (cin.fail() || (choice != 'y' && choice != 'n'))
	{
		cout << "You can only type in the chars 'y' for yes and 'n' for no. Try again." << endl;
		cin >> choice;
	}

	if (choice == 'n')
	{
		cout << "Two contestants of the same team are chosen by their mentor to"<< endl;
		cout << "compete against each other.. It's a real battle ring!!!" << endl;
		cout << "At the end of the assignment, it is the mentor who must" << endl;
		cout << "decide which of the two stays in the show." << endl;
		cout << endl << "The Battle Rounds are now starting..." << endl;
	}
	else {

		cout << "The Battle Rounds are now starting..." << endl;
	}
}

void TheVoice::GalasMenu()
{
	char choice;
	cout << "Be ready for the THIRD PHASE - The Galas" << endl << endl;
	cout << "Do you know what The Galas are? (y/n)" << endl;
	cin >> choice;

	while (cin.fail() || (choice != 'y' && choice != 'n'))
	{
		cout << "You can only type in the chars 'y' for yes and 'n' for no. Try again." << endl;
		cin >> choice;
	}

	if (choice == 'n')
	{
		cout << "In this phase, there are 28 contestants, who must compete against each other in 2 galas. " << endl;
		cout << "In each gala only five contestants must win.";
		cout << "It is up to the audience's vote to decide who is still in the show and who goes home." << endl;
		cout << endl << "The first Gala is now starting..." << endl;
	}
	else {

		cout << "The first Gala is now starting..." << endl;
	}
}

void TheVoice::FinalPhaseMenu()
{
	char choice;
	cout << "Be ready for the FINAL PHASE - The Finals" << endl << endl;
	cout << "Do you know what The Final Gala is? (y/n)" << endl;
	cin >> choice;

	while (cin.fail() || (choice != 'y' && choice != 'n'))
	{
		cout << "You can only type in the chars 'y' for yes and 'n' for no. Try again."	<< endl;
		cin >> choice;
	}

	if (choice == 'n')
	{
		cout << "The 10 contestants, 5 from each of the previous galas, show their skills in one final episode." << endl;
		cout << "Only ONE can be the winner and the choice is equally up to the votes of the " << endl;
		cout << endl << "audience and mentors. " << endl;
		cout << endl << "The Final Gala is now starting..." << endl;
	}
	else {

		cout << "The Final Gala is now starting..." << endl;
	}
}

void TheVoice::MentorSuccess() {


	vector<Contestant *> winners1 = mentors.at(0)->getWinner();
	vector<Contestant *> winners2 = mentors.at(1)->getWinner();
	vector<Contestant *> winners3 = mentors.at(2)->getWinner();
	vector<Contestant *> winners4 = mentors.at(3)->getWinner();
	vector <int> tmp;
	vector<int> tmpO;


	tmp.push_back(winners1.size());
	tmp.push_back(winners2.size());
	tmp.push_back(winners3.size());
	tmp.push_back(winners4.size());

	tmpO = tmp;

	sort(tmpO.begin(), tmpO.end());

	for (int i = 0; i < tmp.size(); i++)
		if (tmp.at(i) == tmpO.back()) {
			cout << " The most successful mentor is: " << mentors.at(i)->getName() << endl;
		}
}
