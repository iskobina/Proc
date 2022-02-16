#pragma once
#ifndef FUNCTIONAL_H
#define FUNCTIONAL_H

#include <fstream>

using namespace std;

namespace Skobina
{
	struct Functional
	{
		enum lang
		{
			PROC,
			OOP,
			FUNCTIONAL
		} key;
		unsigned short int year_of_development;
		int reference;
		bool lazy_calculations;
		enum typification
		{
			STRICT,
			DYNAMIC
		} type;
	};

	Functional* Functional_Input(Functional& obj, ifstream& fin);
	void Functional_Output(Functional* obj, ofstream& fout);
}

#endif