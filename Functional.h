#ifndef FUNCTIONAL_H
#define FUNCTIONAL_H

#include <fstream>

using namespace std;

namespace Skobina
{
	struct Functional
	{
		enum Lang
		{
			PROCEDURAL,
			OOP,
			FUNCTIONAL
		} Key;

		unsigned int YearOfDevelopment;
		unsigned long long int Reference;
		bool LazyCalculations;

		enum Typification
		{
			STRICT,
			DYNAMIC
		} Type;
	};

	bool Functional_Input(Functional& Obj, ifstream& FileInput);
	void Functional_Output(Functional& Obj, ofstream& FileOutput);
}

#endif