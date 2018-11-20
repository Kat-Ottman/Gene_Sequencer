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
	void SetNucleotideSequence()
	{
	}
	void GetNucleotideSequence();
	void SetVariantName();
	void GetVariantName();
	bool RunUnitTests();
};