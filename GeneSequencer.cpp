#include <iostream>
#include <fstream>
#include "GeneSequencer.h"

using namespace std;

ChromosomePair GeneSequencer::CreateChromosome()
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
}

ChromosomePair GeneSequencer::ImportChromosome(const string &myfile)
{
	ifstream fileOpen;
	fileOpen.open("myfile");
	ChromosomePair c;
	c.InputFromFile(fileOpen);
	fileOpen.close();
	return c;
}

void GeneSequencer::ExportChromosome(ChromosomePair c, const string &myfile)
{
	ofstream fileOpen;
	fileOpen.open("myfile");
	c.OutputToFile(fileOpen);
	fileOpen.close();
}

ChromosomePair GeneSequencer::DoMeiosis(ChromosomePair a, ChromosomePair b)
{
	ChromosomePair c = (a + b);
	return c;
}

void GeneSequencer::SequenceChromosomes(ChromosomePair c)
{
	c.AnalyzeGenotype();
}

bool GeneSequencer::PowerOnSelfTest()
{
}