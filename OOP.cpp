#include "OOP.h"
#include <string>

bool Skobina::Object_Oriented_Input(Object_Oriented& obj, ifstream& fin)
{
	string temp;
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

	int state = stoi(temp);
	switch (state)
	{
	case 1:
		obj.number = Object_Oriented::inheritance::SINGLE;
		return true;
	case 2:
		obj.number = Object_Oriented::inheritance::MULTIPLE;
		return true;
	case 3:
		obj.number = Object_Oriented::inheritance::INTERFACE;
		return true;
	default:
		return false;
	}
}

void Skobina::Object_Oriented_Output(Object_Oriented& obj, ofstream& fout)
{
	fout << "It is Object-oriented programming language: Inheritance is ";
	switch (obj.number)
	{
	case Object_Oriented::inheritance::SINGLE:
		fout << "single, ";
		break;
	case Object_Oriented::inheritance::MULTIPLE:
		fout << "multiple, ";
		break;
	case Object_Oriented::inheritance::INTERFACE:
		fout << "interface, ";
		break;
	default:
		break;
	}
}