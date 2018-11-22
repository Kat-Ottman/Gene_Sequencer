#include <iostream>
#include <fstream>
#include <vector>
#include <ChromosomePair.h>

using namespace std;

ChromosomePair::ChromosomePair()
{
}

void ChromosomePair::AnalyzeGenotype()
{
}

void ChromosomePair::InputFromFile(ifstream &myfile)
{
	Gene word;
	string A1NS;
	string A1VN;
	string A1VT;
	string A2NS;
	string A2VN;
	string A2VT;
	string GN;
	string TT;
	myfile.open("Chromosome.txt");
	myfile >> GN; //how can you transfer strings in the file into parts that a gene vector will accept USE Gene(Allele, Allele) and Allele(string, string, string)
	myfile >> TT;
	myfile >> A1VN;
	myfile >> A1VT;
	myfile >> A1NS;
	myfile >> A2VN;
	myfile >> A2VT;
	myfile >> A2NS;
	Allele.Allele(A1NS, A1VN, A1VT);
	Allele.Allele(A2NS, A2VN, A2VT);
	genes.push_back(word);
	myfile.close();
};

void ChromosomePair::OutputToFile(ofstream &myfile)
{
	myfile.open("Chromosome.txt");
	for (int i = 0; i <= genes.size(); i++)
	{
		myfile << genes.at(i).GetName() << genes.at(i).GetTraitType();
		Allele.WriteAlleleToFile(myfile);
	}
	myfile.close();
};

Gene ChromosomePair::FindGene(string givenGene)
{
	Gene match;
	for (int i = 0; i <= genes.size(); i++)
	{
		string geneName = genes.at(i);
		if (geneName == givenGene)
		{
			match = genes.at(i);
		}
	}
	return match;
};

bool ChromosomePair::RunUnitTests()
{
}