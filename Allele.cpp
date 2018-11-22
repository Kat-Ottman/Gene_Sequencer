#include <Allele.h>
#include <iostream>
#include <fstream>

using namespace std;

bool Allele::RunUnitTests(){};
void Allele::WriteAlleleToFile(ofstream &myfile)
{
	myfile.open("Chromosome.txt");
	myfile << variantName << variantType << nucleotideSequence << "\n";
	myfile.close();
};
Allele::Allele(string NS, string VN, string VT)
{
	SetNucleotideSequence(NS);
	SetVariantName(VN);
	SetVariantType(VT);
}