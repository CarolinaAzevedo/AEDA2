/*
 * Season.cpp
 *
 *  Created on: 16/11/2016
 *      Author: cavac
 */

#include "Season.h"




Season::Season(vector<Mentor*> mentors, vector<Contestant*> contestants, vector<Song*> songs){

	this->mentors = mentors;
	this->contestants = contestants;
	this->songs = songs;
}
