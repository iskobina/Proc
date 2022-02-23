#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Language.h"

namespace Skobina
{
	struct Node
	{
		Language* language;
		Node* next;
		Node* prev;
	};

	struct Linked_List
	{
		Node* head;
		Node* tail;
		size_t size_list;
	};

	void Init(Linked_List& obj); // конструктор
	void Clear(Linked_List& obj); // деструктор

	void Linked_List_Input(Linked_List& obj, ifstream& fin);
	void Linked_List_Output(Linked_List& obj, ofstream& fout);
	void Only_Procedural(Linked_List& obj, ofstream& fout);

	void Sort_List(Linked_List& obj); // функция сортировки списка

	void Swap(Linked_List& obj, Node* first, Node* second); // вспомогательная функция сортировки списка
}

#endif