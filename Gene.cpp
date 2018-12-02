#include <iostream>
#include <fstream>
#include "Gene.h"

using namespace std;

Gene::Gene()
{
	cout << "Gene is being created." << endl;
}
void Gene::SetName(string givenName)
{
	name = givenName;
}
string Gene::GetName() const
{
	return name;
}
void Gene::SetTraitType(string givenTraitType)
{
	traitType = givenTraitType;
}
string Gene::GetTraitType() const
{
	return traitType;
}
void Gene::SetAlleleA(Allele givenAlleleA)
{
	AlleleA = givenAlleleA;
}
Allele Gene::GetAlleleA()
{
	return AlleleA;
}
void Gene::SetAlleleB(Allele givenAlleleB)
{
	AlleleB = givenAlleleB;
}
Allele Gene::GetAlleleB()
{
	return AlleleB;
}

Gene::Gene(Allele A1, Allele A2)
{
	SetAlleleA(A1);
	SetAlleleB(A2);
}

void Gene::WriteToFile(ofstream &myfile)
{
	myfile << name << "," << traitType;
	AlleleA.WriteAlleleToFile(myfile);
	AlleleB.WriteAlleleToFile(myfile);
	myfile << endl;
}

Allele Gene::GetExpressedTrait()
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

bool Gene::RunUnitTests()
{
}

bool Gene::operator==(Gene rhs)
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