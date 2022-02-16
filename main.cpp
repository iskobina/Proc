#include "LinkedList.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace Skobina;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "incorrect command line! "
			"Waited: command infile outfile" << endl;
		exit(1);
	}
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);

	cout << "Start" << endl;
	LinkedList list;
	Init(list); //конструктор списка
	LinkedList_Input(list, fin); //заполнение списка
	fout << "Filled container." << endl;
	LinkedList_Output(list, fout); //вывели содержимое контейнера

	fout << endl << "Sorted Linked List." << endl;
	Sort_List(list); //сортируем список
	LinkedList_Output(list, fout); //выводим в файл сортированный спискок
	Only_Procedural(list, fout); //вызов функции фильтрованного вывода

	Clear(list); //деструктор списка
	fout << "Empty container." << endl;
	LinkedList_Output(list, fout); //вывели, что контейнер пустой
	cout << "Stop" << endl;
	return 0;
}