// lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include <fstream>
#include <map>
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
Задача 1
Розробити та реалізувати клас «вектор» згідно варіантів, у класі переважити операції. Написати програму обчислення «векторних» виразів 
(тобто вираз складається операцій на векторами та скалярними величинами). В програмі має бути декілька виразів, вираз має складатися із 5 та більше операцій.
Перевантажені операції повинні бути присутні хоча б одному з виразів.

Створити тип даних - клас VectorInt (вектор цілих чисел), який має вказівник на int, число елементів size і змінну стану codeError. У класі визначити:

o конструктор без параметрів( виділяє місце для одного елемента та інінціалізує його в нуль);
o конструктор з одним параметром - розмір вектора( виділяє місце та інінціалізує масив значенням нуль);
o конструктор із двома параметрами - розмір вектора та значення ініціалізації(виділяє місце (значення перший аргумент) та інінціалізує значенням другого аргументу) ;
o конструктор копіювання;
o деструктор звільняє пам'ять;

o перевантаження операцій (операції перевантажувати через функції класу або дружні функції, якщо не вказано яким чином це робити): 
• унарних префіксних та постфіксних ++ та --: одночасно збільшує (зменшує) значення елементів масиву на 1;
• унарної логічної ! (заперечення): повертає значення true, якщо елементи якщо size не дорівнює – нулю, інакше false;
• унарної побітової ~ (заперечення): повертає побітове заперечення для всіх елементів масиву класу вектор;
• унарний арифметичний - (мінус) : повертає всі елементи масиву класу вектор з протилежним знаком;
• присвоєння =: копіює вектор(перевантажити через функцію класу);

• присвоєння з (перевантажити через функцію класу)
 o += - додаванням векторів;
 o -= - відніманням векторів;
 o *= - множення, вектора на число типу int;
 o /= - ділення, вектора на число типу int;
 o %= - остача від ділення, вектора на число типу int;
 o |= -побітове додаванням векторів;
 o ^= - побітове додавання за модулем 2 векторів;
 o &= - побітове по-елементне множення векторів;

• арифметичних бінарні:
o + - додавання векторів;
o – - віднімання векторів;
o * - множення, вектора на число типу int;
o / - ділення, вектора на число типу int;
o % - остача від ділення, вектора на число типу int;

• побітові бінарні
o | - побітове додавання векторів;
o ^ - побітове додавання за модулем 2 векторів;
o & - побітове по-елементне множення векторів;

• побітові операції зсувів, як дружні операції введення та виведення
вектора у потік (перевантажувати через дружні функції)
o введення >> (побітовий зсув право) ;
o введення << (побітовий зсув ліво);

• рівності == та нерівності!= , функція-операція виконує певні дії над кожною парою елементів векторів за індексом;
• операцію індексації [] – функцію, яка звертається до елементу масиву за індексом, якщо індекс невірний функція вказує на останній елемент масиву та встановлює код помилки у змінну codeError;
• розподілу пам’яті new та delete;
• виклику функції ();
• порівняння (функція-операція виконує певні дії над кожною парою елементів векторів за індексом), які повертають true або false:
o > (більше) для двох векторів;
o >= (більше рівне) для двох векторів;
o < (менше) для двох векторів;
o <=(менше рівне) для двох векторів.

У змінну стани встановлювати код помилки, коли не вистачає пам'яті, виходить за межі масиву.
Передбачити можливість підрахунку числа об'єктів даного типу. Перевірити роботу цього
класу.
*/
typedef int Int;
class VectorInt
{
	Int* vector;
	int size;
	int codeError;

public:
	//конструктор без параметрів( виділяє місце для одного елемента та інінціалізує його в нуль);
	VectorInt() : vector(NULL), size(0), codeError(0) {}
	//конструктор з одним параметром - розмір вектора( виділяє місце та інінціалізує масив значенням нуль);
	VectorInt(int n);
	//конструктор із двома параметрами - розмір вектора та значення ініціалізації(виділяє місце (значення перший аргумент) та інінціалізує значенням другого аргументу)
	VectorInt(int n, Int& value);
	VectorInt(int n, Int* value);
	//конструктор копіювання
	VectorInt(const VectorInt& s);
	//деструктор звільняє пам'ять
	~VectorInt()
	{
		//cout << "del vector" << endl;
		if (vector) delete[] vector;
	}

