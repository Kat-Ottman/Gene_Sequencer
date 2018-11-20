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
	void InputFromFile(ifstream &myfile)
	{
		Gene word;
		myfile.open("Chromosome.txt");
		myfile >> word; //how can you transfer strings in the file into parts that a gene vector will accept
		genes.push_back(word);
		myfile.close();
	};
	void OutputToFile(ofstream &myfile) //why would you output to a file when there is nothing else left to output to it???
	{
		myfile.open("Chromosome.txt");
		for (int i = 0; i <= genes.size(); i++)
		{
			myfile << genes.at(i).GetName() << genes.at(i).GetTraitType() << genes.at(i).GetNucleotideSequence() << genes.at(i).GetVariantName() << genes.at(i).GetVariantType();
		}
		myfile.close();
	};
	void AddGene(Gene givenGene)
	{
		genes.push_back(givenGene);
	};
	Gene FindGene(Gene givenGene)
	{
		Gene match;
		for (int i = 0; i <= genes.size(); i++)
		{
			if (genes.at(i) == givenGene) //how you you compare two genes without using ==
			{
				match = genes.at(i);
			}
		}
		return match;
	};
	//Chromosome operator + (Chrmosome)
	bool RunUnitTests();
};