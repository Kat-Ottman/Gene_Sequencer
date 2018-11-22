#pragma once
#include <Gene.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class ChromosomePair
{
  private:
	vector<Gene> genes;

  public:
	ChromosomePair();

	void AnalyzeGenotype();
	void InputFromFile(ifstream &myfile);
	void OutputToFile(ofstream &myfile);

	void AddGene(Gene givenGene)
	{
		genes.push_back(givenGene);
	};
	Gene FindGene(Gene givenGene);
	//Chromosome operator + (Chrmosome)
	bool RunUnitTests();
};