#ifndef OOP_H
#define OOP_H

#include <fstream>

using namespace std;

namespace Skobina
{
	struct Object_Oriented
	{
		enum Lang
		{
			PROCEDURAL,
			OOP,
			FUNCTIONAL
		} Key;

		unsigned int YearOfDevelopment;
		unsigned long long int Reference;

		enum Inheritance
		{
			SINGLE,
			MULTIPLE,
			INTERFACE
		} Number;
	};

	bool Object_Oriented_Input(Object_Oriented& Obj, ifstream& FileInput);
	void Object_Oriented_Output(Object_Oriented& Obj, ofstream& FileOutput);
}

#endif