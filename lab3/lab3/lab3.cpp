//

#include <iostream>
#include <string.h>
#include <random>
#include <fstream>
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
Завдання 1. Створити клас типу - дата з полями: день (1-31), місяць (1-12), рік (ціле число). У класі визначити
•	конструктори (не менше двох);
•	функції-члени встановлення дня, місяця та року, функції встановлення полів класу повинні перевіряти коректність параметрів, що задаються;
•	функції-члени одержання дня, місяця та року;
•	дві функції-члени друку за шаблоном: “5 січня 2019 року” і “05.01.2019”.
Написати програму тестування всіх можливостей цього класу.
*/
class Data
{
	//дата з полями: день (1-31), місяць (1-12), рік (ціле число)
	int day;
	int month;
	int year;
 	const char* month_names[12] = { "January", "Fabruary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

public:
	//конструктори (не менше двох);
	Data(): day(1), month(1), year(0){}
	Data(int yeari): day(1), month(1), year(yeari){}
	Data(int day, int month, int year) {
		if (day >= 1 && day <= 31)
		{
			this->day = day;
		}
		else
		{
			day = 1;
		}
		if (month >= 1 && month <= 12)
		{
			this->month = month;
		}
		else
		{
			month = 1;
		}
		this->year = year;
	}

	//функції-члени одержання дня, місяця та року;
	int get_day() const
	{
		return day;
	}
	int get_month() const
	{
		return month;
	}
	int get_year() const
	{
		return year;
	}

	//функції-члени встановлення дня, місяця та року, функції встановлення полів класу повинні перевіряти коректність параметрів, що задаються;
	void set_day(int day)
	{
		if (day < 1 || day > 31)
		{
			cout << "eror DAY set\n";
			return;
		}
		this->day = day;
	}
	void set_month(int month)
	{
		if (month < 1 || month > 12)
		{
			cout << "eror MONTH set\n";
			return;
		}
		this->month = month;
	}
	void set_year(int year)
	{
		if (year % 1 != 0)
		{
			cout << "eror YEAR set\n";
			return;
		}
		this->year = year;
	}
	void set_all_rand()
	{
		srand(time(0));
		this->day = rand() % 30 + 1;
		this->month = rand() % 11 + 1;
		this->year = rand() % 20000 - 10000;
	}
	void set_all_file()
	{
		ifstream MyFile("data.txt");
		MyFile >> this->day;
		MyFile >> this->month;
		MyFile >> this->year;
		MyFile.close();
	}

	//дві функції-члени друку за шаблоном: “5 січня 2019 року” і “05.01.2019”
	void print_format1()
	{
		//“5 січня 2019 року”
		cout << day << " " << month_names[month - 1] << " " << year << " year" << endl;
	}
	void print_format2()
	{
		//“05.01.2019”
		printf("%02d.%02d.%04d\n", day, month, year);
	}
};
void task1()
{
	//Написати програму тестування всіх можливостей цього класу.
	Data obj;
	obj.print_format1();
	obj.print_format2();

	int in_day, in_month, in_year;
	cout << "\nInput year number: "; cin >> in_year;
	Data obj1(in_year);
	obj1.print_format1();
	obj1.print_format2();

	cout << "\nInput day number: "; cin >> in_day;
	cout << "Input month number: "; cin >> in_month;
	cout << "Input year number: "; cin >> in_year;
	Data obj2(in_day, in_month, in_year);
	obj2.print_format1();
	obj2.print_format2();

	cout << endl;
	obj.set_day(2);
	obj.set_month(2);
	obj.set_year(1986);
	obj.print_format1();
	obj.print_format2();

	cout << endl;
	obj.set_day(32);
	obj.set_month(12);
	obj.set_year(2005);
	obj.print_format1();
	obj.print_format2();

	cout << endl;
	obj.set_day(28);
	obj.set_month(12);
	obj.set_year(-3765);
	obj.print_format1();
	obj.print_format2();

	cout << endl << "rand: " << endl;
	obj.set_all_rand();
	obj.print_format1();
	obj.print_format2();

	cout << endl << "file: " << endl;
	obj.set_all_file();
	obj.print_format1();
	obj.print_format2();
	cout << "End testing \n";
}

/*
Задача 2. Створити тип даних - клас вектор, який має вказівник на int, число елементів і змінну стану. У класі визначити:
•	конструктор без параметрів( виділяє місце для одного елемента та інінціалізує його в нуль);
•	конструктор з одним параметром - розмір вектора( виділяє місце та інінціалізує масив значенням нуль);
•	конструктор із двома параметрами - розмір вектора та значення ініціалізації(виділяє місце (значення перший аргумент) та інінціалізує значенням другого аргументу).
•	конструктор копій та операцію присвоєння; // !!!
•	деструктор звільняє пам'ять.
•	визначити функцію, яка присвоює елементу масиву деяке значення (параметр за замовчуванням);
•	функцію яка одержує деякий елемент масиву;
•	визначити функції друку, додавання, віднімання, які здійснюють ці арифметичні операції з даними цього класу, множення на ціле типу short;
•	визначити функції порівняння: більше, менше або рівно, які повертають true або false.
У змінну стани встановлювати код помилки, коли не вистачає пам'яті, виходить за межі масиву.
Передбачити можливість підрахунку числа об'єктів даного типу. Написати програму тестування всіх можливостей цього класу.
*/
typedef int Int;
class Vector
{
	//вказівник на int, число елементів і змінну стану:
	Int* v;
	int number;
	int state;

public:
	//конструктор без параметрів
	Vector() : v(NULL), number(0), state(0) {}
	//конструктор з одним параметром
	Vector(int n);
	//конструктор із двома параметрами
	Vector(int n, Int&);
	Vector(int n, Int*);
	Vector(const Vector& s);
	Vector& operator=(const Vector& s);
	//деструктор
	~Vector()
	{
		//cout << "del vector" << endl;
		if (v) delete[] v;
	}

