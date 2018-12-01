#include "Allele.h"
#include <iostream>
#include <fstream>

using namespace std;

bool Allele::RunUnitTests() {}

void Allele::WriteAlleleToFile(ofstream &myfile)
{
	myfile << "," << variantName << "," << variantType << "," << nucleotideSequence;
}

Allele::Allele(string NS, string VN, string VT)
{
	SetNucleotideSequence(NS);
	SetVariantName(VN);
	SetVariantType(VT);
}

bool Allele::operator==(Allele rhs)
{
	bool isMatch = false;
	if (this->GetNucleotideSequence() == rhs.GetNucleotideSequence())
	{
		if (this->GetNucleotideSequence() == rhs.GetNucleotideSequence())
		{
			if (this->GetVariantName() == rhs.GetVariantName())
			{
				if (this->GetVariantName() == rhs.GetVariantName())
				{
					isMatch = true;
				}
			}
		}
	}
	return isMatch;
}
