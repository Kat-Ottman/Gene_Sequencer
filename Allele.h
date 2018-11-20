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
	Allele();
	Allele(string, string, string);

	void WriteAlleleToFile(ofstream &myfile)
	{
		myfile.open("Chromosome.txt");
		myfile << variantName << variantType << nucleotideSequence << "\n";
		myfile.close();
	};

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