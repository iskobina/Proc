#include "LinkedList.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace Skobina;

int main(int argc, char* argv[])
{
	if (argc != 3) // проверка на передачу в программу корректных параметров
	{
		cout << "incorrect command line! "
			"Waited: command infile outfile" << endl;
		exit(1);
	}

	ifstream fin(argv[1]);
	if (!fin.is_open()) // проверка на доступ к файлу
	{
		cout << "No input file found or could not open!" << endl;
		system("pause");
		return 1;
	}

	ofstream fout(argv[2]);
	if (!fout.is_open()) // проверка на доступ к файлу
	{
		cout << "No output file found or could not open!" << endl;
		system("pause");
		return 1;
	}

	cout << "Start" << endl;

	Linked_List list;
	Init(list);
	Linked_List_Input(list, fin); // создание связного списка и его заполнение
	fout << "Filled container." << endl;
	Linked_List_Output(list, fout); // вывод в файл

	fout << endl << "Sorted Linked List." << endl;
	Sort_List(list); // сортировка списка
	Linked_List_Output(list, fout); // вывод в файл отсортированного списка

	Multi_Method(list, fout);

	Linked_List_Output_Only_Procedural(list, fout); // фильтрованный вывод в файл

	Clear(list); // вызов деструктора
	fout << "Empty container." << endl;
	Linked_List_Output(list, fout);

	cout << "Stop" << endl;
	return 0;
}