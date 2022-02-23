#ifndef PROCEDURAL_H
#define PROCEDURAL_H

#include <fstream>

using namespace std;

namespace Skobina
{
	struct Procedural
	{
		enum lang
		{
			PROCEDURAL,
			OOP,
			FUNCTIONAL
		} key;
		unsigned int year_of_development;
		unsigned long long int reference;
		bool abstract_type;
	};

	bool Procedural_Input(Procedural& obj, ifstream& fin);
	void Procedural_Output(Procedural& obj, ofstream& fout);
}

#endif