	//перевантаження операцій (операції перевантажувати через функції класу або дружні функції, якщо не вказано яким чином це робити)
	VectorInt(VectorInt& src);
	VectorInt(VectorInt&& src);
	//унарних префіксних та постфіксних ++ та --: одночасно збільшує (зменшує) значення елементів масиву на 1;
	friend VectorInt& operator++(VectorInt& s);
	friend VectorInt& operator--(VectorInt& s);
	//унарної логічної ! (заперечення): повертає значення true, якщо елементи якщо size не дорівнює – нулю, інакше false;
	bool operator!()
	{
		if (size != 0)
		{
			return true;
		}
		return false;
	}
	//унарної побітової ~(заперечення) : повертає побітове заперечення для всіх елементів масиву класу вектор;
	VectorInt operator~();
	//унарний арифметичний - (мінус) : повертає всі елементи масиву класу вектор з протилежним знаком;
	VectorInt operator-();
	//присвоєння =: копіює вектор(перевантажити через функцію класу);
	VectorInt& operator=(VectorInt& s);
	VectorInt& operator=(VectorInt&& s);

	//присвоєння з (перевантажити через функцію класу):
	// += -додаванням векторів;
	VectorInt& operator+=(const VectorInt& b);
	// -= -відніманням векторів;
	VectorInt& operator-=(const VectorInt& b);
	// *= -множення, вектора на число типу int;
	VectorInt& operator*=(int b);
	// /= -ділення, вектора на число типу int;
	VectorInt& operator/=(int b);
	// %= -остача від ділення, вектора на число типу int;
	VectorInt& operator%=(int b);
	// |= -побітове додаванням векторів;
	VectorInt& operator|=(const VectorInt& b);
	// ^= -побітове додавання за модулем 2 векторів;
	VectorInt& operator^=(const VectorInt& b);
	// &= -побітове по - елементне множення векторів;
	VectorInt& operator&=(const VectorInt& b);

	//арифметичних бінарні :
	// + -додавання векторів;
	VectorInt operator+(VectorInt& b);
	// – - віднімання векторів;
	VectorInt operator-(VectorInt& b);
	// * -множення, вектора на число типу int;
	VectorInt operator*(int a);
	// / -ділення, вектора на число типу int;
	VectorInt operator/(int a);
	// % -остача від ділення, вектора на число типу int;
	VectorInt operator%(int a);

	//побітові бінарні
	// | -побітове додавання векторів;
	VectorInt operator|(VectorInt& b);
	// ^ -побітове додавання за модулем 2 векторів;
	VectorInt operator^(VectorInt& b);
	// & -побітове по - елементне множення векторів;
	VectorInt operator&(VectorInt& b);

	//побітові операції зсувів, як дружні операції введення та виведення вектора у потік(перевантажувати через дружні функції)
	// введення >> (побітовий зсув право);
	friend istream& operator>>(istream& is, VectorInt& a);
	// введення << (побітовий зсув ліво);
	friend ostream& operator<<(ostream& os, VectorInt& a);

