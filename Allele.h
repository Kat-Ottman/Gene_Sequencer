#pragma once
#include <iostream>

using namespace std;

class Allele
{
  private:
	string nucleotideSequence;
	string variantName;
	string variantType;

  public:
	Allele();

	Allele(string NS, string VN, string VT);

	void WriteAlleleToFile(ofstream &myfile);

	void SetNucleotideSequence(string givenNucleotideSequence);
	string GetNucleotideSequence() const;
	void SetVariantName(string givenVariantName);
	string GetVariantName() const;
	void SetVariantType(string givenVariantType);
	string GetVariantType() const;

	bool RunUnitTests();

	bool operator==(Allele rhs);
};