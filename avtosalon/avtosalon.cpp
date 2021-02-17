#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Avto
{
	string m_Name;
	short m_Year;
	float m_EngCap;
	int m_Price;
public:
	Avto(string name, short year, float dvug, int price) :m_Name(name), m_Year(year), m_EngCap(dvug), m_Price(price) {}
	void Info()
	{
		cout << "===============\n";
		cout << "Avto: " << m_Name << " | ";
		cout << "Year: " << m_Year << " | ";
		cout << "Engine capacity: " << m_EngCap <<" l.  |  ";
		cout << "Price: " << m_Price << " euro.  |  \n";
			cout << "====================================\n";
	}
	string& getName() { return m_Name; }
	short& getYear() { return m_Year; }
	float& getEng() { return m_EngCap; }
	int& getPrice() { return m_Price; }
	bool operator==(string find)	{return this->getName() == find;}
	bool operator==(float find){ return this->getEng() == find;}
	bool operator==(short find){return this->getYear() == find;}
	bool operator==(int find){return this->getPrice() == find;}
};
bool SortName(Avto& a1, Avto& a2){return a1.getName() < a2.getName();}
bool SortYear(Avto& a1, Avto& a2){	return a1.getYear() < a2.getYear();}
bool SortEngine(Avto& a1, Avto& a2){return a1.getEng() < a2.getEng();}
bool SortPrice(Avto& a1, Avto& a2){return a1.getPrice() < a2.getPrice();}

class AvtoSalon
{
	vector<Avto>m_Cars;
public:
	AvtoSalon() { m_Cars.clear(); }
	void AddCar(Avto car)
	{
		m_Cars.push_back(car);
	}
	void DeleteCar(string name)
	{
		for (int i = 0; i < m_Cars.size(); i++)
			if (m_Cars[i].getName() == name) m_Cars.erase(m_Cars.begin()+i);
	}
	void ShowAll()
	{
		for (auto &i : m_Cars) i.Info();
	}
	void SortName()
	{
		sort(m_Cars.begin(), m_Cars.end(), ::SortName);
		cout << "Sorting.." << endl;
	}
	void SortYear()
	{
		sort(m_Cars.begin(), m_Cars.end(), ::SortYear);
		cout << "Sorting.." << endl;
	}
	void SortEng()
	{
		sort(m_Cars.begin(), m_Cars.end(), ::SortEngine);
		cout << "Sorting.." << endl;
	}
	void SortPrice()
	{
		sort(m_Cars.begin(), m_Cars.end(), ::SortPrice);
		cout << "Sorting.." << endl;
	}
	void FindAvto(string name)
	{
		if (find(m_Cars.begin(), m_Cars.end(), name) != m_Cars.end())find(m_Cars.begin(), m_Cars.end(), name)->Info();
		else cout << "Not find" << endl;
	}
	void FindYear(short year)
	{
		if (find(m_Cars.begin(), m_Cars.end(), year) != m_Cars.end())find(m_Cars.begin(), m_Cars.end(), year)->Info();
		else cout << "Not find" << endl;
	}
	void FindEngine(float eng)
	{
		if (find(m_Cars.begin(), m_Cars.end(), eng) != m_Cars.end())find(m_Cars.begin(), m_Cars.end(), eng)->Info();
		else cout << "Not find" << endl;
	}
	void FindPrice(int price)
	{
		if (find(m_Cars.begin(), m_Cars.end(), price) != m_Cars.end())find(m_Cars.begin(), m_Cars.end(), price)->Info();
		else cout << "Not find" << endl;
	}

};
int main()
{
	AvtoSalon mySalon;
	bool work = true;
	while(work)
	{ 
	cout << "==============Menu==============\n";
	cout << "1 - Add Car | 2 - remove Car | 3 - Show all | 4 - Sort | 5 - Find | 6 - Exit" << endl;
	int x = 0;
	cin >> x;
	cin.ignore();
	switch (x)
	{
	case 1:
	{
		string name; short year; float engine; int price;
		cout << "Enter the name of avto: ";
		getline(cin, name);
		cout << "Enter the year: ";
		cin >> year;
		cout << "Enter the Engine capacity: ";
		cin >> engine;
		cout << "Enter the price in euro: ";
		cin >> price;
		mySalon.AddCar(Avto(name, year, engine, price));
		break;
	}
	case 2:
	{
		cout << "Enter the name car to delete: ";
		string name; getline(cin, name);
		mySalon.DeleteCar(name); cout << "delete" << endl;
		break;
	}
	case 3:
	{
		mySalon.ShowAll();
		break;
	}
	case 4:
	{
		int x = 0;
		cout << "Sort name - 1 | Sort year - 2 | Sort capacity engine - 3 | Sort price - 4" << endl;
		cin >> x;
		switch (x)
		{
		case 1: mySalon.SortName(); mySalon.ShowAll(); break;
		case 2:mySalon.SortYear(); mySalon.ShowAll(); break;
		case 3:mySalon.SortEng(); mySalon.ShowAll(); break;
		case 4:mySalon.SortPrice(); mySalon.ShowAll(); break;
		default: cout << "Incorrect choose" << endl;
		} break;
	}
	case 5:
	{
		int y = 0;
		cout << "Find from name - 1 | Find from year - 2 | Find from capacity engine - 3 | Find from price - 4" << endl;
		cin >> y; ::cin.clear(); ::cin.ignore();
		switch (y)
		{
		case 1:
		{
			cout << "Enter the name to find: "; string str; getline(cin, str);
			mySalon.FindAvto(str); break;
		}
		case 2:
		{
			cout << "Enter the year to find: "; short y = 0;  cin >> y;
			mySalon.FindYear(y); break;
		}
		case 3:
		{
			cout << "Enter the capacity to find: "; float y = 0;  cin >> y;
			mySalon.FindEngine(y);
		}
		case 4:
		{
			cout << "Enter the price to find: "; int y = 0; cin >> y;
			mySalon.FindPrice(y); break;
		}
		default: cout << "Incorrec position" << endl;
		}break; }
	case 6: work = false; break;
	default: cout << "Enter correct choose 1-6" << endl;
	}
	}
	}