	//рівності == та нерівності!= , функція-операція виконує певні дії над кожною парою елементів векторів за індексом
	bool operator==(VectorInt b)
	{
		if (size == b.size)
		{
			for (int i = 0; i < size; i++)
			{
				if (vector[i] != b.vector[i])
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator!=(VectorInt b)
	{
		if (size == b.size)
		{
			for (int i = 0; i < size; i++)
			{
				if (vector[i] == b.vector[i])
				{
					return false;
				}
			}
			return true;
		}
		return true;
	}
	//операцію індексації [] – функцію, яка звертається до елементу масиву за індексом, якщо індекс невірний функція вказує на останній елемент масиву та встановлює код помилки у змінну codeError
	Int& operator[](const int index);
	//розподілу пам’яті new та delete;
	void* operator new(size_t tip);
	//виклику функції();
	VectorInt& operator()(const int index);

	//порівняння(функція - операція виконує певні дії над кожною парою елементів векторів за індексом), які повертають true або false:
	// > (більше)для двох векторів;
	bool operator>(VectorInt b)
	{
		if (size == b.size)
		{
			int v_tracker = 0;
			int b_tracker = 0;
			for (int i = 0; i < size; i++)
			{
				v_tracker += vector[i];
				b_tracker += b.vector[i];
			}
			if (v_tracker > b_tracker)
			{
				return true;
			}
			return false;
		}
		return false;
	}
	// >= (більше рівне) для двох векторів;
	bool operator>=(VectorInt b)
	{
		if (size == b.size)
		{
			int v_tracker = 0;
			int b_tracker = 0;
			for (int i = 0; i < size; i++)
			{
				v_tracker += vector[i];
				b_tracker += b.vector[i];
			}
			if (v_tracker >= b_tracker)
			{
				return true;
			}
			return false;
		}
		return false;
	}
	// < (менше)для двох векторів;
	bool operator<(VectorInt b)
	{
		if (size == b.size)
		{
			int v_tracker = 0;
			int b_tracker = 0;
			for (int i = 0; i < size; i++)
			{
				v_tracker += vector[i];
				b_tracker += b.vector[i];
			}
			if (v_tracker < b_tracker)
			{
				return true;
			}
			return false;
		}
		return false;
	}
	// <= (менше рівне) для двох векторів.
	bool operator<=(VectorInt b)
	{
		if (size == b.size)
		{
			int v_tracker = 0;
			int b_tracker = 0;
			for (int i = 0; i < size; i++)
			{
				v_tracker += vector[i];
				b_tracker += b.vector[i];
			}
			if (v_tracker <= b_tracker)
			{
				return true;
			}
			return false;
		}
		return false;
	}
};
VectorInt::VectorInt(int n)
{
	if (n <= 0)
	{
		vector = NULL;
		size = 0;
		codeError = -1;
		cout << " Vec --> 0 ";
	}
	size = n;
	vector = new Int[size];
	for (int i = 0; i < size; i++)
	{
		vector[i] = 0;
	}
}
VectorInt::VectorInt(int n, Int& value)
{
	if (n <= 0)
	{
		vector = NULL;
		size = 0;
		codeError = -1;
		cout << " Vec --> 0 ";
	}
	size = n;
	vector = new Int[size];
	for (int i = 0; i < size; i++)
	{
		vector[i] = value;
	}
}
VectorInt::VectorInt(int n, Int* value)
{
	if (n <= 0 || value == NULL)
	{
		vector = NULL;
		size = 0;
		codeError = -1;
		cout << " Vec --> 0 ";
	}
	size = n;
	vector = new Int[size];
	for (int i = 0; i < size; i++)
	{
		vector[i] = value[i];
	}
}
VectorInt::VectorInt(const VectorInt& s)
{
	size = s.size;
	vector = new Int[size];
	codeError = 0;
	for (int i = 0; i < size; i++)
	{
		vector[i] = s.vector[i];
	}
}

VectorInt::VectorInt(VectorInt& src)
{
	size = src.size;
	vector = new Int[size];
	codeError = 0;
	for (int i = 0; i < size; i++) vector[i] = src.vector[i];
}
VectorInt::VectorInt(VectorInt&& src)
{
	size = src.size;
	vector = new Int[size];
	codeError = 0;
	for (int i = 0; i < size; i++) vector[i] = src.vector[i];
}
VectorInt& operator++(VectorInt& s)
{
	for (int i = 0; i < s.size; i++)
	{
		s.vector[i] = s.vector[i] + 1;
	}
	return s;
}
VectorInt& operator--(VectorInt& s)
{
	for (int i = 0; i < s.size; i++)
	{
		s.vector[i] = s.vector[i] - 1;
	}
	return s;
}
/*VectorInt VectorInt::operator!()
{
	return size != 0;
}*/
VectorInt VectorInt::operator~()
{
	VectorInt tempObj;
	for (int i = 0; i < size; i++)
	{
		tempObj.vector[i] = ~vector[i];
	}
	return tempObj;
}
VectorInt VectorInt::operator-()
{
	VectorInt tempObj(size);
	for (int i = 0; i < size; i++)
	{
		tempObj.vector[i] = -vector[i];
	}
	return tempObj;
}
VectorInt& VectorInt::operator=(VectorInt& s)
{
	for (int i = 0; i < 3; i++) vector[i] = s.vector[i];
	return *this;
}
VectorInt& VectorInt::operator=(VectorInt&& s)
{
	for (int i = 0; i < 3; i++) vector[i] = s.vector[i];
	return *this;
}

VectorInt& VectorInt::operator+=(const VectorInt& b)
{
	for (int i = 0; i < size; i++)
	{
		vector[i] = vector[i] + b.vector[i];
	}
	return *this;
}
VectorInt& VectorInt::operator-=(const VectorInt& b)
{
	for (int i = 0; i < size; i++)
	{
		vector[i] = vector[i] - b.vector[i];
	}
	return *this;
}
VectorInt& VectorInt::operator*=(int b)
{
	for (int i = 0; i < size; i++)
	{
		vector[i] = vector[i] * b;
	}
	return *this;
}
VectorInt& VectorInt::operator/=(int b)
{
	for (int i = 0; i < size; i++)
	{
		vector[i] = vector[i] / b;
	}
	return *this;
}
VectorInt& VectorInt::operator%=(int b)
{
	for (int i = 0; i < size; i++)
	{
		vector[i] = vector[i] % b;
	}
	return *this;
}
VectorInt& VectorInt::operator|=(const VectorInt& b)
{
	for (int i = 0; i < size; i++)
	{
		vector[i] = vector[i] | b.vector[i];
	}
	return *this;
}
VectorInt& VectorInt::operator^=(const VectorInt& b)
{
	for (int i = 0; i < size; i++)
	{
		vector[i] = vector[i] ^ b.vector[i];
	}
	return *this;
}
VectorInt& VectorInt::operator&=(const VectorInt& b)
{
	for (int i = 0; i < size; i++)
	{
		vector[i] = vector[i] & b.vector[i];
	}
	return *this;
}

VectorInt VectorInt::operator+(VectorInt& b)
{
	if (size > b.size)
	{
		size = b.size;
	}
	VectorInt temp(size);
	for (int i = 0; i < size; i++)
	{
		temp.vector[i] = vector[i] + b.vector[i];
	}
	return temp;
}
VectorInt VectorInt::operator-(VectorInt& b)
{
	VectorInt temp;
	if (size > b.size)
	{
		size = b.size;
	}
	for (int i = 0; i < size; i++)
	{
		temp.vector[i] = vector[i] - b.vector[i];
	}
	return temp;
}
VectorInt VectorInt::operator*(int a)
{
	VectorInt temp;
	for (int i = 0; i < size; i++)
	{
		temp.vector[i] = vector[i] * a;
	}
	return temp;
}
VectorInt VectorInt::operator/(int a)
{
	VectorInt temp;
	for (int i = 0; i < size; i++)
	{
		temp.vector[i] = vector[i] / a;
	}
	return temp;
}
VectorInt VectorInt::operator%(int a)
{
	VectorInt temp;
	for (int i = 0; i < size; i++)
	{
		temp.vector[i] = vector[i] % a;
	}
	return temp;
}
VectorInt VectorInt::operator|(VectorInt& b)
{
	VectorInt temp;
	if (size > b.size)
	{
		size = b.size;
	}
	for (int i = 0; i < size; i++)
	{
		temp.vector[i] = vector[i] | b.vector[i];
	}
	return temp;
}
VectorInt VectorInt::operator^(VectorInt& b)
{
	VectorInt temp;
	if (size > b.size)
	{
		size = b.size;
	}
	for (int i = 0; i < size; i++)
	{
		temp.vector[i] = vector[i] ^ b.vector[i];
	}
	return temp;
}
VectorInt VectorInt::operator&(VectorInt& b)
{
	VectorInt temp;
	if (size > b.size)
	{
		size = b.size;
	}
	for (int i = 0; i < size; i++)
	{
		temp.vector[i] = vector[i] & b.vector[i];
	}
	return temp;
}

istream& operator>>(istream& is, VectorInt& a)
{
	int i;
	for (i = 0; i < a.size; i++)
	{
		is >> a.vector[i];
	}
	return is;
}
ostream& operator<<(ostream& os, VectorInt& a)
{
	int i;
	for (i = 0; i < a.size; i++)
	{
		os << " " << a.vector[i] << " ";
	}
	return os;
}

Int& VectorInt::operator[](const int index)
{
	if (index >= size || index < 0)
	{
		codeError = -1;
		cout << " error INDEX set ";
		return vector[size - 1];
	}
	return vector[index];
}
void* operator new(size_t tip)
{
	return (malloc(tip));
}
VectorInt& VectorInt::operator()(const int index)
{
	VectorInt tempObj;
	return tempObj;
}

void task1()
{
	VectorInt vec1, vec2(3);
	cout << " Vec1: " << vec1 << endl;
	cout << " Vec2: " << vec2 << endl;
	cout << " Enter size of vec3: ";
	int size3;
	cin >> size3;
	cout << " Enter value of vec3: ";
	int value;
	cin >> value;
	VectorInt vec3(size3, value);
	cout << " Vec3: " << vec3 << endl;

	vec2 += vec3;
	cout << " Vec2 += vec3: " << vec2 << endl;
	vec2 -= vec3;
	cout << " Vec2 -= vec3: " << vec2 << endl;
	vec3 *= 4;
	cout << " Vec3 *= 2: " << vec3 << endl;
	vec3 /= 3;
	cout << " Vec3 /= 3: " << vec3 << endl;
	vec3 %= 3;
	cout << " Vec3 %= 3: " << vec3 << endl;

	//осб тут)
	if (vec2 == vec3)
	{
		cout << " vec2 == vec3" << endl;
	}
	if (vec2 != vec3)
	{
		cout << " vec2 != vec3" << endl;
	}
	if (vec2 > vec3)
	{
		cout << " vec2 > vec3" << endl;
	}
	if (vec2 < vec3)
	{
		cout << " vec2 < vec3" << endl;
	}
}

/*
Завдання 2. 
Побудувати асоційований клас збереження двох сутностей. В завданні створити клас, який представляє собою асоціативний масив між двома сутностями. 
Написати функцію створення набору асоціативних сутностей. Перевантажити операцію індексації [] – функцію, яка звертається до об’єкта класу, 
за однією сутністю, якщо індекс, повертає асоціативну сутність, якщо відповідної сутності немає в встановлює код помилки у змінну CodeError, 
альтернативні звернення через перевантаження операції виклику функції(); перевантажити дружні операції введення та виведення.

Цілих чисел від 1 до 100 та цілі прописом. Наприклад, 1 та один, 10 та десять.
*/
class AssArray
{
	map<int, string> numbers{};
	int CodeError;

public:
	//Написати функцію створення набору асоціативних сутностей
	AssArray();
	//Перевантажити операцію індексації [] – функцію, яка звертається до об’єкта класу, за однією сутністю, якщо індекс, повертає асоціативну сутність, 
	//якщо відповідної сутності немає в встановлює код помилки у змінну CodeError
	string& operator[](int index);
	//альтернативні звернення через перевантаження операції виклику функції()
	int& operator()(string index);
	//перевантажити дружні операції введення та виведення
	friend istream& operator>>(istream& is, AssArray& a);
	friend ostream& operator<<(ostream& os, AssArray& a);
};
AssArray::AssArray()
{
	CodeError = 0;
	numbers[1] = "one";
	numbers[2] = "two";
	numbers[3] = "three";
	numbers[4] = "four";
	numbers[5] = "five";
	numbers[6] = "six";
	numbers[7] = "seven";
	numbers[8] = "eight";
	numbers[9] = "nine";
	numbers[10] = "ten";
	numbers[11] = "eleven";
	numbers[12] = "twelve";
	numbers[13] = "thirteen";
	numbers[14] = "fourteen	";
	numbers[15] = "fifteen";
	numbers[16] = "sixteen";
	numbers[17] = "seventeen";
	numbers[18] = "eighteen";
	numbers[19] = "nineteen";
	numbers[20] = "twenty";
	numbers[21] = "twenty one";
	numbers[22] = "twenty two";
	numbers[23] = "twenty three";
	numbers[24] = "twenty four";
	numbers[25] = "twenty five";
	numbers[26] = "twenty six";
	numbers[27] = "twenty seven";
	numbers[28] = "twenty eight";
	numbers[29] = "twenty nine";
	numbers[30] = "thirty";
	numbers[31] = "thirty one";
	numbers[32] = "thirty two";
	numbers[33] = "thirty three";
	numbers[34] = "thirty four";
	numbers[35] = "thirty five";
	numbers[36] = "thirty six";
	numbers[37] = "thirty seven";
	numbers[38] = "thirty eight";
	numbers[39] = "thirty nine";
	numbers[40] = "forty";
	numbers[41] = "forty one";
	numbers[42] = "forty two";
	numbers[43] = "forty three";
	numbers[44] = "forty four";
	numbers[45] = "forty five";
	numbers[46] = "forty six";
	numbers[47] = "forty seven";
	numbers[48] = "forty eight";
	numbers[49] = "forty nine";
	numbers[50] = "fifty";
	numbers[51] = "fifty one";
	numbers[52] = "fifty two";
	numbers[53] = "fifty three";
	numbers[54] = "fifty four";
	numbers[55] = "fifty five";
	numbers[56] = "fifty six";
	numbers[57] = "fifty seven";
	numbers[58] = "fifty eight";
	numbers[59] = "fifty nine";
	numbers[60] = "sixty";
	numbers[61] = "sixty one";
	numbers[62] = "sixty two";
	numbers[63] = "sixty three";
	numbers[64] = "sixty four";
	numbers[65] = "sixty five";
	numbers[66] = "sixty six";
	numbers[67] = "sixty seven";
	numbers[68] = "sixty eight";
	numbers[69] = "sixty nine";
	numbers[70] = "seventy";
	numbers[71] = "seventy one";
	numbers[72] = "seventy two";
	numbers[73] = "seventy three";
	numbers[74] = "seventy four";
	numbers[75] = "seventy five";
	numbers[76] = "seventy six";
	numbers[77] = "seventy seven";
	numbers[78] = "seventy eight";
	numbers[79] = "seventy nine";
	numbers[80] = "eighty";
	numbers[81] = "eighty one";
	numbers[82] = "eighty two";
	numbers[83] = "eighty three";
	numbers[84] = "eighty four";
	numbers[85] = "eighty five";
	numbers[86] = "eighty six";
	numbers[87] = "eighty seven";
	numbers[88] = "eighty eight";
	numbers[89] = "eighty nine";
	numbers[90] = "ninety";
	numbers[91] = "ninety one";
	numbers[92] = "ninety two";
	numbers[93] = "ninety three";
	numbers[94] = "ninety four";
	numbers[95] = "ninety five";
	numbers[96] = "ninety six";
	numbers[97] = "ninety seven";
	numbers[98] = "ninety eight";
	numbers[99] = "ninety nine";
	numbers[100] = "hundred";
	numbers[101] = "error";
}
string& AssArray::operator[](int index)
{
	if (index >= 100 || index < 0)
	{
		CodeError = -1;
		cout << " error INDEX set ";
		return numbers[101];
	}
	return numbers[index];
}
int& AssArray::operator()(string index)
{
	for (int i = 1; i <= 100; i++)
	{
		if (numbers[i] == index)
		{
			return i;
		}
	}
	cout << " error INDEX set ";
}
istream& operator>>(istream& is, AssArray& a)
{
	int i;
	for (i = 0; i < 3; i++) is >> a.numbers[i];
	return is;
}
ostream& operator<<(ostream& os, AssArray& a)
{
	int i;
	for (i = 0; i < 3; i++) os << " " << a.numbers[i] << " ";
	return os;
}
void task2()
{
	AssArray ass;
	cout << 45 << " and " << ass[45] << " \n";
	cout << ass("one") << " and " << "one" << " \n";
	cout << " Enter index: ";
	int index;
	cin >> index;
	cout << index << " and " << ass[index] << " \n";
	cout << " Enter index( by letters ): ";
	string sindex;
	cin >> sindex;
	cout << ass(sindex) << " and " << sindex;
}

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