// lab6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <string>
#include <time.h>
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
Задача 1. Створити дві ієрархії класів з віртуальним та без віртуального успадкуванням з елементами даних класів у кожному класі. 
Схема успадкування на рисунку за варіантами.
Створити об’єкти похідних класів з віртуальним та без віртуального успадкуванням. Вивести розміри об’єктів даних класів.
*/
class Base
{
protected:
	int dat;
public:
	Base() : dat(0) {}
	Base(int a) : dat(a) {}
};
class d1 : protected Base
{
protected:
	int dat;
public:
	d1() : dat(0) {}
	d1(int b) : dat(b) {}
	d1(int b, int a) : dat(b), Base(a) {}
};
class D1 : protected d1
{
protected:
	int dat;
public:
	D1() : dat(0) {}
	D1(int c) : dat(c) {}
	D1(int c, int b) : dat(c), d1(b) {}
	D1(int c, int b, int a) : dat(c), d1(b, a) {}
};
class d2 : protected Base
{
protected:
	int dat;
public:
	d2() : dat(0) {}
	d2(int d) : dat(d) {}
	d2(int d, int a) : dat(d), Base(a) {}
};
class D2 : protected d2
{
protected:
	int dat;
public:
	D2() : dat(0) {}
	D2(int e) : dat(e) {}
	D2(int e, int d) : dat(e), d2(d) {}
	D2(int e, int d, int a) : dat(e), d2(d, a) {}
};
class R : protected  Base, protected D1, protected D2
{
protected:
	int dat;
public:
	R() : dat(0) {}
	R(int f) : dat(f) {}
	R(int f, int a, int b, int c, int d, int e) : dat(f), Base(a), D1(c, b, a), D2(e, d, a) {}

	void showDat()
	{
		cout << " Base: " << Base::dat;
		cout << " Base: " << D1::d1::Base::dat;
		cout << " Base: " << D2::d2::Base::dat << endl;
		/*
		cout << " d1: " << D1::d1::dat;
		cout << " D1: " << D1::dat;
		cout << " d2: " << D2::d2::dat;
		cout << " D2: " << D2::dat;
		cout << " R: " << dat << endl;
		*/
	}
};
class dv1 : virtual protected Base
{
protected:
	int dat;
public:
	dv1() : dat(0) {}
	dv1(int b) : dat(b) {}
	dv1(int b, int a) : dat(b), Base(a) {}
};
class Dv1 : virtual protected dv1
{
protected:
	int dat;
public:
	Dv1() : dat(0) {}
	Dv1(int c) : dat(c) {}
	Dv1(int c, int b) : dat(c), dv1(b) {}
	Dv1(int c, int b, int a) : dat(c), dv1(b, a) {}
};
class dv2 : virtual protected Base
{
protected:
	int dat;
public:
	dv2() : dat(0) {}
	dv2(int d) : dat(d) {}
	dv2(int d, int a) : dat(d), Base(a) {}
};
class Dv2 : virtual protected dv2
{
protected:
	int dat;
public:
	Dv2() : dat(0) {}
	Dv2(int e) : dat(e) {}
	Dv2(int e, int d) : dat(e), dv2(d) {}
	Dv2(int e, int d, int a) : dat(e), dv2(d, a) {}
};
class Rv : virtual public Base, virtual protected Dv1, virtual protected Dv2
{
protected:
	int dat;
public:
	Rv() : dat(0) {}
	Rv(int f) : dat(f) {}
	Rv(int f, int a, int b, int c, int d, int e) : dat(f), Base(a), Dv1(c, b), Dv2(e, d) {}

	void showvDat()
	{
		cout << " Base: " << Base::dat;
		cout << " Base: " << Dv1::Base::dat;
		cout << " Base: " << Dv2::Base::dat << endl;
		/*
		cout << " dv1: " << Dv1::dv1::dat;
		cout << " Dv1: " << Dv1::dat;
		cout << " dv2: " << Dv2::dv2::dat;
		cout << " Dv2: " << Dv2::dat;
		cout << " Rv: " << dat << endl;
		*/
	}
};
void task1()
{
	int a, b, c, d, e, f;
	cout << " a: ";
	cin >> a;
	cout << " b: ";
	cin >> b;
	cout << " c: ";
	cin >> c;
	cout << " d: ";
	cin >> d;
	cout << " e: ";
	cin >> e;
	cout << " f: ";
	cin >> f;

	R A, B(f, a, b, c, d, e);
	cout << " Size of Base: " << sizeof(Base) << endl;
	cout << " Size of d1: " << sizeof(d1) << endl;
	cout << " Size of D1: " << sizeof(D1) << endl;
	cout << " Size of d2: " << sizeof(d2) << endl;
	cout << " Size of D2: " << sizeof(D2) << endl;
	cout << " Size of R: " << sizeof(R) << " or " << sizeof(A) << " or " << sizeof(B) << endl;

	A.showDat();
	B.showDat();

	Rv C, D(f, a, b, c, d, e);
	cout << " Size of Base: " << sizeof(Base) << endl;
	cout << " Size of dv1: " << sizeof(dv1) << endl;
	cout << " Size of Dv1: " << sizeof(Dv1) << endl;
	cout << " Size of dv2: " << sizeof(dv2) << endl;
	cout << " Size of Dv2: " << sizeof(Dv2) << endl;
	cout << " Size of Rv: " << sizeof(Rv) << " or " << sizeof(C) << " or " << sizeof(D) << endl;

	C.showvDat();
	D.showvDat();
}

