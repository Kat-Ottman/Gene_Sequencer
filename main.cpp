/*	Project:    Gene Sequencer
	Name:       Kat Ottman
    Partner:    N/A
    Class:      CSC 1810 - Section 3
*/

#include <iostream>
#include <vector>
#include "Allele.h"
#include "Gene.h"
#include "ChromosomePair.h"
#include "GeneSequencer.h"

using namespace std;

void Menu() //Goes through options for user and implements functions in GeneSequencer based on user choice
{
	string userChoice = "0";
	GeneSequencer g;
	vector<ChromosomePair> cVec;

	while (userChoice != "6") //While-loop continues if user does not want to exit program
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

		if (userChoice == "1") //Create Chromosome
		{
			cVec.push_back(g.CreateChromosome());
		}
		else if (userChoice == "2") //Analyze Chromosome
		{
			string CName;
			cout << "What Chromosome would you like to analyze?" << endl;
			cin >> CName;
			for (size_t i = 0; i < cVec.size(); i++)
			{
				if (cVec.at(i).GetChromosomeName() == CName)
				{
					g.SequenceChromosomes(cVec.at(i));
				}
				else
				{
					cout << "This Chromosome does not exist." << endl;
				}
			}
		}
		else if (userChoice == "3") //Output Chromosome to File
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
					g.ExportChromosome(cVec.at(i), fileName);
				}
				else
				{
					cout << "This Chromosome does not exist." << endl;
				}
			}
		}
		else if (userChoice == "4") //Input Chromosome From File
		{
			string fileName;
			cout << "What file would you like to input a Chromosome from?" << endl;
			cin >> fileName;
			cVec.push_back(g.ImportChromosome(fileName));
		}
		else if (userChoice == "5") //Combine Chromosomes
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

			cVec.push_back(a + b);

			cout << "Your new Chromosme has been created and added to your known Chromosomes." << endl;
		}
	}
	cout << "Thank you for using this program!" << endl; //Exit
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