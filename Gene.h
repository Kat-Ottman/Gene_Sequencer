#include <Allele.h>
#include <iostream>
#include <fstream>

using namespace std;

class Gene
{
  private:
	string name;
	string traitType;
	Allele AlleleA;
	Allele AlleleB;

  public: //change void!!!
	Gene();
	Gene(Allele, Allele);

	void SetName(string givenName)
	{
		name = givenName;
	};
	string GetName() const
	{
		return name;
	};
	void SetTraitType(string givenTraitType)
	{
		traitType = givenTraitType;
	};
	string GetTraitType() const
	{
		return traitType;
	};
	void SetAlleleA(Allele givenAlleleA)
	{
		AlleleA = givenAlleleA;
	};
	Allele GetAlleleA()
	{
		return AlleleA;
	};
	void SetAlleleB(Allele givenAlleleB)
	{
		AlleleB = givenAlleleB;
	};
	Allele GetAlleleB()
	{
		return AlleleB;
	};

	void WriteToFile(ofstream &myfile)
	{
		myfile.open("Chromosome.txt");
		myfile << name << traitType;
		AlleleA.WriteAlleleToFile(myfile);
		AlleleB.WriteAlleleToFile(myfile);
		myfile.close();
	};
	Allele GetExpressedTrait()
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
	};
	bool RunUnitTests();
};