/*
Створити абстрактний клас згідно варіанту.
Для перевірки визначити масив вказівників на абстрактний клас, яким присвоюється адреси об'єктів похідних класів
Задача 2. Створити абстрактний базовий клас фігура із віртуальною функцією площа. 
Створити похідні класи: прямокутник, коло, прямокутний трикутник, трапеція зі своїми функціями площі.
*/
class Figure
{
public:
	virtual double square() = 0;
};
class Rectangl : Figure
{
public:
	double a;
	double b;
	Rectangl() : a(0), b(0) {}
	Rectangl(double n, double m) : a(n), b(m) {}
	virtual double square()override
	{
		return a * b;
	}
};
class Circle : Figure
{
public:
	double r;
	Circle() : r(0) {}
	Circle(double rad) : r(rad) {}
	virtual double square()override
	{
		return 3.14 * pow(r, 2);
	}
};
class Triangle : Figure
{
public: 
	double a;
	double b;
	Triangle() : a(0), b(0) {}
	Triangle(double n, double m) : a(n), b(m) {}
	virtual double square()override
	{
		return a * b / 2;
	}
};
class Trapez : Figure
{
public:
	double a;
	double b;
	double h;
	Trapez() : a(0), b(0), h(0) {}
	Trapez(double n, double m, double k) : a(n), b(m), h(k) {}
	virtual double square()override
	{
		return (a + b) * h / 2;
	}
};
void task2()
{
	cout << " Rectangle: ";
	Rectangl r = Rectangl(2, 3);
	cout << r.square() << endl;

	cout << " Circle: ";
	Circle c = Circle(2);
	cout << c.square() << endl;

	cout << " Triangle: ";
	Triangle t = Triangle(2, 3);
	cout << t.square() << endl;

	cout << " Trapeze: ";
	Trapez tr = Trapez(2, 3, 4);
	cout << tr.square() << endl;
}

/*
Створити ієрархію типів, що описують класи сутностей. Класи мають поля характерні сутності та успадковувати поля батьківських класів. 
Визначити конструктори та віртуальні деструктори, перевантажити операції введення та виведення. 
В похідному класі визначити виводить інформацію про об’єкт класу, що успадковане від батьківських класів. 
Продумати ієрархію типів таким чином щоб похідний клас успадковував двох батьків(множинне спадкування).
Задача 3. Ієрархія типів складається з сутностей: студент, батько сімейства та студент-батько сімейства
*/
class Student
{
protected:
	string specialty;
public:
	Student() : specialty("NoSpecialty") {}
	Student(string s) : specialty(s) {}
	~Student()
	{
		cout << " Student Dtor" << endl;
	}

	friend ostream& operator<<(ostream& os, Student& a);
	friend istream& operator>>(istream& os, Student& a);
};
ostream& operator<<(ostream& os, Student& a) {
	os << a.specialty;
	return os;
}
istream& operator>>(istream& is, Student& a) {
	is >> a.specialty;
	return is;
}
class Father
{
protected:
	int children_number;
public:
	Father() : children_number(0) {}
	Father(int n) : children_number(n) {}
	~Father()
	{
		cout << " Father Dtor" << endl;
	}

	friend ostream& operator<<(ostream& os, Father& a);
	friend istream& operator>>(istream& os, Father& a);
};
ostream& operator<<(ostream& os, Father& a) {
	os << a.children_number;
	return os;
}
istream& operator>>(istream& is, Father& a) {
	is >> a.children_number;
	return is;
}
class StudentFather : public Student, public Father
{
	string name;
public:
	StudentFather() : name("NoName") {}
	StudentFather(string s, int n, string nm) : Student(s), Father(n), name(nm) {}
	~StudentFather()
	{
		cout << " StudentFather Dtor" << endl;
	}

	friend ostream& operator<<(ostream& os, StudentFather& a);
	friend istream& operator>>(istream& os, StudentFather& a);
};
ostream& operator<<(ostream& os, StudentFather& a) {
	os << a.name << endl;
	os << a.specialty << endl;
	os << a.children_number << endl;
	return os;
}
istream& operator>>(istream& is, StudentFather& a) {
	is >> a.name;
	is >> a.specialty;
	is >> a.children_number;
	return is;
}
void task3()
{
	string name, specialty;
	int children_number;
	cout << " Enter name: ";
	cin >> name;
	cout << " Enter specialty: ";
	cin >> specialty;
	cout << " Enter children number: ";
	cin >> children_number;
	StudentFather sf = StudentFather(specialty, children_number, name);
	cout << "Student: " << endl;
	cout << sf;
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
