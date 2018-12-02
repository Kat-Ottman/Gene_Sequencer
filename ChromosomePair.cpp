#include <iostream>
#include <fstream>
#include <vector>
#include "ChromosomePair.h"
#include "Allele.h"

using namespace std;

string ChromosomePair::GetChromosomeName()
{
	return ChromosomeName;
}

ChromosomePair::ChromosomePair()
{
	ChromosomePair newChromosomePair;

	int GC;
	cout << "What is your Chromosome Pair's name?" << endl;
	cin >> ChromosomeName;
	cout << "What is your Chromosome Pair's gene count?" << endl;
	cin >> GC;
	newChromosomePair.genes.resize(GC);

	for (int i = 0; i < newChromosomePair.genes.size(); i++)
	{
		string A1NS;
		string A1VN;
		string A1VT;
		string A2NS;
		string A2VN;
		string A2VT;
		string GN;
		string TT;

		cout << "What is the Gene's Name?" << endl;
		cin >> GN;
		newChromosomePair.genes.at(i).SetName(GN);
		cout << "What is the Gene's Trait Type?" << endl;
		cin >> TT;
		newChromosomePair.genes.at(i).SetTraitType(TT);

		cout << "What is Allele A's Variant Name for Gene " << GN << "?" << endl;
		cin >> A1VN;
		cout << "What is Allele A's Variant Type for Gene " << GN << "?" << endl;
		cin >> A1VT;
		cout << "What is Allele A's Nucleode Sequence for Gene " << GN << "?" << endl;
		cin >> A1NS;
		newChromosomePair.genes.at(i).SetAlleleA(Allele(A1NS, A1VT, A1VN));

		cout << "What is Allele B's Variant Name for Gene " << GN << "?" << endl;
		cin >> A2VN;
		cout << "What is Allele B's Variant Type for Gene " << GN << "?" << endl;
		cin >> A2VT;
		cout << "What is Allele B's Nucleode Sequence for Gene " << GN << "?" << endl;
		cin >> A2NS;
		newChromosomePair.genes.at(i).SetAlleleB(Allele(A2NS, A2VT, A2VN));

		Gene g = Gene(newChromosomePair.genes.at(i).GetAlleleA(), newChromosomePair.genes.at(i).GetAlleleB());
		newChromosomePair.genes.at(i) = g;
		chromosomes.push_back(newChromosomePair);
	}
}

void ChromosomePair::AnalyzeGenotype()
{
	for (int i = 0; i <= genes.size(); i++)
	{
		cout << "Gene" << i << endl;
		cout << "   Name:   " << genes.at(i).GetName() << endl;
		cout << "   Genetic Trait:   " << genes.at(i).GetTraitType() << endl;
		cout << "   Expressed Allele:   ";
		if (genes.at(i).GetExpressedTrait() == genes.at(i).GetAlleleA())
		{
			cout << genes.at(i).GetAlleleA().GetVariantName() << endl;
			cout << "   Nucleotide Sequence:   " << genes.at(i).GetAlleleA().GetNucleotideSequence() << endl;
		}
		else if (genes.at(i).GetExpressedTrait() == genes.at(i).GetAlleleB())
		{
			cout << genes.at(i).GetAlleleB().GetVariantName() << endl;
			cout << "   Nucleotide Sequence:   " << genes.at(i).GetAlleleB().GetNucleotideSequence() << endl;
		}
		cout << "\n \n";
	}
}

int CountLinesinFile(ifstream &myfile)
{
	int numlines = 0;
	string line;
	while (getline(myfile, line))
	{
		numlines++;
	}
	return numlines;
}

void ChromosomePair::InputFromFile(ifstream &myfile)
{
	ChromosomePair c;

	for (int i = 0; i < CountLinesinFile(myfile); i++)
	{
		string A1NS;
		string A1VN;
		string A1VT;
		string A2NS;
		string A2VN;
		string A2VT;
		string GN;
		string TT;
		myfile >> GN;
		myfile >> TT;
		myfile >> A1VN;
		myfile >> A1VT;
		myfile >> A1NS;
		myfile >> A2VN;
		myfile >> A2VT;
		myfile >> A2NS;

		Gene g;
		g.SetName(GN);
		g.SetTraitType(TT);
		g.SetAlleleA(Allele(A1NS, A1VN, A1VT));
		g.SetAlleleB(Allele(A2NS, A2VN, A2VT));
		c.AddGene(Gene((g.GetAlleleA()), (g.GetAlleleB())));
	}
}

void ChromosomePair::OutputToFile(ofstream &myfile)
{
	for (int i = 0; i <= genes.size(); i++)
	{
		genes.at(i).WriteToFile(myfile);
	}
}

Gene ChromosomePair::FindGene(string givenGene)
{
	Gene match;
	for (int i = 0; i <= genes.size(); i++)
	{
		string givenName = genes.at(i).GetName();
		if (givenName == givenGene)
		{
			match = genes.at(i);
		}
	}
	return match;
}

ChromosomePair ChromosomePair::operator+(ChromosomePair addMe)
{
	ChromosomePair newChromosomePair;
	if (addMe.genes.size() != this->genes.size())
	{
		if (addMe.genes.size() > this->genes.size())
		{
			for (int i = 0; i < this->genes.size(); i++)
			{
				Gene g = Gene();
				g.SetAlleleA(this->genes.at(i).GetExpressedTrait());
				g.SetAlleleB(addMe.genes.at(i).GetExpressedTrait());
				newChromosomePair.AddGene(g);
			}
		}
		else if (addMe.genes.size() < this->genes.size())
		{
			for (int i = 0; i < addMe.genes.size(); i++)
			{
				Gene g = Gene();
				g.SetAlleleA(this->genes.at(i).GetExpressedTrait());
				g.SetAlleleB(addMe.genes.at(i).GetExpressedTrait());
				newChromosomePair.AddGene(g);
			}
		}
	}
	else
	{
		for (int i = 0; i < this->genes.size(); i++)
		{
			Gene g = Gene();
			g.SetAlleleA(this->genes.at(i).GetExpressedTrait());
			g.SetAlleleB(addMe.genes.at(i).GetExpressedTrait());
			newChromosomePair.AddGene(g);
		}
	}

	return newChromosomePair;
}

bool ChromosomePair::RunUnitTests()
{
}
