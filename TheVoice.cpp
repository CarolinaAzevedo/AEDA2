 /*
 * TheVoice.cpp
 *
 *  Created on: 16/11/2016
 *      Author: Carolina Azevedo, Daniela João & Eduarda Cunha
 */
#include "TheVoice.h"


void TheVoice::newSeason()
{
	//Season a1(void);

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

	for (int i = 0; i < 299; i++)
	{
		while (1)
		{
			int r = rand() % 299;
			random = true;
			for (int j = 0; j < tmp.size(); j++)
			{
				if (r == tmp[j])

				{
					random = false;
				}
			}
			if (random)
			{
				tmp.push_back(r);
				break;
			}

		}
	}
	for (unsigned int i = 0; i < tmp.size(); i++)
	{
		songsTmp.push_back(songs[tmp[i]]);
	}
	tmp.clear();

	

	Season a1 (mentorsTmp, contestantsTmp, songsTmp);
	seasons.push_back(a1);
}





string TheVoice::trim(const string str) {
	size_t first = str.find_first_not_of(' ');
	size_t last = str.find_last_not_of(' ');
	string a = str.substr(first, (last - first + 1));
	return  a;
}
