#include "OOP.h"

Skobina::Object_oriented* Skobina::Object_oriented_Input(Object_oriented& obj, ifstream& fin)
{
	unsigned short int temp;
	fin >> temp;
	switch (temp)
	{
	case 1:
		obj.number = Object_oriented::inheritance::SINGLE;
		return &obj;
	case 2:
		obj.number = Object_oriented::inheritance::MULTIPLE;
		return &obj;
	case 3:
		obj.number = Object_oriented::inheritance::INTERFACE;
		return &obj;
	default:
		return NULL;
	}
}

void Skobina::Object_oriented_Output(Object_oriented* obj, ofstream& fout)
{
	fout << "It is Object-oriented programming language: Inheritance is ";
	switch (obj->number)
	{
	case Object_oriented::inheritance::SINGLE:
		fout << "single, ";
		break;
	case Object_oriented::inheritance::MULTIPLE:
		fout << "multiple, ";
		break;
	case Object_oriented::inheritance::INTERFACE:
		fout << "interface, ";
		break;
	default:
		break;
	}
}