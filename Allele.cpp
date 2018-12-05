#include "Allele.h"
#include <iostream>
#include <fstream>
#include "POST.h"

using namespace std;

Allele::Allele() //Confirms that an Allele is being created
{
	cout << "Your Allele is being created." << endl;
}

void Allele::SetNucleotideSequence(string givenNucleotideSequence) //Takes given string and assigns it to NS
{
	nucleotideSequence = givenNucleotideSequence;
}
string Allele::GetNucleotideSequence() const //Returns string in NS
{
	return nucleotideSequence;
}
void Allele::SetVariantName(string givenVariantName) //Takes given string and assigns to VN
{
	variantName = givenVariantName;
}
string Allele::GetVariantName() const //Returns string in VN
{
	return variantName;
}
void Allele::SetVariantType(string givenVariantType) //Takes given string and assigns to VT
{
	variantType = givenVariantType;
}
string Allele::GetVariantType() const //Returns string in VT
{
	return variantType;
}

void Allele::WriteAlleleToFile(ofstream &myfile) //Writes variables from Allele class to given file
{
	myfile << "," << variantName << "," << variantType << "," << nucleotideSequence;
}

Allele::Allele(string NS, string VN, string VT) //Alle Constructor that uses Setters in Allele class
{
	SetNucleotideSequence(NS);
	SetVariantName(VN);
	SetVariantType(VT);
}

bool Allele::operator==(Allele rhs) //Overloading operator== for use in Chromsome::AnalyzeGenotype()
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

bool Allele::RunUnitTests()
{ //Checks all variables and functions in Allele class for functionality
	bool isOkay = true;
	Allele a;
	Allele b;

	cout << "Beginning Allele Tests" << endl;

	a.SetNucleotideSequence("ABCDFG");
	if (a.GetNucleotideSequence() != "ABCDFG")
	{
		cout << "FAILED set/get Nucleotide Sequence." << endl;
		isOkay = false;
	}

	a.SetVariantName("blonde");
	if (a.GetVariantName() != "blonde")
	{
		cout << "FAILED set/get Variant Name." << endl;
		isOkay = false;
	}

	a.SetVariantType("dominant");
	if (a.GetVariantType() != "blonde")
	{
		cout << "FAILED set/get Variant Type." << endl;
		isOkay = false;
	}

	b.SetNucleotideSequence("ABCDFG");
	b.SetVariantName("blonde");
	b.SetVariantType("dominant");
	if (a == b)
	{
		cout << "SUCCESS overloaded operator==" << endl;
	}
	else
	{
		cout << "FAILED overloaded operator==" << endl;
		isOkay = false;
	}

	return isOkay;
}
