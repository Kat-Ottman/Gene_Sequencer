#include "Allele.h"
#include <iostream>
#include <fstream>

using namespace std;

Allele::Allele()
{
	cout << "Allele is being created." << endl;
}

void Allele::SetNucleotideSequence(string givenNucleotideSequence)
{
	nucleotideSequence = givenNucleotideSequence;
}
string Allele::GetNucleotideSequence() const
{
	return nucleotideSequence;
}
void Allele::SetVariantName(string givenVariantName)
{
	variantName = givenVariantName;
}
string Allele::GetVariantName() const
{
	return variantName;
}
void Allele::SetVariantType(string givenVariantType)
{
	variantType = givenVariantType;
}
string Allele::GetVariantType() const
{
	return variantType;
}

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
