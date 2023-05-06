// lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;

int task_manager()
{
	int task_number;
RENUMBER:	printf("Menu:\n     1.  Task 1\n     2.  Task 2\n     3.  Task 3\n");
	printf("Enter task number you wanna do: ");
	scanf_s("%d", &task_number);
	if (task_number < 1 || task_number > 3)
	{
		system("cls");
		printf("There is only 3 options!\n\n");
		goto RENUMBER;
	}
	return task_number;
}

/*
Задача 1.
Створити клас студент, що має поля: ПІБ(прізвище, ім'я, по-батькові) курс і ідентифікаційний номер.Визначити конструктори, деструктор і функцію друку. 
Створити похідний клас–студент-дипломник,що має тему диплома.Визначити конструктори за замовчуванням і з різним числом параметрів,деструктори,функцію друку.
Визначити функції перепризначення назви диплома та ідентифікаційного номера. 
Написати програму тестування всіх можливостей цього класу.*/
struct PIB
{
	string fname;
	string name;
	string lname;
	PIB() {
		fname = "NoFirstName";
		name = "NoName";
		lname = "NoLastName";
		cout << "Default constructor PIB \n";
	}
	PIB(string fn) {
		fname = "NoFirstName";
		name = fn;
		lname = "NoLastName";
		cout << "Constructor PIB(string fn) \n";
	}
	PIB(string fn[3]) {
		fname = fn[0];
		name = fn[1];
		lname = fn[2];
		cout << "Constructor PIB(string fn[]) \n";
	}
	PIB(const PIB& s) {
		fname = s.fname;
		name = s.name;
		lname = s.lname;
		cout << "Constructor Copy PIB(const PIB &) \n";
	}
	PIB(PIB&& s) {
		fname = s.fname;
		name = s.name;
		lname = s.lname;
		cout << " Constructor Move PIB(PIB &&) \n";
		s.fname = "NoFirstName";
		s.name = "NoName";
		s.lname = "NoLastName";
	}
	PIB(const char* fn, const char* n, const char* ln) {
		fname = fn;
		name = n;
		lname = ln;
		cout << " Constructor PIB(const char * ... ) \n";
	}
	~PIB() {
		cout << "Destructor ~PIB() \n";
	}

	PIB& operator=(const PIB& s)
	{
		fname = s.fname;
		name = s.name;
		lname = s.lname;
		cout << " PIB operator=(PIB &) \n";
		return *this;
	}
	string toString() 
	{
		string ts = "PIB: " + fname + " " + name + " " + lname + " ";
		return ts;
	}
	bool operator==(PIB& b) 
	{
		return name == b.name &&
			fname == b.fname && lname == b.lname ? true : false;

	}
	void Input() 
	{
		cout << "Input fname "; cin >> fname;
		cout << "Input name "; cin >> name;
		cout << "Input lname "; cin >> lname;
	}
	friend ostream& operator<<(ostream& os, PIB& a);
	friend istream& operator>>(istream& os, PIB& a);
};
ostream& operator<<(ostream& os, PIB& a) {
	os << a.fname << endl;
	os << a.name << endl;
	os << a.lname << endl;
	return os;
}
istream& operator>>(istream& is, PIB& a) {
	is >> a.name;
	is >> a.fname;
	is >> a.lname;
	return is;
}

class Student
{
protected:
	// ПІБ(прізвище, ім'я, по-батькові) курс і ідентифікаційний номер
	PIB name;
	int course;
	long long ID;

public:
	//Визначити конструктори, деструктор і функцію друку
	Student() 
	{
		course = 0;
		ID = 0;
		cout << " Default constructor Student() \n";
	}
	Student(int c, long long id, string n)
	{
		course = c;
		ID = id;
		name = n;
		cout << " Constructor Student(int c, long long id, string n) \n";
	}
	Student(int c, long long id, PIB& n)
	{
		course = c;
		ID = id;
		name = n;
		cout << " Constructor Student(int c, long long id, PIB& n) \n";
	}
	//деструктор
	~Student()
	{
		cout << "\tDestructor Student\n";
	}
	//функцію друку
	friend ostream& operator<<(ostream& os, Student& a);
	friend istream& operator>>(istream& os, Student& a);
};
ostream& operator<<(ostream& os, Student& a) {
	os << a.name;
	os << a.course << endl;
	os << a.ID << endl;
	return os;
}
istream& operator>>(istream& is, Student& a) {
	is >> a.name;
	is >> a.course;
	is >> a.ID;
	return is;
}

class Diploma : public Student
{
	//Створити похідний клас–студент-дипломник,що має тему диплома
	string topic;

public:
	//Визначити конструктори за замовчуванням і з різним числом параметрів, деструктори, функцію друку
	Diploma() 
	{
		topic = "NoTopic";
		cout << " Default constructor Diploma() \n";
	}
	Diploma(int c, long long id, string n, string t) : Student(c, id, n) 
	{
		topic = t;
		cout << " Constructor Diploma(int c, long long id, string n, string t) \n";
	}
	Diploma(int c, long long id, PIB& pib, string t) : Student(c, id, pib) 
	{
		topic = t;
		cout << " Constructor Diploma(int c, long long id, PIB& pib, string t) \n";
	}
	//деструктори
	~Diploma() 
	{
		cout << "\tDestructor Diploma\n";
	}
	//функцію друку
	friend ostream& operator<<(ostream& os, Diploma& a);
	friend istream& operator>>(istream& os, Diploma& a);
};
ostream& operator<<(ostream& os, Diploma& a) {
	os << a.name;
	os << a.course << endl;
	os << a.ID << endl;
	os << a.topic << endl;
	return os;
}
istream& operator>>(istream& is, Diploma& a) {
	is >> a.name;
	is >> a.course;
	is >> a.ID;
	is >> a.topic;
	return is;
}
void task1()
{
	PIB name;
	name.lname = "Serhiivna";
	name.name = "Olena";
	name.fname = "Bondarenko";
	Diploma test1, test2(1, 12345678, "Olena", "Sport"), test3(2, 87654321, name, "Food");
	cout << test1;
	cout << test2;
	cout << test3;
}

