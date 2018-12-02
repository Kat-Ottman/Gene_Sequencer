#pragma once
#include <ChromosomePair.h>
#include <iostream>

using namespace std;

class GeneSequencer
{
  public:
	ChromosomePair CreateChromosome();
	void ImportChromosome(const string &myfile);
	void ExportChromosome(ChromosomePair c, const string &myfile);
	ChromosomePair DoMeiosis(ChromosomePair a, ChromosomePair b);
	void SequenceChromosomes(ChromosomePair);
	bool PowerOnSelfTest();
};