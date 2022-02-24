#define _CRT_SECURE_NO_WARNINGS
#include "Language.h"
#include <ctime>
#include <string>

Skobina::Language* Skobina::Language_Input(ifstream& FileInput)
{
	Language* Langua = new Language;
	Procedural* Proc;
	Object_Oriented* Oop;
	Functional* Func;

	string TempString;

	FileInput >> TempString;
	if (TempString == "\0") // проверка на конец строки
	{
		return NULL;
	}
	if (TempString.length() > 1) // проверка на длину строки
	{
		FileInput.get();
		getline(FileInput, TempString, '\n'); // пропуск оставшихся данных
		return NULL;
	}
	if (!isdigit(int(unsigned char(TempString.front())))) // проверка на ввод цифры
	{
		FileInput.get();
		getline(FileInput, TempString, '\n'); // пропуск оставшихся данных
		return NULL;
	}
	int State = stoi(TempString);

	getline(FileInput, TempString, '\n'); // пропуск оставшихся данных

	FileInput >> TempString;
	if (TempString == "\0") // проверка на конец строки
	{
		return NULL;
	}
	if (TempString.length() != 4) // проверка на длину строки
	{
		getline(FileInput, TempString, '\n'); // пропуск оставшихся данных
		return NULL;
	}
	for (auto iter = TempString.begin(); iter != TempString.end(); ++iter)
	{
		if (!isdigit(int(unsigned char(*iter)))) // проверка на ввод цифры
		{
			getline(FileInput, TempString, '\n'); // пропуск оставшихся данных
			return NULL;
		}
	}
	Langua->YearOfDevelopment = stoul(TempString);

	FileInput >> TempString;
	if (TempString == "\0") // проверка на конец строки
	{
		return NULL;
	}
	for (auto iter = TempString.begin(); iter != TempString.end(); ++iter)
	{
		if (!isdigit(int(unsigned char(*iter)))) // проверка на ввод цифры
		{
			getline(FileInput, TempString, '\n'); // пропуск оставшихся данных
			return NULL;
		}
	}
	Langua->Reference = stoull(TempString);

	switch (State)
	{
	case 1:
		Proc = new Procedural;
		Langua->Key = Language::Lang::PROCEDURAL;
		Proc = (Procedural*)Langua;

		if (!Procedural_Input(*Proc, FileInput))
		{
			return NULL;
		}
		else
		{
			return Langua;
		}
	case 2:
		Oop = new Object_Oriented;
		Langua->Key = Language::Lang::OOP;
		Oop = (Object_Oriented*)Langua;

		if (!Object_Oriented_Input(*Oop, FileInput))
		{
			return NULL;
		}
		else
		{
			return Langua;
		}
	case 3:
		Func = new Functional;
		Langua->Key = Language::Lang::FUNCTIONAL;
		Func = (Functional*)Langua;

		if (!Functional_Input(*Func, FileInput))
		{
			return NULL;
		}
		else
		{
			return Langua;
		}
	default:
		getline(FileInput, TempString, '\n'); // пропуск оставшихся данных
		return NULL;
	}
}


void Skobina::Language_Output(Language& Obj, ofstream& FileOutput)
{
	switch (Obj.Key)
	{
	case Language::Lang::PROCEDURAL:
		Procedural_Output((Procedural&)Obj, FileOutput);
		break;
	case Language::Lang::OOP:
		Object_Oriented_Output((Object_Oriented&)Obj, FileOutput);
		break;
	case Language::Lang::FUNCTIONAL:
		Functional_Output((Functional&)Obj, FileOutput);
		break;
	default:
		FileOutput << "Incorrect programming language" << endl;
		return;
	}

	FileOutput << "Year of development = " << Obj.YearOfDevelopment
		<< ", The number of references of this language on the Internet = " << Obj.Reference << endl;
}


int Skobina::Past_Years(Language& obj)
{
	time_t now = time(NULL);
	tm* localtm = localtime(&now);
	return 1900 + localtm->tm_year - obj.YearOfDevelopment;
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