#pragma once
#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "Proc.h"
#include "OOP.h"

namespace Skobina
{
	struct Language
	{
		enum lang //перечисление для создания наследования
		{
			PROC,
			OOP
		} key;
		unsigned short int year_of_development;
	};

	Language* Language_Input(ifstream& fin);
	void Language_Output(Language* obj, ofstream& fout);
	int Past_Years(Language* obj);
	bool Compare(Language* first, Language* second);
}

#endif