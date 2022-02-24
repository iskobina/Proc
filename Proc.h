#ifndef PROCEDURAL_H
#define PROCEDURAL_H

#include <fstream>

using namespace std;

namespace Skobina
{
	struct Procedural
	{
		enum Lang
		{
			PROCEDURAL,
			OOP,
			FUNCTIONAL
		} Key;

		unsigned int YearOfDevelopment;
		unsigned long long int Reference;
		bool AbstractType;
	};

	bool Procedural_Input(Procedural& Obj, ifstream& FileInput);
	void Procedural_Output(Procedural& Obj, ofstream& FileOutput);
}

#endif