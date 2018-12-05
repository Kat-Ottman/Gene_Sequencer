#include <iostream>
#include <fstream>
#include <vector>
#include "ChromosomePair.h"
#include "Allele.h"

using namespace std;

void ChromosomePair::AddGene(Gene givenGene) //Takes given gene and creates a new position for it in genes vector
{
	genes.push_back(givenGene);
}

string ChromosomePair::GetChromosomeName() //Returns string in Chromosome Name
{
	return ChromosomeName;
}

void ChromosomePair::SetChromosomeName(string name) ////Takes given string and assigns it to Chromosome Name
{
	ChromosomeName = name;
}

ChromosomePair::ChromosomePair() //ChromsomePair Constructor that creates all variables under a Gene and adds to this->genes
{
	Gene g;

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
	g.SetName(GN);
	cout << "What is the Gene's Trait Type?" << endl;
	cin >> TT;
	g.SetTraitType(TT);

	cout << "What is Allele A's Variant Name for Gene " << GN << "?" << endl;
	cin >> A1VN;
	cout << "What is Allele A's Variant Type for Gene " << GN << "?" << endl;
	cin >> A1VT;
	cout << "What is Allele A's Nucleode Sequence for Gene " << GN << "?" << endl;
	cin >> A1NS;
	g.SetAlleleA(Allele(A1NS, A1VT, A1VN));

	cout << "What is Allele B's Variant Name for Gene " << GN << "?" << endl;
	cin >> A2VN;
	cout << "What is Allele B's Variant Type for Gene " << GN << "?" << endl;
	cin >> A2VT;
	cout << "What is Allele B's Nucleode Sequence for Gene " << GN << "?" << endl;
	cin >> A2NS;
	g.SetAlleleB(Allele(A2NS, A2VT, A2VN));

	g = Gene(g.GetAlleleA(), g.GetAlleleB());
	AddGene(g);
}

void ChromosomePair::AnalyzeGenotype() //Prints out specific information about a Gene including it's "dominant" trait
{
	for (size_t i = 0; i <= genes.size(); i++)
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

int CountLinesinFile(ifstream &myfile) //Reads the amount of lines that are in a given file
{
	int numlines = 0;
	string line;
	while (getline(myfile, line))
	{
		numlines++;
	}
	return numlines;
}

void ChromosomePair::InputFromFile(ifstream &myfile) //Creates a new Gene type variable for each line in a file and adds it to this->genes
{

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
		AddGene(Gene((g.GetAlleleA()), (g.GetAlleleB())));
	}
}

void ChromosomePair::OutputToFile(ofstream &myfile) //Uses Gene::WriteToFile() for each Gene in genes with the given file
{
	for (size_t i = 0; i <= genes.size(); i++)
	{
		genes.at(i).WriteToFile(myfile);
	}
}

Gene ChromosomePair::FindGene(string givenGene) //Compares the given string to the Names of each Gene in genes
{
	Gene match;
	for (size_t i = 0; i <= genes.size(); i++)
	{
		string givenName = genes.at(i).GetName();
		if (givenName == givenGene)
		{
			match = genes.at(i);
		}
	}
	return match;
}

ChromosomePair ChromosomePair::operator+(ChromosomePair addMe) //Overloads operator+ to create a new ChromosomePair with a genes vector of Genes made from dominant Alleles
{
	ChromosomePair newChromosomePair;
	if (addMe.genes.size() != this->genes.size())
	{
		if (addMe.genes.size() > this->genes.size())
		{
			for (size_t i = 0; i < this->genes.size(); i++)
			{
				Gene g;
				g.SetAlleleA(this->genes.at(i).GetExpressedTrait());
				g.SetAlleleB(addMe.genes.at(i).GetExpressedTrait());
				g = Gene(g.GetAlleleA(), g.GetAlleleB());
				newChromosomePair.AddGene(g);
			}
		}
		else if (addMe.genes.size() < this->genes.size())
		{
			for (size_t i = 0; i < addMe.genes.size(); i++)
			{
				Gene g;
				g.SetAlleleA(this->genes.at(i).GetExpressedTrait());
				g.SetAlleleB(addMe.genes.at(i).GetExpressedTrait());
				g = Gene(g.GetAlleleA(), g.GetAlleleB());
				newChromosomePair.AddGene(g);
			}
		}
	}
	else
	{
		for (size_t i = 0; i < this->genes.size(); i++)
		{
			Gene g;
			g.SetAlleleA(this->genes.at(i).GetExpressedTrait());
			g.SetAlleleB(addMe.genes.at(i).GetExpressedTrait());
			g = Gene(g.GetAlleleA(), g.GetAlleleB());
			newChromosomePair.AddGene(g);
		}
	}

	return newChromosomePair;
}

bool ChromosomePair::RunUnitTests()
{
	Gene g;
	bool isOkay = g.RunUnitTests();
	return isOkay;
}
