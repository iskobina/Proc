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

	ifstream FileInput(argv[1]);
	if (!FileInput.is_open()) // проверка на доступ к файлу
	{
		cout << "No input file found or could not open!" << endl;
		system("pause");
		return 1;
	}

	ofstream FileOutput(argv[2]);
	if (!FileOutput.is_open()) // проверка на доступ к файлу
	{
		cout << "No output file found or could not open!" << endl;
		system("pause");
		return 1;
	}

	cout << "Start" << endl;

	Linked_List list;
	Init(list);
	Linked_List_Input(list, FileInput); // создание связного списка и его заполнение
	FileOutput << "Filled container." << endl;
	Linked_List_Output(list, FileOutput); // вывод в файл

	FileOutput << endl << "Sorted Linked List." << endl;
	Sort_List(list); // сортировка списка
	Linked_List_Output(list, FileOutput); // вывод в файл отсортированного списка

	Multi_Method(list, FileOutput);

	Linked_List_Output_Only_Procedural(list, FileOutput); // фильтрованный вывод в файл

	Clear(list); // вызов деструктора
	FileOutput << "Empty container." << endl;
	Linked_List_Output(list, FileOutput);

	cout << "Stop" << endl;
	return 0;
}