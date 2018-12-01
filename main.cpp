/*	Project:    Gene Sequencer
	Name:       Kat Ottman
    Partner:    N/A
    Class:      CSC 1810 - Section 3
*/

#include <iostream>
#include "Allele.h"
#include "ChromosomePair.h"
#include "Gene.h"
#include "GeneSequencer.h"

using namespace std;

void Menu()
{
	string userChoice = "";

	while (userChoice != "6")
	{
		cout << "Welcome to the Gene Sequencer! Please enter a number choice."
			 << "\n"
			 << "1 - Create Chromosome"
			 << "\n"
			 << "2 - Analyze Chromosome"
			 << "\n"
			 << "3 - Output Chromosome to File"
			 << "\n"
			 << "4 - Input Chromosome From File"
			 << "\n"
			 << "5- Combine Chromosomes"
			 << "\n"
			 << "6 - Exit" << endl;

		cin >> userChoice;

		if (userChoice == "1")
		{
		}
		else if (userChoice == "2")
		{
		}
		else if (userChoice == "3")
		{
		}
		else if (userChoice == "4")
		{
		}
		else if (userChoice == "5")
		{
		}
	}
}

int main(int argc, char *argv[])
{
	Menu();

	{
		char c;
		cout << "Hit enter to exit:";
		cin.get(c);
	}
	return 0;
}