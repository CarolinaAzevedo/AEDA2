/*
 * Person.cpp
 *
 *  Created on: 16/11/2016
 *      Author: Carolina Azevedo, Daniela João & Eduarda Cunha
 */

#include "Person.h"



Person::Person(string name)
{
	this ->name = name;
}

Contestant::Contestant(string name): Person(name)
{
}

string Contestant::getName() {
	return name;
}
Mentor::Mentor(string name): Person(name)
{
}

string Mentor::getName() {
	return name;
}

void Mentor::addTeamBlind(Contestant *c) {
	teamBlind.push_back(c);

}