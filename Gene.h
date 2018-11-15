#include <Allele.h>
#include <iostream>
#include <fstream>

using namespace std;

class Gene
{
  private:
	string name;
	string traitType;
	string AlleleA;
	string AlleleB;

  public: //change void!!!
	Gene();
	Gene(Allele, Allele);

	void SetName();
	void GetName();
	void SetTraitType();
	void GetTraitType();
	void SetAlleleA();
	void GetAlleleA();
	void SetAlleleB();
	void GetAlleleB();
	void WriteToFile(ofstream &);
	Allele GetExpressedTrait();
	bool RunUnitTests();
};