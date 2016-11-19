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

	//Load das songs para o vetor



	

	Season a1 (mentorsTmp, contestantsTmp, songs);
	seasons.push_back(a1);
}



bool TheVoice::inputCharCorrect(char c)
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