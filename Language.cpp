#define _CRT_SECURE_NO_WARNINGS
#include "Language.h"
#include <ctime>
#include <string>

Skobina::Language* Skobina::Language_Input(ifstream& fin)
{
	Language* language = new Language;
	Procedural* proc;
	Object_Oriented* oop;
	Functional* func;

	string temp;
	fin >> temp;
	if (temp == "\0") // проверка на конец строки
	{
		return NULL;
	}
	if (temp.length() > 1) // проверка на длину строки
	{
		fin.get();
		getline(fin, temp, '\n'); // пропуск оставшихся данных
		return NULL;
	}
	if (!isdigit(int(unsigned char(temp.front())))) // проверка на ввод цифры
	{
		fin.get();
		getline(fin, temp, '\n'); // пропуск оставшихся данных
		return NULL;
	}
	int state = stoi(temp);

	getline(fin, temp, '\n'); // пропуск оставшихся данных

	fin >> temp;
	if (temp == "\0") // проверка на конец строки
	{
		return NULL;
	}
	if (temp.length() != 4) // проверка на длину строки
	{
		getline(fin, temp, '\n'); // пропуск оставшихся данных
		return NULL;
	}
	for (auto iter = temp.begin(); iter != temp.end(); ++iter)
	{
		if (!isdigit(int(unsigned char(*iter)))) // проверка на ввод цифры
		{
			getline(fin, temp, '\n'); // пропуск оставшихся данных
			return NULL;
		}
	}
	language->year_of_development = stoul(temp);

	fin >> temp;
	if (temp == "\0") // проверка на конец строки
	{
		return NULL;
	}
	for (auto iter = temp.begin(); iter != temp.end(); ++iter)
	{
		if (!isdigit(int(unsigned char(*iter)))) // проверка на ввод цифры
		{
			getline(fin, temp, '\n'); // пропуск оставшихся данных
			return NULL;
		}
	}
	language->reference = stoull(temp);

	switch (state)
	{
	case 1:
		proc = new Procedural;
		language->key = Language::lang::PROCEDURAL;
		proc = (Procedural*)language;
		if (!Procedural_Input(*proc, fin))
		{
			return NULL;
		}
		else
		{
			return language;
		}
	case 2:
		oop = new Object_Oriented;
		language->key = Language::lang::OOP;
		oop = (Object_Oriented*)language;
		if (!Object_Oriented_Input(*oop, fin))
		{
			return NULL;
		}
		else
		{
			return language;
		}
	case 3:
		func = new Functional;
		language->key = Language::lang::FUNCTIONAL;
		func = (Functional*)language;
		if (!Functional_Input(*func, fin))
		{
			return NULL;
		}
		else
		{
			return language;
		}
	default:
		getline(fin, temp, '\n'); // пропуск оставшихся данных
		return NULL;
	}
}

void Skobina::Language_Output(Language& obj, ofstream& fout)
{
	switch (obj.key)
	{
	case Language::lang::PROCEDURAL:
		Procedural_Output((Procedural&)obj, fout);
		break;
	case Language::lang::OOP:
		Object_Oriented_Output((Object_Oriented&)obj, fout);
		break;
	case Language::lang::FUNCTIONAL:
		Functional_Output((Functional&)obj, fout);
		break;
	default:
		fout << "Incorrect programming language" << endl;
		return;
	}
	fout << "Year of development = " << obj.year_of_development
		<< ", The number of references of this language on the Internet = " << obj.reference << endl;
}

int Skobina::Past_Years(Language& obj)
{
	time_t now = time(NULL);
	tm* localtm = localtime(&now);
	return 1900 + localtm->tm_year - obj.year_of_development;
}

bool Skobina::Compare(Language* first, Language* second)
{
	if (first == NULL && second != NULL)
	{
		return true;
	}
	if (first != NULL && second == NULL)
	{
		return false;
	}
	if (first == NULL && second == NULL)
	{
		return false;
	}
	if (first != NULL && second != NULL)
	{
		return Past_Years(*first) < Past_Years(*second);
	}
}