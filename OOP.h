#ifndef OOP_H
#define OOP_H

#include <fstream>

using namespace std;

namespace Skobina
{
	struct Object_Oriented
	{
		enum lang
		{
			PROCEDURAL,
			OOP,
			FUNCTIONAL
		} key;
		unsigned int year_of_development;
		unsigned long long int reference;
		enum inheritance
		{
			SINGLE,
			MULTIPLE,
			INTERFACE
		} number;
	};

	bool Object_Oriented_Input(Object_Oriented& obj, ifstream& fin);
	void Object_Oriented_Output(Object_Oriented& obj, ofstream& fout);
}

#endif