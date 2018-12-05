#include <iostream>
#include <fstream>
#include "GeneSequencer.h"

using namespace std;

ChromosomePair GeneSequencer::CreateChromosome() //Using ChromosomePair::ChromosomePair(), creates a new Chromsome with a new genes vector
{
	ChromosomePair c;
	string CName;
	int CGS;
	cout << "What is your Chromosome's Name?" << endl;
	cin >> CName;
	c.SetChromosomeName(CName);
	cout << "What is your Chromosome's Gene Count?" << endl;
	cin >> CGS;
	for (int i = 0; i < CGS; i++)
	{
		ChromosomePair();
	}
	return c;
}

ChromosomePair GeneSequencer::ImportChromosome(const string &myfile) //Creates a new Chromosome based on the Genes found i the given file
{
	ifstream fileOpen;
	fileOpen.open("myfile");
	ChromosomePair c;
	c.InputFromFile(fileOpen);
	fileOpen.close();
	return c;
}

void GeneSequencer::ExportChromosome(ChromosomePair c, const string &myfile) //Takes given ChromosomePair and writes it to the given file
{
	ofstream fileOpen;
	fileOpen.open("myfile");
	c.OutputToFile(fileOpen);
	fileOpen.close();
}

ChromosomePair GeneSequencer::DoMeiosis(ChromosomePair a, ChromosomePair b) //Using ChromosomePair::operator==(), adds ChromosomePairs a and b into ChromosomePair c
{
	ChromosomePair c = (a + b);
	return c;
}

void GeneSequencer::SequenceChromosomes(ChromosomePair c) //Using ChromosomePair::AnalyzeGenotype() on given ChromosomePair
{
	c.AnalyzeGenotype();
}

bool GeneSequencer::PowerOnSelfTest() //Tests all variables and functions in GeneSequencer class for functionality
{
	ChromosomePair c;
	bool isOkay = c.RunUnitTests();
	return isOkay;
}