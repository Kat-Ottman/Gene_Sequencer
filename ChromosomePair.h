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
	void InputFromFile(ifstream &myfile)
	{
		string word;
		myfile.open("Chromosome.txt");
		while (myfile >> word)
		{
			genes.push_back(word);
		}
		myfile.close();
	};
	void OutputToFile(ofstream &myfile)
	{
		myfile.open("Chromosome.txt");
		for (i = 0; i <= genes.length(); i++)
		{
			myfile << genes.at(i);
		}
		myfile.close();
	};
	void AddGene(Gene);
	Gene FindGene(string name);
	//Chromosome operator + (Chrmosome)
	bool RunUnitTests();
};