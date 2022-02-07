#include "Language.h"

Skobina::Language* Skobina::Language_Input(ifstream& fin)
{
	Language* language = new Language;
	Proc* proc;
	Object_oriented* oop;
	unsigned short int temp;
	fin >> temp;
	fin >> language->year_of_development;
	switch (temp)
	{
	case 1:
		proc = new Proc;
		language->key = Language::lang::PROC;
		proc = (Proc*)language;
		language = (Language*)Proc_Input(*proc, fin);
		return language;
	case 2:
		oop = new Object_oriented;
		language->key = Language::lang::OOP;
		oop = (Object_oriented*)language;
		language = (Language*)Object_oriented_Input(*oop, fin);
		return language;
	default:
		return 0;
	}
}

void Skobina::Language_Output(Language* obj, ofstream& fout)
{
	switch (obj->key)
	{
	case Language::lang::PROC:
		Proc_Output((Proc*)obj, fout);
		break;
	case Language::lang::OOP:
		Object_oriented_Output((Object_oriented*)obj, fout);
		break;
	default:
		fout << "Incorrect programming language" << endl;
		return;
	}
	fout << "Year of development = " << obj->year_of_development << endl;
}