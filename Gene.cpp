#include <iostream>
#include <fstream>
#include "Gene.h"

using namespace std;

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