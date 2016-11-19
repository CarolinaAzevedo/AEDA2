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

Song* Season::SongsUsed()
{
	int r = rand() % songs.size();
	songsUsed.push_back(songs.at(r));
	songs.erase(songs.begin() + r);
	return songsUsed.back();
}

//Esta função associa cada musica a um concorrente e associa cada concorrente a um mentor consoante ele vira o nao

void Season::addteamBlind() {
	int i = 0;
	for (int i = 0; i < 56; i++)
	{
		if (i < 14)
		{
			mentors.at(0)->addTeamBlind(contestants.at(i));
		}
		else if (i < 28)
		{
			mentors.at(1)->addTeamBlind(contestants.at(i));
		}
		else if (i < 42)
		{
			mentors.at(2)->addTeamBlind(contestants.at(i));
		}
		else
		{
			mentors.at(3)->addTeamBlind(contestants.at(i));
		}
	}
	/*
	while (i < 56) {
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
	
	*/
}


//Esta função permite escolher os dois concorrentes que vao participar nas batalhas de um mentor, criando um vetor que contem todos os pares.

vector<vector<Contestant *>> Season::teamBattleFase(int a) {

	vector<Contestant *> tmp = mentors.at(a)->getTeamBlind();
	vector<vector<Contestant *>> battle;

	int option1, option2;

	while (1) {
		if (tmp.size() == 0)
			break;
		for (int i = 0; i < tmp.size(); i++)
		{
			cout << i + 1 << " : " << tmp.at(i)->getName() << endl;
		}

		while (1)
		{
			cout << "Please choose contestant 1 for the battle:" << endl;
			cin.clear();
			while (!(cin >> option1))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Not a number, try again" << endl;
			}
			option1--;
			cout << "Please choose contestant 2 for the battle:" << endl;
			cin.clear();
			while (!(cin >> option2))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Not a number, try again" << endl;
			}
			option2--;

			if (option1 < (tmp.size() )) {

				if  (option2 < (tmp.size() )) {

				if (option1 != option2) {

					break;
				}
			}
			}

		
				cout << endl << "Failed options, try again " << endl;
			}
		

		if (option1 != option2 && option1 < tmp.size() && option2 < tmp.size()) {

			vector<Contestant *> btmp;
			btmp.push_back(tmp.at(option1));
			btmp.push_back(tmp.at(option2));
			if (option1 < option2) {

				tmp.erase(tmp.begin() + option2);
				tmp.erase(tmp.begin() + option1);


			}
			else {
				tmp.erase(tmp.begin() + option1);
				tmp.erase(tmp.begin() + option2);
			}

			battle.push_back(btmp);
		}

	}
	return battle;
}


vector<Song *> Season::teamBattleSongs()
{
	vector<Song *> tmp;
	for (int i = 0; i < 7; i++)
	{
		tmp.push_back(SongsUsed());
	}
	return tmp;
}

