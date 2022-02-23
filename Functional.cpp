#include "Functional.h"
#include <string>

bool Skobina::Functional_Input(Functional& obj, ifstream& fin)
{
	string temp;
	fin >> temp;
	if (temp == "\0")
	{
		return false;
	}
	if (temp.length() > 1)
	{
		getline(fin, temp, '\n');
		return false;
	}
	if (!isdigit(int(unsigned char(temp.front()))))
	{
		getline(fin, temp, '\n');
		return false;
	}

	int state = stoi(temp);
	if (state > 0)
	{
		obj.lazy_calculations = true;
	}
	else
	{
		obj.lazy_calculations = false;
	}

	fin >> temp;
	if (temp == "\0")
	{
		return false;
	}
	if (temp.length() > 1)
	{
		return false;
	}
	if (!isdigit(int(unsigned char(temp.front()))))
	{
		return false;
	}

	state = stoi(temp);
	switch (state)
	{
	case 1:
		obj.type = Functional::typification::STRICT;
		return true;
	case 2:
		obj.type = Functional::typification::DYNAMIC;
		return true;
	default:
		return false;
	}
}

void Skobina::Functional_Output(Functional& obj, ofstream& fout)
{
	fout << "It is Functional programming language: Support \"lazy\" calculations is ";
	if (obj.lazy_calculations)
	{
		fout << "present, ";
	}
	else
	{
		fout << "missing, ";
	}
	fout << "Typification is ";
	switch (obj.type)
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