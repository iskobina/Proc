#include "LinkedList.h"

void Skobina::Init(Linked_List& obj) // конструктор
{
	obj.head = NULL;
	obj.tail = NULL;
	obj.size_list = 0;
}

void Skobina::Clear(Linked_List& obj) // деструктор
{
	Node* temp = NULL;
	while (obj.tail != NULL)
	{
		temp = obj.tail->prev;
		delete obj.tail;
		obj.tail = temp;
		--obj.size_list;
	}
	obj.head = temp;
}

void Skobina::Linked_List_Input(Linked_List& obj, ifstream& fin)
{
	Node* temp;
	while (!fin.eof())
	{
		temp = new Node;

		temp->language = Language_Input(fin); // заполнение блока данных
		temp->next = NULL;
		++obj.size_list;

		if (obj.head == NULL)
		{
			temp->prev = NULL;
			obj.head = obj.tail = temp;
		}
		else
		{
			temp->prev = obj.tail;
			obj.tail->next = temp;
			obj.tail = temp;
		}
	}
}

void Skobina::Linked_List_Output(Linked_List& obj, ofstream& fout)
{
	Node* current = obj.head; // создание указателя на первый элемент
	fout << "Container contains " << obj.size_list << " elements." << endl;

	for (size_t i = 0; i < obj.size_list; i++)
	{
		fout << i + 1 << ": ";
		if (current->language == NULL)
		{
			fout << "Error reading data! Expected other values in the string." << endl;
		}
		else
		{
			Language_Output(*current->language, fout);
			fout << "The number of years that have passed since the year the language was created = "
				<< Past_Years(*current->language) << endl;
		}
		current = current->next;
	}
}

void Skobina::Sort_List(Linked_List& obj) // функция сортировки списка
{
	if (obj.size_list < 2) // список с одним элементом не сортируется
	{
		return;
	}

	Node* current = obj.head;
	bool flag = false;

	do
	{
		current = obj.head;
		flag = false;
		for (size_t i = 0; i < (obj.size_list - 1); ++i)
		{
			if (Compare(current->language, current->next->language))
			{
				Swap(obj, current, current->next);
				flag = true;
			}
			else
			{
				current = current->next;
			}
		}
	} while (flag);
}

void Skobina::Swap(Linked_List& obj, Node* first, Node* second)
{
	if ((first->prev == NULL) && (second->next == NULL)) // если всего 2 элемента в списке
	{
		obj.head = second;
		obj.tail = first;
		first->prev = second;
		second->next = first;
		first->next = NULL;
		second->prev = NULL;
		return;
	}
	if ((first->prev == NULL) && (second->next != NULL))
	{
		first->next = second->next;
		first->prev = second;
		second->next->prev = first;
		second->next = first;
		second->prev = NULL;
		obj.head = second;
		return;
	}
	if ((first->prev != NULL) && (second->next == NULL))
	{
		second->prev = first->prev;
		first->prev = second;
		first->next = NULL;
		second->next = first;
		second->prev->next = second;
		obj.tail = first;
		return;
	}
	if ((first->prev != NULL) && (second->next != NULL))
	{
		first->next = second->next;
		second->prev = first->prev;
		second->next = first;
		first->prev = second;
		second->prev->next = second;
		first->next->prev = first;
		return;
	}
}

void Skobina::Only_Procedural(Linked_List& obj, ofstream& fout)
{
	Node* current = obj.head;
	fout << endl << "Only Procedural languages." << endl;

	for (size_t i = 0; i < obj.size_list; i++)
	{
		fout << i + 1 << ": ";
		if (current->language == NULL)
		{
			fout << endl;
			continue;
		}
		if (current->language->key == Language::lang::PROCEDURAL)
		{
			Language_Output(*current->language, fout);
		}
		else
		{
			fout << endl;
		}
		current = current->next;
	}
	fout << endl;
}