#include <iostream>
#define MAX_ELEMENTS_OF_LIST 5
using namespace std;

template<typename T>
class List
{
	template<typename T1>
	struct Elem
	{
		T1 data;
		Elem* next, * prev;
	};
	Elem<T>* m_Head, * m_Tail;
	int m_Count;
public:
	List();
	List(const List&);
	void DelAll();
	void Del(int pos = 0);
	void Insert(int pos, T data);
	void AddTail(T n);
	void AddHead(T n);
	void Print();
};
template<typename T>
void List<T>::Print()
{
	try {
		if (m_Count == 0) throw "LIST IS EMPTY";
		{
			Elem<T>* temp = m_Head;
			cout << "( ";
			while (temp->next != 0)
			{
				cout << temp->data << ", ";
				temp = temp->next;
			}
			cout << temp->data << " )\n";
		}
	}
	catch (const char* k) { cout << k << endl; }
}
template<typename T>
List<T>::List()
{
	m_Head = m_Tail = NULL;
	m_Count = 0;
}
template<typename T>
List<T>::List(const List& L)
{
	m_Head = m_Tail = NULL;
	m_Count = 0;
	Elem* temp = L.Head;
	while (temp != 0)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
}
template<typename T>
void List<T>::Del(int pos)
{
	try
	{
		if (pos == 0)
		{
			cout << "Input position: ";
			cin >> pos;
		}

		if (pos < 1 || pos > m_Count)
			throw "Incorrect position";

		int i = 1;
		Elem<T>* Del = m_Head;
		while (i < pos)
		{

			Del = Del->next;
			i++;
		}

		Elem<T>* PrevDel = Del->prev;

		Elem<T>* AfterDel = Del->next;

		if (PrevDel != 0 && m_Count != 1)
			PrevDel->next = AfterDel;

		if (AfterDel != 0 && m_Count != 1)
			AfterDel->prev = PrevDel;

		if (pos == 1)
			m_Head = AfterDel;
		if (pos == m_Count)
			m_Tail = PrevDel;

		delete Del;
		m_Count--;
	}
	catch (const char* error) { cout <<"DEl"<< error << endl; }
}
template<typename T>
void List<T>::DelAll()
{
	try {
		while (m_Head != 0)
		{
			Del(1);
			if (m_Count == 0) throw - 1;
		}
		
	}
	catch (...)
	{
		cout << "List is EMPTY!" << endl;
	}
}
template<typename T>
void List<T>::Insert(int pos, T data)
{
	try {
		if ((pos < 1 || pos > m_Count + 1)||m_Count>=MAX_ELEMENTS_OF_LIST)
		{
			throw - 1;
		}
		if (pos == m_Count + 1)
		{
			AddTail(data);
			return;
		}
		else if (pos == 1)
		{
			AddHead(data);
			return;
		}
		int i = 1;
		Elem<T>* Ins = m_Head;
		while (i < pos)
		{
			Ins = Ins->next;
			i++;
		}

		Elem<T>* PrevIns = Ins->prev;

		Elem<T>* temp = new Elem<T>;
		temp->data = data;

		if (PrevIns != 0 && m_Count != 1)
			PrevIns->next = temp;
		temp->next = Ins;
		temp->prev = PrevIns;
		Ins->prev = temp;
		m_Count++;
	}
	catch(...)
	{
		cout << "Incorrect position!" << endl;
	}
}
template<typename T>
void List<T>::AddTail(T n)
{
	try{
		if (m_Count == MAX_ELEMENTS_OF_LIST) throw "There is no place to element";
	Elem<T>* temp = new Elem<T>;

	temp->next = 0;

	temp->data = n;

	temp->prev = m_Tail;

	if (m_Tail != 0)
		m_Tail->next = temp;

	if (m_Count == 0)
		m_Head = m_Tail = temp;
	else
		m_Tail = temp;
	m_Count++;
}
	catch (const char* error) { cout << error << endl; }
}
template<typename T>
void List<T>::AddHead(T n)
{
	try{
		if (m_Count == MAX_ELEMENTS_OF_LIST) throw "There is no place to element";
	Elem<T>* temp = new Elem<T>;

	temp->prev = 0;

	temp->data = n;

	temp->next = m_Head;

	if (m_Head != 0)
		m_Head->prev = temp;

	if (m_Count == 0)
		m_Head = m_Tail = temp;
	else

		m_Head = temp;
	m_Count++;
}
	catch (const char* error) { cout <<"Error: "<< error << endl; }
}
int main()

{
	List<char> Name;
	Name.Print();
	Name.AddHead('T');
	Name.AddTail('A');
	Name.AddTail('R');
	Name.AddTail('A');
	Name.AddTail('S');
	Name.Print();
	Name.AddHead('s');
	Name.AddTail('d');
	Name.Insert(2, 'r');
	Name.Del(6);
	Name.DelAll();
	Name.DelAll();
	Name.Insert(2, 'r');
	Name.AddHead('T');
}