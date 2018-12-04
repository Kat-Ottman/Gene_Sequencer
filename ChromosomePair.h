#pragma once
#include "Gene.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ChromosomePair
{
  private:
	vector<Gene> genes;
	string ChromosomeName;

  public:
	vector<ChromosomePair> chromosomes;

	ChromosomePair();

	void AnalyzeGenotype();
	void InputFromFile(ifstream &myfile);
	void OutputToFile(ofstream &myfile);
	string GetChromosomeName();
	void SetChromosomeName(string name);

	void AddGene(Gene givenGene);
	Gene FindGene(string givenGene);
	ChromosomePair operator+(ChromosomePair addMe);
	bool RunUnitTests();
};