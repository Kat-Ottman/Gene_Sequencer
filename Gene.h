#pragma once
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
	Gene()
	{
		cout << "Gene is being created." << endl;
	};
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

	void WriteToFile(ofstream &myfile);
	Allele GetExpressedTrait();
	bool RunUnitTests();
};