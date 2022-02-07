#include "LinkedList.h"

void Skobina::Init(LinkedList& obj)
{
	obj.First = NULL;
	obj.Last = NULL;
	obj.SizeList = 0;
}

void Skobina::Clear(LinkedList& obj)
{
	Node* Temp = NULL;
	while (obj.Last != NULL)
	{
		Temp = obj.Last->Prev;
		delete obj.Last;
		obj.Last = Temp;
		--obj.SizeList;
	}
	obj.First = Temp;
}

void Skobina::LinkedList_Input(LinkedList& obj, ifstream& fin)
{
	Node* Temp;
	while (!fin.eof())
	{
		Temp = new Node;

		Temp->Next = NULL;

		Temp->language = Language_Input(fin);

		++obj.SizeList;

		if (obj.First == NULL)
		{
			Temp->Prev = NULL;
			obj.First = obj.Last = Temp;
		}
		else
		{
			Temp->Prev = obj.Last;
			obj.Last->Next = Temp;
			obj.Last = Temp;
		}
	}
}

void Skobina::LinkedList_Output(LinkedList& obj, ofstream& fout)
{
	Node* Temp = obj.First;
	fout << "Container contains " << obj.SizeList << " elements." << endl;

	for (size_t i = 0; i < obj.SizeList; i++)
	{
		fout << i + 1 << ": ";
		Language_Output(Temp->language, fout);
		Temp = Temp->Next;
	}
	fout << endl;
}