#include "Proc.h"
#include <string>

bool Skobina::Procedural_Input(Procedural& Obj, ifstream& FileInput)
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

	if (State > 0)
	{
		Obj.AbstractType = true;
	}
	else
	{
		Obj.AbstractType = false;
	}
	return true;
}


void Skobina::Procedural_Output(Procedural& Obj, ofstream& FileOutput)
{
	FileOutput << "It is Procedural programming language: Abstract data types is ";
	if (Obj.AbstractType)
	{
		FileOutput << "present, ";
	}
	else
	{
		FileOutput << "missing, ";
	}
}