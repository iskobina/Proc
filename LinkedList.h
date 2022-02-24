#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Language.h"

namespace Skobina
{
	struct Node
	{
		Language* Langu;
		Node* Next;
		Node* Previous;
	};

	struct Linked_List
	{
		Node* Head;
		Node* Tail;
		size_t SizeLinkedList;
	};

	void Init(Linked_List& Obj); // конструктор
	void Clear(Linked_List& Obj); // деструктор

	void Linked_List_Input(Linked_List& Obj, ifstream& FileInput);
	void Linked_List_Output(Linked_List& Obj, ofstream& FileOutput);
	void Linked_List_Output_Only_Procedural(Linked_List& Obj, ofstream& FileOutput);

	void Sort_List(Linked_List& Obj); // функция сортировки списка

	void Swap(Linked_List& Obj, Node* First, Node* Second); // вспомогательная функция сортировки списка
}

#endif