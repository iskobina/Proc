#pragma once
#ifndef OOP_H
#define OOP_H

#include <fstream>

using namespace std;

namespace Skobina
{
	struct Object_oriented
	{
		enum lang //перечисление для создания наследования
		{
			PROC,
			OOP,
			FUNCTIONAL
		} key;
		unsigned short int year_of_development;
		enum inheritance
		{
			SINGLE,
			MULTIPLE,
			INTERFACE
		} number;
	};

	Object_oriented* Object_oriented_Input(Object_oriented& obj, ifstream& fin);
	void Object_oriented_Output(Object_oriented* obj, ofstream& fout);
}

#endif