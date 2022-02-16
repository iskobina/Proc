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
		fout << "The number of years that have passed since the year the language was created = "
			<< Past_Years(Temp->language) << endl;
		Temp = Temp->Next;
	}
	fout << endl;
}

<<<<<<< HEAD
void Skobina::Sort_List(LinkedList& obj) //передаем весь список в функцию сортировки
{
	if (obj.SizeList < 2) //сортировать список из 1 элемента нет смысла
		return;

	Node* current = obj.First; //создаем указатель на первый элемент в списке

	bool flag = false;

	do
	{
		current = obj.First;
		flag = false;
		for (size_t i = 0; i < (obj.SizeList - 1); ++i) //от 0 до конца списка
		{
			if (Compare(current->language, current->Next->language)) //если функция compare возвращает true (если необходимо поменять местами)
			{
				Swap(obj, current, current->Next); //передаем в функцию весь список, текущий элемент и следующий
				flag = true;
			}
			else
			{
				current = current->Next; //если не надо менять, то переходим к следующему элементу
			}
		}
	} while (flag);
}

void Skobina::Swap(LinkedList& obj, Node* first, Node* second) //меняем указатели
{
	if ((first->Prev == NULL) && (second->Next == NULL)) //если всего 2 элемента в списке
	{
		obj.First = second;
		obj.Last = first;
		first->Prev = second;
		second->Next = first;
		first->Next = NULL;
		second->Prev = NULL;
		return;
	}
	if ((first->Prev == NULL) && (second->Next != NULL)) //если в списке более 2-ух элементов, и мы рассматриваем 1 и 2 элементы
	{
		first->Next = second->Next;
		first->Prev = second;
		second->Next->Prev = first;
		second->Next = first;
		second->Prev = NULL;
		obj.First = second;
		return;
	}
	if ((first->Prev != NULL) && (second->Next == NULL)) //если в списке более 2-ух элементов, и мы рассматриваем предпоследний и последний
	{
		second->Prev = first->Prev;
		first->Prev = second;
		first->Next = NULL;
		second->Next = first;
		second->Prev->Next = second;
		obj.Last = first;
		return;
	}
	if ((first->Prev != NULL) && (second->Next != NULL)) //если в списке более 2-ух элементов и мы где-то по-середине
	{
		first->Next = second->Next;
		second->Prev = first->Prev;
		second->Next = first;
		first->Prev = second;
		second->Prev->Next = second;
		first->Next->Prev = first;
		return;
	}
=======
void Skobina::Only_Procedural(LinkedList& obj, ofstream& fout)
{
	Node* current = obj.First;
	fout << "Only Procedural languages." << endl;

	for (size_t i = 0; i < obj.SizeList; i++)
	{
		fout << i + 1 << ": ";
		if (current->language->key == Language::lang::PROC)
		{
			Language_Output(current->language, fout);
		}
		else
		{
			fout << endl;
		}
		current = current->Next;
	}

	fout << endl;
>>>>>>> lab2.5
}