	//визначити функцію, яка присвоює елементу масиву деяке значення (параметр за замовчуванням);
	void Element();
	//функцію яка одержує деякий елемент масиву;
	void Index(int i);
	//визначити функцію друку
	void Output();
	void Input();
	//rand
	void Input_rand();
	//file
	void Input_file();
	//визначити функцію додавання
	Vector Add(Vector& b);
	//визначити функцію віднімання
	Vector Subtract(Vector& b);
	//визначити функцію множення на ціле типу short
	Vector Multiply(short b);
	//визначити функції порівняння: більше, менше або рівно, які повертають true або false
	Vector More(Vector& b);
	Vector Less(Vector& b);
	Vector Equal(Vector& b);
};
Vector::Vector(int n)
{
	//конструктор з одним параметром - розмір вектора( виділяє місце та інінціалізує масив значенням нуль);
	if (n <= 0) 
	{ 
		v = NULL; 
		number = 0; 
		state = -1; 
		cout << " Vec --> 0 "; 
	}
	number = n;
	v = new Int[n];
	for (int i = 0; i < n; i++) 
	{
		v[i] = 0;
	}
}
Vector::Vector(int n, Int& b)
{
	if (n <= 0) 
	{ 
		v = NULL; 
		number = 0; 
		state = -1; 
		cout << " Vec --> 0 "; 
	}
	number = n;
	v = new Int[n];
	for (int i = 0; i < n; i++) 
	{
		v[i] = b;
	}
}
Vector::Vector(int n, Int* p) 
{
	if (n <= 0 || p == NULL) 
	{ 
		v = NULL; 
		number = 0; 
		state = -1; 
		cout << " Vec --> 0 "; 
	}
	number = n;
	v = new Int[n];
	for (int i = 0; i < n; i++) 
	{
		v[i] = p[i];
	}
}
Vector::Vector(const Vector& s) 
{
	number = s.number;
	v = new Int[number];
	state = 0;
	for (int i = 0; i < number; i++)
	{
		v[i] = s.v[i];
	}
}
Vector& Vector::operator=(const Vector& s) 
{
	if (number != s.number)
	{
		if (v) delete[] v;
		number = s.number;
		v = new Int[number];
		state = 0;
	}
	for (int i = 0; i < number; i++)
	{
		v[i] = s.v[i];
	}
	return *this;
}
void Vector::Element()
{
	for (int i = 0; i < number; i++)
	{
		v[i] = 6;
	}
}
void Vector::Index(int i)
{
	if (i < number)
	{
		cout << " v[" << i << "] " << v[i] << endl;
	}
	else
	{
		cout << "error INDEX set\n";
	}
}
void Vector::Input() 
{
	if (number == 0) 
	{
		if (v) delete[] v;
		do 
		{
			cout << "Input v size: ";
			cin >> number;
		} while (number <= 0);
		v = new Int[number];
	}
	for (int i = 0; i < number; i++) 
	{
		cout << " v[" << i << "] "; 
		cin >> v[i];
	}
}
void Vector::Input_rand()
{
	srand(time(0));
	if (number == 0)
	{
		if (v) delete[] v;
		do
		{
			cout << "Input v size: ";
			cin >> number;
		} while (number <= 0);
		v = new Int[number];
	}
	for (int i = 0; i < number; i++)
	{
		v[i] = rand() % 10;
	}
}
void Vector::Input_file()
{
	ifstream MyFile("vector.txt");
	if (!MyFile.is_open()) return;
	if (MyFile.fail()) return;
	MyFile >> number;
	for (int i = 0; i < number; i++)
	{
		MyFile >> v[i];
	}
	MyFile.close();
}
void Vector::Output() 
{
	if (number != 0) 
	{
		for (int i = 0; i < number; i++) 
		{
			cout << " v[" << i << "] " << v[i] << '\t';
			cout << endl;
		}
	}
}
Vector Vector::Add(Vector& b) {
	int tnum;
	tnum = number < b.number ? number : b.number;
	if (tnum >= 0) {
		Vector tmp(tnum);
		for (int i = 0; i < tnum; i++) tmp.v[i] = v[i] + b.v[i];
		return tmp;
	}
	return Vector(0);
}
Vector Vector::Subtract(Vector& b) {
	int tnum;
	tnum = number < b.number ? number : b.number;
	if (tnum >= 0) {
		Vector tmp(tnum);
		for (int i = 0; i < tnum; i++) tmp.v[i] = v[i] - b.v[i];
		return tmp;
	}
	return Vector(0);
}
Vector Vector::Multiply(short b) 
{
	Vector tmp(number);
	for (int i = 0; i < number; i++)
	{
		tmp.v[i] = v[i] * b;
	}
	return tmp;
}
Vector Vector::More(Vector& b) {
	int tnum;
	tnum = number < b.number ? number : b.number;
	if (tnum >= 0) {
		Vector tmp(tnum);
		for (int i = 0; i < tnum; i++)
		{
			if (v[i] > b.v[i])
			{
				tmp.v[i] = true;
				cout << v[i] << " > " << b.v[i] << " : true" << endl;
			}
			else
			{
				tmp.v[i] = false;
				cout << v[i] << " > " << b.v[i] << " : false" << endl;
			}
		}
		return tmp;
	}
	return Vector(0);
}
Vector Vector::Less(Vector& b) {
	int tnum;
	tnum = number < b.number ? number : b.number;
	if (tnum >= 0) {
		Vector tmp(tnum);
		for (int i = 0; i < tnum; i++)
		{
			if (v[i] < b.v[i])
			{
				tmp.v[i] = true;
				cout << v[i] << " < " << b.v[i] << " : true" << endl;
			}
			else
			{
				tmp.v[i] = false;
				cout << v[i] << " < " << b.v[i] << " : false" << endl;
			}
		}
		return tmp;
	}
	return Vector(0);
}
Vector Vector::Equal(Vector& b) {
	int tnum;
	tnum = number < b.number ? number : b.number;
	if (tnum >= 0) {
		Vector tmp(tnum);
		for (int i = 0; i < tnum; i++)
		{
			if (v[i] == b.v[i])
			{
				tmp.v[i] = true;
				cout << v[i] << " = " << b.v[i] << " : true" << endl;
			}
			else
			{
				tmp.v[i] = false;
				cout << v[i] << " = " << b.v[i] << " : false" << endl;
			}
		}
		return tmp;
	}
	return Vector(0);
}
void task2()
{
	Int a(1), b, c;
	cout << " a : " << a << endl;
	b = 2;
	cout << " b : " << b << endl;
	c = a + b;
	cout << " c : " << c << endl << endl;

	cout << "    Test " << endl;
	Vector VecObj, VecObj1(10);
	cout << "VecObj" << endl;
	VecObj.Output();
	cout << "VecObj1:" << endl;
	VecObj1.Output();
	cout << "Input a ";
	cin >> a;
	cout << " a : " << a << endl;
	Vector VecObj2(10, a);
	cout << "VecObj2:" << endl;
	VecObj2.Output();

	cout << endl;
	VecObj.Input();
	cout << "VecObj:" << endl;
	VecObj.Output();
	//визначити функцію, яка присвоює елементу масиву деяке значення (параметр за замовчуванням);
	cout << "VecObj2:" << endl;
	VecObj2.Element();
	VecObj2.Output();
	//функцію яка одержує деякий елемент масиву;
	cout << "Index : ";
	int i;
	cin >> i;
	VecObj.Index(i);
	//визначити функцію додавання
	cout << "Add:\n";
	VecObj1 = VecObj.Add(VecObj2);
	VecObj1.Output();
	//визначити функцію віднімання
	cout << "Subtract:\n";
	VecObj1 = VecObj.Subtract(VecObj2);
	VecObj1.Output();
	//визначити функцію множення на ціле типу short
	cout << "Multiply:\n";
	short d;
	cout << " Input d : ";
	cin >> d;
	cout << " d : " << d << endl;
	VecObj1 = VecObj.Multiply(d);
	VecObj1.Output();
	//визначити функції порівняння: більше, менше або рівно, які повертають true або false
	cout << "More:\n";
	VecObj1 = VecObj.More(VecObj2);
	cout << "Less:\n";
	VecObj1 = VecObj.Less(VecObj2);
	cout << "Equal:\n";
	VecObj1 = VecObj.Equal(VecObj2);

	//rand
	cout << endl;
	VecObj.Input_rand();
	cout << "VecObj rand:" << endl;
	VecObj.Output();
	//rand
	cout << endl;
	VecObj.Input_file();
	cout << "VecObj file:" << endl;
	VecObj.Output();
}

/*
Задача 3.Створити клас матриця. Даний клас містить вказівник на int, розміри рядків і стовпців та стан помилки. У класі визначити:
•	конструктор без параметрів( виділяє місце для матриці 3 на 3 елемента та інінціалізує його в нуль);
•	конструктор з одним параметром – розмір n матриці (виділяє місце n на n та інінціалізує матрицю значенням нуль);
•	конструктор із трьома розміри матриці (n , m) та значення ініціалізації value (виділяє місце перші аргументи та інінціалізує значенням третього аргументу - value);
•	конструктор копій та операцію присвоєння; // !!!
•	деструктор звільняє пам'ять.
•	визначити функцію, яка присвоює елементу масиву деяке значення (параметр за замовчуванням);
•	функцію яка одержує деякий елемент матриці за індексами i та j;
•	визначити функції друку, додавання, множення, віднімання, які здійснюють ці арифметичні операції з даними цього класу;
•	визначити функції порівняння: більше, менше або рівно, які повертають true або false.

У змінну стани встановлювати код помилки, коли не вистачає пам'яті, виходить за межі
матриці. Передбачити можливість підрахунку числа об'єктів даного типу. Написати програму
тестування всіх можливостей цього класу.
*/
class Matrix
{
	//вказівник на int, розміри рядків і стовпців та стан помилки
	int* ma;
	int rows, colls;
	int state;
	int num = rows * colls; //rows * colls

public:
	//конструктор без параметрів( виділяє місце для матриці 3 на 3 елемента та інінціалізує його в нуль);
	Matrix() : ma(NULL), rows(3), colls(3), state(0), num(9) {}
	//конструктор з одним параметром – розмір n матриці (виділяє місце n на n та інінціалізує матрицю значенням нуль);
	Matrix(int n);
	//конструктор із трьома розміри матриці (n , m) та значення ініціалізації value (виділяє місце перші аргументи та інінціалізує значенням третього аргументу - value);
	Matrix(int n, int m, int& value);
	Matrix(int n, int m, int* value);
	//конструктор копій та операцію присвоєння;
	Matrix(const Matrix& s);
	Matrix& operator=(const Matrix& s);
	//деструктор звільняє пам'ять.
	~Matrix()
	{
		//cout << "del matrix" << endl;
		if (ma) delete[] ma;
	}

