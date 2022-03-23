#include "LinkedList.h"

void Skobina::Init(Linked_List& Obj) // конструктор
{
	Obj.Head = NULL;
	Obj.Tail = NULL;
	Obj.SizeLinkedList = 0;
}


void Skobina::Clear(Linked_List& Obj) // деструктор
{
	Node* TempNode = NULL;

	while (Obj.Tail != NULL)
	{
		TempNode = Obj.Tail->Previous;
		delete Obj.Tail;
		Obj.Tail = TempNode;
		--Obj.SizeLinkedList;
	}
	Obj.Head = TempNode;
}


void Skobina::Linked_List_Input(Linked_List& Obj, ifstream& FileInput)
{
	Node* TempNode;

	while (!FileInput.eof())
	{
		TempNode = new Node;

		TempNode->Langu = Language_Input(FileInput); // заполнение блока данных
		TempNode->Next = NULL;
		++Obj.SizeLinkedList;

		if (Obj.Head == NULL)
		{
			TempNode->Previous = NULL;
			Obj.Head = Obj.Tail = TempNode;
		}
		else
		{
			TempNode->Previous = Obj.Tail;
			Obj.Tail->Next = TempNode;
			Obj.Tail = TempNode;
		}
	}
}


void Skobina::Linked_List_Output(Linked_List& Obj, ofstream& FileOutput)
{
	Node* TempNode = Obj.Head; // создание указателя на первый элемент
	FileOutput << "Container contains " << Obj.SizeLinkedList << " elements." << endl;

	for (size_t i = 0; i < Obj.SizeLinkedList; i++)
	{
		FileOutput << i + 1 << ": ";
		if (TempNode->Langu == NULL)
		{
			FileOutput << "Error reading data! Expected other values in the string." << endl;
		}
		else
		{
			Language_Output(*TempNode->Langu, FileOutput);
			FileOutput << "The number of years that have passed since the year the language was created = "
				<< Past_Years(*TempNode->Langu) << endl;
		}
		TempNode = TempNode->Next;
	}
}


void Skobina::Sort_List(Linked_List& Obj) // функция сортировки списка
{
	if (Obj.SizeLinkedList < 2) // список с одним элементом не сортируется
	{
		return;
	}

	Node* TempNode = Obj.Head;
	bool Flag = false;

	do
	{
		TempNode = Obj.Head;
		Flag = false;

		for (size_t i = 0; i < (Obj.SizeLinkedList - 1); ++i)
		{
			if (Compare(TempNode->Langu, TempNode->Next->Langu))
			{
				Swap(Obj, TempNode, TempNode->Next);
				Flag = true;
			}
			else
			{
				TempNode = TempNode->Next;
			}
		}
	} while (Flag);
}


void Skobina::Swap(Linked_List& Obj, Node* First, Node* Second)
{
	if ((First->Previous == NULL) && (Second->Next == NULL)) // если всего 2 элемента в списке
	{
		Obj.Head = Second;
		Obj.Tail = First;
		First->Previous = Second;
		Second->Next = First;
		First->Next = NULL;
		Second->Previous = NULL;
		return;
	}
	if ((First->Previous == NULL) && (Second->Next != NULL))
	{
		First->Next = Second->Next;
		First->Previous = Second;
		Second->Next->Previous = First;
		Second->Next = First;
		Second->Previous = NULL;
		Obj.Head = Second;
		return;
	}
	if ((First->Previous != NULL) && (Second->Next == NULL))
	{
		Second->Previous = First->Previous;
		First->Previous = Second;
		First->Next = NULL;
		Second->Next = First;
		Second->Previous->Next = Second;
		Obj.Tail = First;
		return;
	}
	if ((First->Previous != NULL) && (Second->Next != NULL))
	{
		First->Next = Second->Next;
		Second->Previous = First->Previous;
		Second->Next = First;
		First->Previous = Second;
		Second->Previous->Next = Second;
		First->Next->Previous = First;
		return;
	}
}


void Skobina::Linked_List_Output_Only_Procedural(Linked_List& Obj, ofstream& FileOutput)
{
	Node* TempNode = Obj.Head;
	FileOutput << endl << "Only Procedural languages." << endl;

	for (size_t i = 0; i < Obj.SizeLinkedList; i++)
	{
		FileOutput << i + 1 << ": ";
		if (TempNode->Langu == NULL)
		{
			FileOutput << endl;
			continue;
		}
		if (TempNode->Langu->Key == Language::Lang::PROCEDURAL)
		{
			Language_Output(*TempNode->Langu, FileOutput);
		}
		else
		{
			FileOutput << endl;
		}
		TempNode = TempNode->Next;
	}
	FileOutput << endl;
}


void Skobina::Multi_Method(Linked_List& obj, ofstream& fout)
{
	Node* current_first = obj.Head;
	Node* current_second = current_first->Next;

	fout << endl << "Multimethod." << endl;
	for (size_t i = 0; i < obj.SizeLinkedList - 1; i++)
	{
		for (size_t j = i + 1; j < obj.SizeLinkedList; j++)
		{
			switch (current_first->Langu->Key)
			{
			case Language::Lang::PROCEDURAL:
				switch (current_second->Langu->Key)
				{
				case Language::Lang::PROCEDURAL:
					fout << "Procedural and Procedural." << endl;
					break;
				case Language::Lang::OOP:
					fout << "Procedural and OOP." << endl;
					break;
				case Language::Lang::FUNCTIONAL:
					fout << "Procedural and Functional." << endl;
					break;
				default:
					fout << "Unknown type." << endl;
					break;
				}
				break;
			case Language::Lang::OOP:
				switch (current_second->Langu->Key)
				{
				case Language::Lang::PROCEDURAL:
					fout << "OOP and Procedural." << endl;
					break;
				case Language::Lang::OOP:
					fout << "OOP and OOP." << endl;
					break;
				case Language::Lang::FUNCTIONAL:
					fout << "OOP and Functional." << endl;
					break;
				default:
					fout << "Unknown type." << endl;
					break;
				}
				break;
			case Language::Lang::FUNCTIONAL:
				switch (current_second->Langu->Key)
				{
				case Language::Lang::PROCEDURAL:
					fout << "Functional and Procedural." << endl;
					break;
				case Language::Lang::OOP:
					fout << "Functional and OOP." << endl;
					break;
				case Language::Lang::FUNCTIONAL:
					fout << "Functional and Functional." << endl;
					break;
				default:
					fout << "Unknown type." << endl;
					break;
				}
				break;
			default:
				fout << "Unknown type." << endl;
				break;
			}
			Language_Output(*current_first->Langu, fout);
			Language_Output(*current_second->Langu, fout);
			current_second = current_second->Next;
		}
		current_first = current_first->Next;
		current_second = current_first->Next;
	}
}