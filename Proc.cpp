#include "Proc.h"
#include <string>

bool Skobina::Procedural_Input(Procedural& obj, ifstream& fin)
{
	string temp;
	fin >> temp;
	if (temp == "\0") // проверка на конец строки
	{
		return false;
	}
	if (temp.length() > 1) // проверка на длину строки
	{
		return false;
	}
	if (!isdigit(int(unsigned char(temp.front())))) // проверка на ввод цифры
	{
		return false;
	}

	int state = stoi(temp);

	getline(fin, temp, '\n'); // пропуск оставшихся данных

	if (state > 0)
	{
		obj.abstract_type = true;
	}
	else
	{
		obj.abstract_type = false;
	}
	return true;
}

void Skobina::Procedural_Output(Procedural& obj, ofstream& fout)
{
	fout << "It is Procedural programming language: Abstract data types is ";
	if (obj.abstract_type)
	{
		fout << "present, ";
	}
	else
	{
		fout << "missing, ";
	}
}