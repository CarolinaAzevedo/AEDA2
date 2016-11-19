#include <iostream>
#include <string>
#include <vector>
#include "LIbraries.h"
#include "TheVoice.h"
#include <ctime>

TheVoice programa;
int main()
{
	cout << "The Voice" << endl;
	cout << "---------" << endl;
	cout << "The Voice is a competition which intends to find the best unknown voices in the country!" << endl;
	srand((unsigned int)time(NULL));
	programa.loadAll();
	programa.startMenu();
	
	cout << "Wait on for the next season \n Auditions will begin next Summer" << endl;
	cout << "All you have to do is register as an Artist Account at www.nbcthevoice.com and the following steps will be provided.";
	cout << endl << endl << endl;
	cout << "Executive Producers \n Carolina Azevedo, Daniela Joao and Eduarda Cunha" << endl;
	cout << endl << "Supervising Producers \n Ana Paula Rocha, Henrique Lopes Cardoso and Rosaldo Rossetti" << endl;

	return 0;
}
