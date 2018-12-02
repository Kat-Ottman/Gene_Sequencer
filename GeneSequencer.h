#pragma once
#include "ChromosomePair.h"
#include <iostream>

using namespace std;

class GeneSequencer
{
  public:
	ChromosomePair CreateChromosome();
	ChromosomePair ImportChromosome(const string &myfile);
	void ExportChromosome(ChromosomePair c, const string &myfile);
	ChromosomePair DoMeiosis(ChromosomePair a, ChromosomePair b);
	void SequenceChromosomes(ChromosomePair c);
	bool PowerOnSelfTest();
};