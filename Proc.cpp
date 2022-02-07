#include "Proc.h"

Skobina::Proc* Skobina::Proc_Input(Proc& obj, ifstream& fin)
{
	fin >> obj.abstract_type;
	return &obj;
}

void Skobina::Proc_Output(Proc* obj, ofstream& fout)
{
	fout << "It is Procedural programming language: Abstract data types is ";
	if (obj->abstract_type)
	{
		fout << "present, ";
	}
	else
	{
		fout << "missing, ";
	}
}