#pragma once
#include <Gene.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ChromosomePair
{
  private:
	vector<Gene> genes;
	string myfile;

  public:
	ChromosomePair();

	void AnalyzeGenotype();
	void InputFromFile(ifstream &myfile);
	void OutputToFile(ofstream &myfile);

	void AddGene(Gene givenGene)
	{
		genes.push_back(givenGene);
	};

	Gene FindGene(string givenGene);
	ChromosomePair operator+(ChromosomePair addMe); //select dominant allele from two chromosomes to create a new chromosome (a.operator+(b) = c)
	bool RunUnitTests();
};