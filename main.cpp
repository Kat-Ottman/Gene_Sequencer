/*	Project:    Gene Sequencer
	Name:       Kat Ottman
    Partner:    N/A
    Class:      CSC 1810 - Section 3
*/

#include <iostream>
#include "Allele.h"
#include "Gene.h"
#include "ChromosomePair.h"
#include "GeneSequencer.h"

using namespace std;

void Menu()
{
	string userChoice = "";
	GeneSequencer g;
	vector<ChromosomePair> cVec;
	ChromosomePair c;

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
			c = g.CreateChromosome();
			cVec.push_back(c);
		}
		else if (userChoice == "2")
		{
			string CName;
			cout << "What Chromosome would you like to analyze?" << endl;
			cin >> CName;
			for (size_t i = 0; i < cVec.size(); i++)
			{
				if (cVec.at(i).GetChromosomeName() == CName)
				{
					c = cVec.at(i);
					g.SequenceChromosomes(c);
				}
				else
				{
					cout << "This Chromosome does not exist." << endl;
				}
			}
		}
		else if (userChoice == "3")
		{
			string fileName;
			string CName;
			cout << "What file would you like to output your Chromosome to?" << endl;
			cin >> fileName;
			cout << "What Chromosome would you like to output?" << endl;
			cin >> CName;
			for (size_t i = 0; i < cVec.size(); i++)
			{
				if (CName == cVec.at(i).GetChromosomeName())
				{
					c = cVec.at(i);
					g.ExportChromosome(c, fileName);
				}
				else
				{
					cout << "This Chromosome does not exist." << endl;
				}
			}
		}
		else if (userChoice == "4")
		{
			string fileName;
			cout << "What file would you like to input a Chromosome from?" << endl;
			cin >> fileName;
			c = g.ImportChromosome(fileName);
			cVec.push_back(c);
		}
		else if (userChoice == "5")
		{
			string C1;
			string C2;
			ChromosomePair a;
			ChromosomePair b;
			ChromosomePair c;
			cout << "What is the first Chromosome you'd like to combine with?" << endl;
			cin >> C1;
			for (size_t i = 0; i < cVec.size(); i++)
			{
				if (cVec.at(i).GetChromosomeName() == C1)
				{
					a = cVec.at(i);
				}
				else
				{
					cout << "This Chromosome has not been created." << endl;
				}
			}
			cout << "What is the second Chromosome you'd like to combine with?" << endl;
			cin >> C2;

			for (size_t i = 0; i < cVec.size(); i++)
			{
				if (cVec.at(i).GetChromosomeName() == C2)
				{
					b = cVec.at(i);
				}
				else
				{
					cout << "This Chromosome has not been created." << endl;
				}
			}

			c = a + b;
			cVec.push_back(c);

			cout << "Your new Chromosme has been created and added to your known Chromosomes." << endl;
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