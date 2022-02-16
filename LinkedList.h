#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Language.h"

namespace Skobina
{
	struct Node
	{
		Language* language;
		Node* Next;
		Node* Prev;
	};

	struct LinkedList
	{
		Node* First;
		Node* Last;
		size_t SizeList;
	};

	void Init(LinkedList& obj);
	void Clear(LinkedList& obj);

	void LinkedList_Input(LinkedList& obj, ifstream& fin);
	void LinkedList_Output(LinkedList& obj, ofstream& fout);

	void Sort_List(LinkedList& obj);
	void Swap(LinkedList& obj, Node* first, Node* second);

	void Only_Procedural(LinkedList& obj, ofstream& fout);
}

#endif