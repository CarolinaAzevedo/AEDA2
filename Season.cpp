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
		cout << setw(18) << mentors.at(i)->getName() << endl;
	}
}

void Season::showContestants() {

	cout << setw(18) << " CONTESTANTS " << endl;
	cout << setw(18) << "__________________" << endl;
	for (unsigned int i = 0; i < contestants.size(); i++) {
		cout << setw(18) << contestants.at(i)->getName() << endl;
	}
}

Song* Season::teamBlind()
{
	bool batata = true;
	while (batata) {
		int r = rand() % 300;
		for (int i = 0; i < songsUsed.size(); i++)
		{
			if (songs.at(r) != songsUsed.at(i))
			{
				songsUsed.push_back(songs.at(r));
				batata = false;
			}
		}
	}
	return songsUsed.back();
}

//Esta função associa cada musica a um concorrente e associa cada concorrente a um mentor consoante ele vira o nao

void Season::addteamBlind() {
	int i = 0;

	while (i < 54) {
		vector<int> mentorsTurned;
		cout << contestants.at(i)->getName() << endl;
		cout << songsUsed.back()->getName() << " - " << songsUsed.back()->getArtist() << endl;
		char tmp;
		while (1) {
			if (mentors.at(0)->getTeamBlind().size < 15)
			{
				cout << "Mentor 1 turn your chair? (y/n)" << endl;

				
				if (inputCharCorrect('y'))
				{
					mentorsTurned.push_back(1);
				}
				else
				{
					mentorsTurned.push_back(0);

				}
			}
			else 
			{
				cout << "Mentor 1 team is full" << endl;
				mentorsTurned.push_back(0);
			}
			cout << "Mentor 2 turn your chair? (y/n)" << endl;
			cin >> tmp;
			if (tmp == 'y')
			{
				mentorsTurned.push_back(1);
			}
			else
			{
				mentorsTurned.push_back(0);

			}
			cout << "Mentor 3 turn your chair? (y/n)" << endl;
			cin >> tmp;
			if (tmp == 'y')
			{
				mentorsTurned.push_back(1);
			}
			else
			{
				mentorsTurned.push_back(0);

			}
			cout << "Mentor 4 turn your chair? (y/n)" << endl;
			char tmp;
			cin >> tmp;
			if (tmp == 'y')
			{
				mentorsTurned.push_back(1);
			}
			else
			{
				mentorsTurned.push_back(0);

			}
			if (mentorsTurned[0] + mentorsTurned[1] + mentorsTurned[2] + mentorsTurned[3] == 0)
			{
				cout << "I'm sorry mentors, someone has to turn for this contestant, lets go again" << endl;
			}
			else if (mentorsTurned[0] + mentorsTurned[1] + mentorsTurned[3] + mentorsTurned[2] == 1)
			{
				cout << "Congratulations contestant you go into ";
				if (mentorsTurned[0] == 1)
				{
					cout << mentors.at(0)->getName();
					mentors.at(0)->addTeamBlind(contestants.at(i));
				}
				else if (mentorsTurned[1] == 1)
				{
					cout << mentors.at(1)->getName();
					mentors.at(1)->addTeamBlind(contestants.at(i));
				}
				else if (mentorsTurned[2] == 1)
				{
					cout << mentors.at(2)->getName();
					mentors.at(2)->addTeamBlind(contestants.at(i));
				}
				else if (mentorsTurned[3] == 1)
				{
					cout << mentors.at(3)->getName();
					mentors.at(3)->addTeamBlind(contestants.at(i));
				}
				break;
			}
			else if (mentorsTurned[0] + mentorsTurned[1] + mentorsTurned[3] + mentorsTurned[2] >= 2)
			{
				while (true) {
					cout << "Contestant, please pick your new Coach : " << endl;
					if (mentorsTurned[0] == 1)
						cout << "Mentor 1 (Press A)    ";
					if (mentorsTurned[1] == 1)
						cout << "Mentor 2 (Press S)    ";
					if (mentorsTurned[2] == 1)
						cout << "Mentor 3 (Press D)    ";
					if (mentorsTurned[3] == 1)
						cout << "Mentor 4 (Press F)    ";

					cin >> tmp;
					if (tmp == 'a' && mentors.at(0)->getTeamBlind().size() < 15)
					{
						cout << "Congratulations Mentor 1, the contestant choose your team";
						mentors.at(0)->addTeamBlind(contestants.at(i));

					}
					else if (tmp == 's' && mentors.at(1)->getTeamBlind().size() < 15)
					{
						cout << "Congratulations Mentor 2, the contestant choose your team";
						mentors.at(1)->addTeamBlind(contestants.at(i));

					}
					else if (tmp == 'd' && mentors.at(2)->getTeamBlind().size() < 15)
					{
						cout << "Congratulations Mentor 3, the contestant choose your team";
						mentors.at(2)->addTeamBlind(contestants.at(i));

					}
					else if (tmp == 'f' && mentors.at(3)->getTeamBlind().size() < 15)
					{
						cout << "Congratulations Mentor 4, the contestant choose your team";
						mentors.at(3)->addTeamBlind(contestants.at(i));

					}
					else
					{
						cout << "Wrong button motherfucker" << endl;
					}
				}
			}

		}
		i++;
	}
	
	
}


bool Season::inputCharCorrect(char c)
{
	char tmp;
	while (1)
	{
		cin >> tmp;
		if (c == tmp)
		{
			return true;
		}
		else
		{
			cout << "Wrong input, try again" << endl;
		}
	}
}



