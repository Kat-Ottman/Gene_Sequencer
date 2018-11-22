#include <iostream>
#include <fstream>
#include <Gene.h>

using namespace std;

Gene::Gene(Allele A1, Allele A2)
{
	SetAlleleA(A1);
	SetAlleleB(A2);
}

void Gene::WriteToFile(ofstream &myfile)
{
	myfile.open("Chromosome.txt");
	myfile << name << traitType;
	AlleleA.WriteAlleleToFile(myfile);
	AlleleB.WriteAlleleToFile(myfile);
	myfile.close();
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