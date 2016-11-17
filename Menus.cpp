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


#endif /* SRC_MENUS_CPP_ */
