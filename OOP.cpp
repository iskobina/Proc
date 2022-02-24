#include "OOP.h"
#include <string>

bool Skobina::Object_Oriented_Input(Object_Oriented& Obj, ifstream& FileInput)
{
	string TempString;
	FileInput >> TempString;
	if (TempString == "\0") // проверка на конец строки
	{
		return false;
	}
	if (TempString.length() > 1) // проверка на длину строки
	{
		return false;
	}
	if (!isdigit(int(unsigned char(TempString.front())))) // проверка на ввод цифры
	{
		return false;
	}

	int State = stoi(TempString);

	getline(FileInput, TempString, '\n'); // пропуск оставшихся данных

	switch (State)
	{
	case 1:
		Obj.Number = Object_Oriented::Inheritance::SINGLE;
		return true;
	case 2:
		Obj.Number = Object_Oriented::Inheritance::MULTIPLE;
		return true;
	case 3:
		Obj.Number = Object_Oriented::Inheritance::INTERFACE;
		return true;
	default:
		return false;
	}
}


void Skobina::Object_Oriented_Output(Object_Oriented& Obj, ofstream& FileOutput)
{
	FileOutput << "It is Object-oriented programming language: Inheritance is ";
	switch (Obj.Number)
	{
	case Object_Oriented::Inheritance::SINGLE:
		FileOutput << "single, ";
		break;
	case Object_Oriented::Inheritance::MULTIPLE:
		FileOutput << "multiple, ";
		break;
	case Object_Oriented::Inheritance::INTERFACE:
		FileOutput << "interface, ";
		break;
	default:
		break;
	}
}