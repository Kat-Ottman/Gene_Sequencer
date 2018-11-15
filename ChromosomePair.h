#include <Gene.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class ChromosomePair
{
  private:
	vector<Gene> genes;

  public:
	ChromosomePair();

	void AnalyzeGenotype();
	void InputFromFile(ifstream &);
	void OutputToFile(ofstream &);
	void AddGene(Gene);
	Gene FindGene(string name);
	//Chromosome operator + (Chrmosome)
	bool RunUnitTests();
};