/*
Задача 2. Створити клас кімната, що має площа. Визначити конструктор і метод доступу. 
Створити клас однокімнатних квартира, що містить кімнату й кухню (її площа), поверх (кімната втримується в класі однокімнатна квартира). 
Визначити конструктори, методи доступу. Визначити public-похідний клас однокімнатних квартир різних міст ( додатковий параметр - назва міста). 
Визначити конструктори, деструктор і функцію друку.
*/
//однокімнатних квартира
class Flatlet
{
protected:
	//клас кімната
	class Room
	{
	public:
		int square;
		Room() : square(0) {}
		Room(int sq) : square(sq) {}
		~Room()
		{
			cout << " Room Dtor " << endl;
		}
	};
	Room RoomObj;
	//кухню (її площа)
	int kitchensq;
	//поверх
	int floor;

public:
	Flatlet() : RoomObj(), kitchensq(0), floor(0) {}
	Flatlet(int sqr) : RoomObj(sqr), kitchensq(0), floor(0) {}
	Flatlet(int sqr, int sqk) : RoomObj(sqr), kitchensq(sqk), floor(0) {}
	Flatlet(int sqr, int sqk, int fl) : RoomObj(sqr), kitchensq(sqk), floor(fl) {}
	~Flatlet()
	{
		cout << " Flatlet Dtor " << endl;
	}
};
//Визначити public-похідний клас однокімнатних квартир різних міст
class City : public Flatlet
{
	//додатковий параметр - назва міста
	string name;

public:
	City() : Flatlet()
	{
		name = "NoName";
	}
	City(int sqr) : Flatlet(sqr)
	{
		name = "NoName";
	}
	City(int sqr, int sqk) : Flatlet(sqr, sqk)
	{
		name = "NoName";
	}
	City(int sqr, int sqk, int fl) : Flatlet(sqr, sqk, fl)
	{
		name = "NoName";
	}
	City(string nme, int sqr, int sqk, int fl) : Flatlet(sqr, sqk, fl)
	{
		name = nme;
	}
	~City()
	{
		cout << " City Dtor" << endl;
	}
	//функцію друку
	friend ostream& operator<<(ostream& os, City& a);
	friend istream& operator>>(istream& os, City& a);
	void Output();
};
ostream& operator<<(ostream& os, City& a) {
	os << "Room square: " << a.RoomObj.square << endl;
	os << "Kitchen square: " << a.kitchensq << endl;
	os << "Floor: " << a.floor << endl;
	os << "City name: " << a.name << endl;
	return os;
}
istream& operator>>(istream& is, City& a) {
	is >> a.RoomObj.square;
	is >> a.kitchensq;
	is >> a.floor;
	is >> a.name;
	return is;
}
void City::Output()
{
	cout << "Room square: " << RoomObj.square << endl;
	cout << "Kitchen square: " << kitchensq << endl;
	cout << "Floor: " << floor << endl;
	cout << "City name: " << name << endl;
}
void task2()
{
	cout << " Enter room square: ";
	int rs;
	cin >> rs;
	cout << " Enter kitchen square: ";
	int ks;
	cin >> ks;
	cout << " Enter floor: ";
	int f;
	cin >> f;
	cout << " Enter city name: ";
	string c;
	cin >> c;

	City CityObj1(rs), CityObj2(rs, ks), CityObj3(rs, ks, f), CityObj4(c, rs, ks, f);
	cout << "CityObj2(rs): ";
	CityObj1.Output();
	cout << "CityObj3(rs, ks): ";
	CityObj2.Output();
	cout << "CityObj4(rs, ks, f): ";
	CityObj3.Output();
	cout << "CityObj5(c, rs, ks, f): ";
	CityObj4.Output();
}

/*
Задача 3. Створити ієрархію класів спортивна гра й футбол. 
Перевизначити вивід у потік і введення з потоку, конструктори копіювання та перенесення, оператори присвоювання та перенесення через відповідні функції базового класу.
*/
class SportGame
{
protected:
	int players_number;
	int victories_number;

public:
};
class Football : public SportGame
{
	string team_name;

public:

};
void task3()
{

}

int main()
{
TASK:	int task_number = task_manager();
	switch (task_number)
	{
	case 1:
		task1();
		break;
	case 2:
		task2();
		break;
	case 3:
		task3();
		break;
	default:
		break;
	}

	string answer;
FIN:	printf("\nDo you want to do one more task? Enter 'yes' if you do, and 'no' if you don`t: ");
	cin >> answer;
	if (answer == "yes")
	{
		system("cls");
		goto TASK;
	}
	if (answer == "no")
	{
		system("cls");
		printf("Bye!");
	}
	else
	{
		printf("Please enter 'yes' or 'no'\n");
		goto FIN;
	}
}