void Season::BattleFase()
{
	vector<Song *> mentor1, mentor2, mentor3, mentor4;
	vector<vector<Contestant *>> mentor1b, mentor2b, mentor3b, mentor4b;
	vector<int> option;
	while (1) {
		int a;
		bool valido = true;
		cout << "Que mentor quer usar para as batalhas? " << endl;
		while (!(cin >> a))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Not a number, try again" << endl;
		}
		cout << a << endl;
		if (a < 0 && a > 4)
			valido = false;
		for (int i = 0; i < option.size(); i++)
		{
			if (a == option[i])
				valido = false;
		}
		if (valido)
		{
			option.push_back(a);
			switch (a) {
			case 1:
				mentor1b = teamBattleFase(0);
				mentor1 = teamBattleSongs();

				cout << mentors.at(0)->getName() << "'s Battles " << endl;
				for (int i = 0; i < mentor1.size(); i++)
				{
					int b;
					cout << "1-" << mentor1b.at(i).at(0)->getName() << " VS " << "2- " << mentor1b.at(i).at(1)->getName() << endl;
					cout << "Singing: " << endl << mentor1.at(i)->getName() << " - " << mentor1.at(i)->getArtist() << endl;
					cout << "Who wins? (1/2)" << endl;
					while (1)
					{
						while (!(cin >> b))
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Not a number, try again" << endl;
						}
						if (b != 1 && b != 2) {
							cout << "Wrong option, try again" << endl;
							cin.clear();
						}
						else {
							break;
						}
					}
					if (b == 1) {
						cout << "The winner is " << mentor1b.at(i).at(0)->getName() << endl;
						
						mentors.at(0)->addTeamBattle(mentor1b.at(1).at(0));
					}
					if (b == 2) {
						cout << "The winner is " << mentor1b.at(i).at(1)->getName() << endl;

						mentors.at(0)->addTeamBattle(mentor1b.at(1).at(1));
					}
				}
				cin.clear();
				break;
			case 2:
				mentor2b = teamBattleFase(1);
				mentor2 = teamBattleSongs();

				cout << endl << mentors.at(1)->getName() << "'s Battles " << endl;
				for (int i = 0; i < mentor2.size(); i++)
				{
					int b;
					cout << "Contestants: "<< endl << mentor2b.at(i).at(0)->getName() << " VS " << mentor2b.at(i).at(1)->getName() << endl;
					cout << "Singing: "<< endl << mentor2.at(i)->getName() << " - " << mentor2.at(i)->getArtist() << endl;
					cout << "Who wins? (1/2)" << endl;
					while (1)
					{
						while (!(cin >> b))
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Not a number, try again" << endl;
						}
						if (b != 1 && b != 2) {
							cout << "Wrong option, try again" << endl;
							cin.clear();
						}
						else {
							break;
						}
					}
					
					if (b == 1) {
						cout << "The winner is " << mentor2b.at(i).at(0)->getName() << endl;

						mentors.at(0)->addTeamBattle(mentor2b.at(1).at(0));
					}
					if (b == 2) {
						cout << "The winner is " << mentor2b.at(i).at(1)->getName() << endl;

						mentors.at(1)->addTeamBattle(mentor2b.at(1).at(1));
					}
					
				
				}
				cin.clear();
				break;
			case 3:
				mentor3b = teamBattleFase(2);
				mentor3 = teamBattleSongs();

				cout << "Contestants: " << endl <<  mentors.at(2)->getName() << "'s Battles " << endl;
				for (int i = 0; i < mentor3.size(); i++)
				{
					int b;
					cout << "Contestants: " << endl << mentor3b.at(i).at(0)->getName() << " VS " << mentor3b.at(i).at(1)->getName() << endl;
					cout << "Singing: " << endl << mentor3.at(i)->getName() << " - " << mentor3.at(i)->getArtist() << endl;
					cout << "Who wins? (1/2)" << endl;
					while (1)
					{
						while (!(cin >> b))
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Not a number, try again" << endl;
						}
						if (b != 1 && b != 2) {
							cout << "Wrong option, try again" << endl;
							cin.clear();
						}
						else {
							break;
						}
					}
					if (b == 1) {
						cout << "The winner is " << mentor3b.at(i).at(0)->getName() << endl;

						mentors.at(0)->addTeamBattle(mentor3b.at(1).at(0));
					}
					if (b == 2) {
						cout << "The winner is " << mentor3b.at(i).at(1)->getName() << endl;

						mentors.at(2)->addTeamBattle(mentor3b.at(1).at(1));
					}
				
				}
				cin.clear();
				break;
			case 4:

				mentor4b = teamBattleFase(3);
				mentor4 = teamBattleSongs();

				cout << mentors.at(3)->getName() << "'s Battles " << endl;
				for (int i = 0; i < mentor4.size(); i++)
				{
					int b;
					cout << "Contestants: " << endl << mentor4b.at(i).at(0)->getName() << " VS " << mentor4b.at(i).at(1)->getName() << endl;
					cout << "Singing: " << endl << mentor4.at(i)->getName() << " - " << mentor4.at(i)->getArtist() << endl;
					cout << "Who wins? (1/2)" << endl;
					while (1)
					{
						while (!(cin >> b))
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Not a number, try again" << endl;
						}
						if (b != 1 && b != 2) {
							cout << "Wrong option, try again" << endl;
							cin.clear();
						}
						else {
							break;
						}
					}
					if (b == 1) {
						cout << "The winner is " << mentor4b.at(i).at(0)->getName() << endl;

						mentors.at(0)->addTeamBattle(mentor4b.at(1).at(0));
					}
					if (b == 2) {
						cout << "The winner is " << mentor4b.at(i).at(1)->getName() << endl;

						mentors.at(3)->addTeamBattle(mentor4b.at(1).at(1));
					}
				
				}
				cin.clear();
				break;
			}
		}
			

	}

}

