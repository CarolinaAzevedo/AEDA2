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
		if (songsUsed.size() == 0)
		{
			songsUsed.push_back(songs.at(r));
		}
		else {
			for (int i = 0; i < songsUsed.size(); i++)
			{
				if (songs.at(r) != songsUsed.at(i))
				{
					songsUsed.push_back(songs.at(r));
					batata = false;
				}
			}
		}
	}
	return songsUsed.back();
}

//Esta função associa cada musica a um concorrente e associa cada concorrente a um mentor consoante ele vira o nao

void Season::addteamBlind() {
	int i = 0;

	while (i < 54) {
		cout <<endl <<  "Contestant: " << contestants.at(i)->getName() << endl;
		teamBlind();
		cout << songsUsed.back()->getName() << " - " << songsUsed.back()->getArtist() << endl;
		char tmp;
		

		while (1) {
			vector<int> mentorsTurned;
			if (mentors.at(0)->getTeamBlind().size() < 15)
			{
				cout << mentors.at(0)->getName() << ", do you want to turn your chair? (y/n)" << endl;
				cin >> tmp;
				if (tmp == 'y')
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
				cout << mentors.at(0)->getName() <<"'s team is full" << endl;
				mentorsTurned.push_back(0);
			}

			if (mentors.at(1)->getTeamBlind().size() < 15)
			{
				cout << mentors.at(1)->getName()<< ", do you want to turn your chair? (y/n)" << endl;
				
				cin.clear();
				cin >> tmp;
				if (tmp == 'y')
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
				cout << mentors.at(1)->getName() << "'s team is full" << endl;
				mentorsTurned.push_back(0);
			}

			if (mentors.at(2)->getTeamBlind().size() < 15) {


				cout << mentors.at(2)->getName()<< ", do you want to  turn your chair? (y/n)" << endl;
				cin.clear();
				cin >> tmp;
				if (tmp == 'y')
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
				cout << mentors.at(2)->getName() <<"'s  team is full" << endl;
				mentorsTurned.push_back(0);
			}
			if (mentors.at(3)->getTeamBlind().size() < 15) {

				cout << mentors.at(3)->getName()<< ", do you want to turn your chair? (y/n)" << endl;
				char tmp;
				cin.clear();
				cin >> tmp;
				if (tmp == 'y')
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
				cout << mentors.at(3)->getName() << "'s team is full" << endl;
				mentorsTurned.push_back(0);
			}


			if (mentorsTurned[0] + mentorsTurned[1] + mentorsTurned[2] + mentorsTurned[3] == 0)
			{
				cout << "Are you sure? This contestant is really good! Give" << contestants.at(i)->getName() << "another shot" << endl;
				mentorsTurned.clear();
			}
			else if (mentorsTurned[0] + mentorsTurned[1] + mentorsTurned[3] + mentorsTurned[2] == 1)
			{
				cout << "Congratulations contestant you go into ";
				if (mentorsTurned[0] == 1)
				{
					cout << mentors.at(0)->getName() << endl;
					mentors.at(0)->addTeamBlind(contestants.at(i));
				}
				else if (mentorsTurned[1] == 1)
				{
					cout << mentors.at(1)->getName() << endl;
					mentors.at(1)->addTeamBlind(contestants.at(i));
				}
				else if (mentorsTurned[2] == 1)
				{
					cout << mentors.at(2)->getName() << endl;
					mentors.at(2)->addTeamBlind(contestants.at(i));
				}
				else if (mentorsTurned[3] == 1)
				{
					cout << mentors.at(3)->getName() << endl;
					mentors.at(3)->addTeamBlind(contestants.at(i));
				}
				break;
			}
			else if (mentorsTurned[0] + mentorsTurned[1] + mentorsTurned[3] + mentorsTurned[2] >= 2)
			{
				while (true) {
					cout << "Contestant, please pick your new Coach : " << endl;
					if (mentorsTurned[0] == 1)
						cout << mentors.at(0)->getName() << endl <<  "Press a " << endl;
					if (mentorsTurned[1] == 1)
						cout << mentors.at(1)->getName() << endl <<  "Press b"  << endl;
					if (mentorsTurned[2] == 1)
						cout << mentors.at(2)->getName() << endl << "Press c"   << endl;
					if (mentorsTurned[3] == 1)
						cout << mentors.at(3)->getName() << endl << "Press d" << endl;

					cin.clear();
					cin >> tmp;
					if (tmp == 'a' && mentors.at(0)->getTeamBlind().size() < 15)
					{
						cout << "Congratulations " << mentors.at(0)->getName() << ", the contestant choose your team" << endl;
						mentors.at(0)->addTeamBlind(contestants.at(i));
						break;

					}
					else if (tmp == 'b' && mentors.at(1)->getTeamBlind().size() < 15)
					{
						cout << "Congratulations " << mentors.at(1)->getName() << ", the contestant choose your team" << endl;;
						mentors.at(1)->addTeamBlind(contestants.at(i));
						break;

					}
					else if (tmp == 'c' && mentors.at(2)->getTeamBlind().size() < 15)
					{
						cout << "Congratulations " << mentors.at(2)->getName()<< ", the contestant choose your team"<< endl;
						mentors.at(2)->addTeamBlind(contestants.at(i));
						break;

					}
					else if (tmp == 'd' && mentors.at(3)->getTeamBlind().size() < 15)
					{
						cout << "Congratulations " << mentors.at(3)->getName() << ", the contestant choose your team" << endl;
						mentors.at(3)->addTeamBlind(contestants.at(i));
						break;

					}
					else
					{
						cout << "Wrong button, try again" << endl;
					}
				}
				break;
			}

			n_turned.push_back(mentorsTurned);
		}

		
		i++;
	}
	
	
}
/*
void Season::teamBatlleFase() {
	vector<int> tmp;
	bool random;
	vector <vector <Contestant *>> battles;
	vector<Contestant *> teamblind;
	for (int k = 0; k < mentors.size(); k++) {

		for (int j = 0; j < 2; j++) {
			while (1) {

				int r = rand() % 1;
				random = true;

				for (int i = 0; i <= tmp.size(); i++) {
					if (r == tmp[i]) {
						random = false;
					}
				}
				if (random) {
					tmp.push_back(r);
					break;
				}
			}
		}
		for (unsigned int i = 0; i < 7; i++) {

			battles[i].push_back(mentors.at(k)->getTeamBlind().at(tmp[i*2]));
			battles[i].push_back(mentors.at(k)->getTeamBlind().at(tmp[i*2+1]));


		}
	}
}
*/
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



