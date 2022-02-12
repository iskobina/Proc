#include "Functional.h"

Skobina::Functional* Skobina::Functional_Input(Functional& obj, ifstream& fin)
{
	unsigned short int temp;
	fin >> obj.lazy_calculations;
	fin >> temp;
	switch (temp)
	{
	case 1:
		obj.type = Functional::typification::STRICT;
		return &obj;
	case 2:
		obj.type = Functional::typification::DYNAMIC;
		return &obj;
	default:
		return NULL;
	}
}

void Skobina::Functional_Output(Functional* obj, ofstream& fout)
{
	fout << "It is Functional programming language: Support \"lazy\" calculations is ";
	if (obj->lazy_calculations)
	{
		fout << "present, ";
	}
	else
	{
		fout << "missing, ";
	}
	fout << "Typification is ";
	switch (obj->type)
	{
	case Functional::typification::STRICT:
		fout << "strict, ";
		break;
	case Functional::typification::DYNAMIC:
		fout << "dynamic, ";
		break;
	default:
		break;
	}
}