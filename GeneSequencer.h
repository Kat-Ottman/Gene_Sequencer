#include <ChromosomePair.h>
#include <iostream>
#include <fstream>

using namespace std;

class GeneSequencer
{
  public:
	ChromosomePair CreateChromosome();
	ChromosomePair ImportChromosome();
	void ExportChromosome();
	ChromosomePair DoMeiosis(ChromosomePair, ChromosomePair);
	void SequenceChromosomes(ChromosomePair);
	bool PowerOnSelfTest();
};