	//визначити функцію, яка присвоює елементу масиву деяке значення (параметр за замовчуванням);
	void Element();
	//функцію яка одержує деякий елемент матриці за індексами i та j;
	void Index(int i, int j);
	//визначити функції друку, додавання, множення, віднімання, які здійснюють ці арифметичні операції з даними цього класу;
	void Output();
	void Input();

	//визначити функцію додавання
	Matrix Add(Matrix& b);
	//визначити функцію віднімання
	Matrix Subtract(Matrix& b);
	//визначити функцію множення на ціле типу short
	Matrix Multiply(Matrix& b);
	//визначити функції порівняння: більше, менше або рівно, які повертають true або false
	Matrix More(Matrix& b);
	Matrix Less(Matrix& b);
	Matrix Equal(Matrix& b);
};
Matrix::Matrix(int n)
{
	if (n <= 0)
	{
		ma = NULL;
		num = 0;
		rows = 0;
		colls = 0;
		state = -1;
		cout << " Mat --> 0 \n";
	}
	num = n * n;
	rows = n;
	colls = n;
	ma = new int[n * n];
	for (int i = 0; i < num; i++)
	{
		ma[i] = 0;
	}
}
Matrix::Matrix(int n, int m, int& value)
{
	if (n <= 0 || m <= 0)
	{
		ma = NULL;
		num = 0;
		rows = 0;
		colls = 0;
		state = -1;
		cout << " Mat --> 0 ";
	}
	num = n * m;
	rows = n;
	colls = m;
	ma = new int[num];
	for (int i = 0; i < num; i++)
	{
		ma[i] = value;
	}
}
Matrix::Matrix(int n, int m, int* value)
{
	if (n <= 0 || ma == NULL || m <= 0)
	{
		m = NULL;
		num = 0;
		rows = 0;
		colls = 0;
		state = -1;
		cout << " Mat --> 0 ";
	}
	num = n * m;
	rows = n;
	colls = m;
	ma = new int[num];
	for (int i = 0; i < num; i++)
	{
		ma[i] = value[i];
	}
}
Matrix::Matrix(const Matrix& s)
{
	num = s.num;
	rows = s.rows;
	colls = s.colls;
	ma = new int[num];
	state = 0;
	for (int i = 0; i < num; i++)
	{
		ma[i] = s.ma[i];
	}
}
Matrix& Matrix::operator=(const Matrix& s)
{
	if (rows != s.rows || colls != s.colls || num != s.num)
	{
		if (ma) delete[] ma;
		num = s.num;
		rows = s.rows;
		colls = s.colls;
		ma = new int[num];
		state = 0;
	}
	for (int i = 0; i < num; i++)
	{
		ma[i] = s.ma[i];
	}
	return *this;
}
void Matrix::Element()
{
	for (int i = 0; i < num; i++)
	{
		ma[i] = 3;
	}
}
void Matrix::Index(int i, int j)
{
	if (i < rows || j < colls)
	{
		cout << " ma[" << i << "] [" << j << "] :" << ma[i * colls + j] << endl;
	}
	else
	{
		cout << "error INDEX set\n";
	}
}
void Matrix::Input()
{
	if (ma == NULL || rows <= 0 || colls <= 0)
	{
		if (ma) delete[] ma;
		do
		{
			cout << "Input rows: ";
			cin >> rows;
		} while (rows <= 0);
		do
		{
			cout << "Input colls: ";
			cin >> colls;
		} while (colls <= 0);
		num = rows * colls;
		ma = new int[num];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colls; j++)
		{
			cout << " ma[" << i << "] [" << j << "] : ";
			cin >> ma[i * colls + j];
		}
	}
}
void Matrix::Output()
{
	if (rows >= 0 && colls >= 0 && ma != NULL)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < colls; j++)
			{
				cout << " ma[" << i << "] [" << j << "] " << ma[i * colls + j] << '\t';
				cout << endl;
			}
		}
	}
}
Matrix Matrix::Add(Matrix& b) 
{
	if (rows != b.rows || colls != b.colls)
	{
		Matrix tmp;
		tmp.state = -1;
		cout << " Matrix must have the same size!";
		return tmp;
	}
	Matrix tmp(rows, colls, 0);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colls; j++)
		{
			tmp.ma[i * colls + j] = ma[i * colls + j] + b.ma[i * colls + j];
		}
	}
	return tmp;
}
Matrix Matrix::Subtract(Matrix& b) {
	int tnum, ti, tj;
	if (rows != b.rows)
	{
		return Matrix(0);
	}
	if (colls == b.colls)
	{
		return Matrix(0);
	}
	ti = rows;
	tj = colls;
	tnum = ti * tj;
	if (tnum >= 0 && ti >= 0 && tj >= 0) {
		Matrix tmp(ti, tj, 0);
		for (int i = 0; i < tnum; i++)
		{
			tmp.ma[i] = ma[i] - b.ma[i];
		}
		return tmp;
	}
	return Matrix(0);
}
Matrix Matrix::Multiply(Matrix& b)
{
	int tnum, ti, tj;
	if (rows != b.rows)
	{
		return Matrix(0);
	}
	if (colls == b.colls)
	{
		return Matrix(0);
	}
	ti = rows;
	tj = colls;
	tnum = ti * tj;
	if (tnum >= 0 && ti >= 0 && tj >= 0) {
		Matrix tmp(ti, tj, 0);
		for (int i = 0; i < tnum; i++)
		{
			tmp.ma[i] = ma[i] * b.ma[i];
		}
		return tmp;
	}
	return Matrix(0);
}
Matrix Matrix::More(Matrix& b) {
	int tnum, ti, tj; 
	if (rows != b.rows)
	{
		return Matrix(0);
	}
	if (colls == b.colls)
	{
		return Matrix(0);
	}
	ti = rows;
	tj = colls;
	tnum = ti * tj;
	if (tnum >= 0 && ti >= 0 && tj >= 0)
	{
		Matrix tmp(ti, tj, 0);
		for (int i = 0; i < tnum; i++)
		{
			if (ma[i] > b.ma[i])
			{
				tmp.ma[i] = true;
				cout << ma[i] << " > " << b.ma[i] << " : true" << endl;
			}
			else
			{
				tmp.ma[i] = false;
				cout << ma[i] << " > " << b.ma[i] << " : false" << endl;
			}
		}
		return tmp;
	}
	return Matrix(0);
}
Matrix Matrix::Less(Matrix& b) {
	int tnum, ti, tj;
	if (rows != b.rows)
	{
		return Matrix(0);
	}
	if (colls == b.colls)
	{
		return Matrix(0);
	}
	ti = rows;
	tj = colls;
	tnum = ti * tj;
	if (tnum >= 0 && ti >= 0 && tj >= 0)
	{
		Matrix tmp(ti, tj, 0);
		for (int i = 0; i < tnum; i++)
		{
			if (ma[i] < b.ma[i])
			{
				tmp.ma[i] = true;
				cout << ma[i] << " < " << b.ma[i] << " : true" << endl;
			}
			else
			{
				tmp.ma[i] = false;
				cout << ma[i] << " < " << b.ma[i] << " : false" << endl;
			}
		}
		return tmp;
	}
	return Matrix(0);
}
Matrix Matrix::Equal(Matrix& b) {
	int tnum, ti, tj;
	if (rows != b.rows)
	{
		return Matrix(0);
	}
	if (colls == b.colls)
	{
		return Matrix(0);
	}
	ti = rows;
	tj = colls;
	tnum = ti * tj;
	if (tnum >= 0 && ti >= 0 && tj >= 0)
	{
		Matrix tmp(ti, tj, 0);
		for (int i = 0; i < tnum; i++)
		{
			if (ma[i] = b.ma[i])
			{
				tmp.ma[i] = true;
				cout << ma[i] << " = " << b.ma[i] << " : true" << endl;
			}
			else
			{
				tmp.ma[i] = false;
				cout << ma[i] << " = " << b.ma[i] << " : false" << endl;
			}
		}
		return tmp;
	}
	return Matrix(0);
}
void task3()
{
	cout << "    Test " << endl;
	Matrix Obj, Obj1(3);
	cout << "Obj" << endl;
	Obj.Output();
	cout << "Obj1:" << endl;
	Obj1.Output();
	cout << "Input value ";
	int a;
	cin >> a;
	cout << " value : " << a << endl;
	Matrix Obj2(2, 3, a);
	cout << "Obj2:" << endl;
	Obj2.Output();

	cout << endl;
	Obj.Input();
	cout << "Obj:" << endl;
	Obj.Output();
	//функцію яка одержує деякий елемент масиву;
	cout << "Index i : ";
	int i;
	cin >> i;
	cout << "Index j : ";
	int j;
	cin >> j;
	Obj.Index(i, j);
	//визначити функцію, яка присвоює елементу масиву деяке значення (параметр за замовчуванням);
	cout << "Obj2:" << endl;
	Obj2.Element();
	Obj2.Output();
	//визначити функцію додавання
	cout << "Add:\n";
	Obj1 = Obj.Add(Obj2);
	Obj1.Output();
	//визначити функцію віднімання
	cout << "Subtract:\n";
	Obj1 = Obj.Subtract(Obj2);
	Obj1.Output();
	//визначити функцію множення на ціле типу short
	cout << "Multiply:\n";
	Obj1 = Obj.Multiply(Obj2);
	Obj1.Output();
	//визначити функції порівняння: більше, менше або рівно, які повертають true або false
	cout << "More:\n";
	Obj1 = Obj.More(Obj2);
	cout << "Less:\n";
	Obj1 = Obj.Less(Obj2);
	cout << "Equal:\n";
	Obj1 = Obj.Equal(Obj2);
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