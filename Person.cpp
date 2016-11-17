/*
 * Person.cpp
 *
 *  Created on: 16/11/2016
 *      Author: cavac
 */

#include "Person.h"


Person::Person(string name)
{
	this ->name = name;
}

Contestant::Contestant(string name): Person(name)
{

}

Mentor::Mentor(string name): Person(name)
{

}
