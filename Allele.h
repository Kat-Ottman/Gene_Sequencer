#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Allele
{
  private:
	string nucleotideSequence;
	string variantName;
	string variantType;

  public: //change void!!!
	Allele()
	{
		cout << "Allele is being created." << endl;
	};
	Allele(string, string, string);

	void WriteAlleleToFile(ofstream &myfile);

	void SetNucleotideSequence(string givenNucleotideSequence)
	{
		nucleotideSequence = givenNucleotideSequence;
	};
	string GetNucleotideSequence() const
	{
		return nucleotideSequence;
	};
	void SetVariantName(string givenVariantName)
	{
		variantName = givenVariantName;
	};
	string GetVariantName() const
	{
		return variantName;
	};
	void SetVariantType(string givenVariantType)
	{
		variantType = givenVariantType;
	};
	string GetVariantType() const
	{
		return variantType;
	};

	bool RunUnitTests();
};