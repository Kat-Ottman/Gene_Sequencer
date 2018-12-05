#include <iostream>
#include <fstream>
#include "Gene.h"

using namespace std;

Gene::Gene() //Confirms that a new variable, type Gene, is being created
{
	cout << "Your Gene is being created." << endl;
	Allele();
}
void Gene::SetName(string givenName) //Takes given string and assigns to Name
{
	name = givenName;
}
string Gene::GetName() const //Returns string in Name
{
	return name;
}
void Gene::SetTraitType(string givenTraitType) //Takes given string and assigns to Trait Type
{
	traitType = givenTraitType;
}
string Gene::GetTraitType() const //Returns string in Trait Type
{
	return traitType;
}
void Gene::SetAlleleA(Allele givenAlleleA) //Takes given Allele and assigns to Allele A
{
	AlleleA = givenAlleleA;
}
Allele Gene::GetAlleleA() //Returns Allele in Allele A
{
	return AlleleA;
}
void Gene::SetAlleleB(Allele givenAlleleB) //Takes given Allele and assings to Allele B
{
	AlleleB = givenAlleleB;
}
Allele Gene::GetAlleleB() //Returns Allele in Allele B
{
	return AlleleB;
}

Gene::Gene(Allele A1, Allele A2) //Gene constructor that uses Setters in Gene class
{
	SetAlleleA(A1);
	SetAlleleB(A2);
}

void Gene::WriteToFile(ofstream &myfile) //Writes known Alleles in given file
{
	myfile << name << "," << traitType;
	AlleleA.WriteAlleleToFile(myfile);
	AlleleB.WriteAlleleToFile(myfile);
	myfile << endl;
}

Allele Gene::GetExpressedTrait() //Checks Variant Type of Alleles in a Gene to see which is dominant
{
	Allele dominantAllele;
	if (AlleleA.GetVariantType() == "dominant")
	{
		dominantAllele = AlleleA;
	}
	else if (AlleleB.GetVariantType() == "dominant")
	{
		dominantAllele = AlleleB;
	}
	return dominantAllele;
}

bool Gene::operator==(Gene rhs) //Overloads operator== for use in ChromosomePair::FindGene()
{
	bool isMatch = false;
	if (this->GetAlleleA().GetNucleotideSequence() == rhs.GetAlleleA().GetNucleotideSequence())
	{
		if (this->GetAlleleB().GetNucleotideSequence() == rhs.GetAlleleB().GetNucleotideSequence())
		{
			if (this->GetAlleleA().GetVariantName() == rhs.GetAlleleA().GetVariantName())
			{
				if (this->GetAlleleB().GetVariantName() == rhs.GetAlleleB().GetVariantName())
				{
					isMatch = true;
				}
			}
		}
	}
	return isMatch;
}

bool Gene::RunUnitTests() //Checks all variables and functions in Gene class for functionality
{
	Gene g;
	Allele a;
	bool isOkay = a.RunUnitTests();

	g.SetName("U567");
	if (g.GetName() != "U567")
	{
		cout << "FAILED set/get Gene Name." << endl;
		isOkay = false;
	}

	g.SetTraitType("Hair Color");
	if (g.GetTraitType() != "Hair Color")
	{
		cout << "FAILED set/get Gene Trait Type." << endl;
		isOkay = false;
	}

	return isOkay;
}