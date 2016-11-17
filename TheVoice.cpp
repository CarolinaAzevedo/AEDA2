/*
 * TheVoice.cpp
 *
 *  Created on: 16/11/2016
 *      Author: cavac
 */
#include "TheVoice.h"


void TheVoice::newSeason()
{
	Season a1(void);

	vector<int> tmp;
	vector<Mentor *> mentorsTmp;
	vector<Contestant *> contestantsTmp;
	bool random = true;

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

	/*Season a1(mentorsTmp, contestantsTmp);
	seasons.push_back(a1);*/
}
