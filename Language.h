#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "Proc.h"
#include "OOP.h"
#include "Functional.h"

namespace Skobina
{
	struct Language
	{
		enum Lang
		{
			PROCEDURAL,
			OOP,
			FUNCTIONAL
		} Key;

		unsigned int YearOfDevelopment;
		unsigned long long int Reference;
	};

	Language* Language_Input(ifstream& FileInput);
	void Language_Output(Language& Obj, ofstream& FileOutput);

	int Past_Years(Language& Obj);
	bool Compare(Language* First, Language* Second);
}

#endif