#pragma once
#include "Allele.h"
#include <iostream>

using namespace std;

class Gene
{
  private:
	string name;
	string traitType;
	Allele AlleleA;
	Allele AlleleB;

  public:
	Gene();
	Gene(Allele A1, Allele A2);

	void SetName(string givenName);
	string GetName() const;
	void SetTraitType(string givenTraitType);
	string GetTraitType() const;
	void SetAlleleA(Allele givenAlleleA);
	Allele GetAlleleA();
	void SetAlleleB(Allele givenAlleleB);
	Allele GetAlleleB();

	void WriteToFile(ofstream &myfile);
	Allele GetExpressedTrait();
	bool operator==(Gene rhs);
	bool RunUnitTests();
};