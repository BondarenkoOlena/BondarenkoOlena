//Варіант 1

#include <iostream>
#include <string.h>
#include <string.h>
#include <fstream>
#include <clocale>
#include <bitset>
using namespace std;
#define MAXSIZE 200

//Меню:
int task_manager()
{
	int task_number;
RENUMBER:	printf("Menu:\n     1.  Calculation of expressions using bitwise operations\n     2.  Data encryption using bitwise operations\n     3.  Data encryption using structures with bit fields\n     4.  The problem of using bitwise operations\n");
	printf("Enter task number you wanna do: ");
	scanf_s("%d", &task_number);
	if (task_number < 1 || task_number > 4)
	{
		system("cls");
		printf("There is only 5 options!\n\n");
		goto RENUMBER;
	}
	return task_number;
}

//Завдання 1: Обчислення виразів з використанням побітових операцій.
/*
Задано цілі числа a, b, c та d.Обчислити вираз без використання операцій множення та ділення(замінивши на їх операцій зсувів).
(15*a + 312*b) / 64 - 120*c + 121*d
([a*16 - a] + [256*b + 64*b - 8 *b]) / 64 - [c*128 + c*8] + [d*128 - d*8 + d]
*/
void task1()
{
	system("cls");
	int a, b, c, d, result;
	printf("Enter a: ");
	scanf_s("%d", &a);
	printf("Enter b: ");
	scanf_s("%d", &b);
	printf("Enter c: ");
	scanf_s("%d", &c);
	printf("Enter d: ");
	scanf_s("%d", &d);

	result = (((a << 4) - a + (b << 8) + (b << 6) - (b << 3)) >> 6) - (c << 7) + (c << 3) + (d << 7) - (d << 3) + d;
	printf("Result: %d", result);
}

//Завдання 2: Шифрування інформації.
/*
Задано 4 рядки тексту. У рядку до 32 символів. Доповнити пробілами рядки до 32 символів. Шифрувати тексти таким чином, щоб кожний символ тексту записувався у два байти. 
Два байти мають таку структуру:
у бітах 0-1 знаходиться номер рядка символу букви (2 біти),
у бітах 2-6 позиція символу в рядку (5 біти),
у бітах 7-14 ASCII - код символу (8 біт),
15 біт - біт парності (1 біт).
*/
void task2()
{
	char text[4][32];
	char c[MAXSIZE];
	unsigned short result[4][32];
	printf("Enter your text:\n");
	for (int i = 0; i < 4; i++)
	{
		cin >> c;
		for (int j = 0; j < 32; j++)
		{
			if (c[j] == NULL)
			{
				c[j] = ' ';
			}
			text[i][j] = c[j];			
		}
	}

	unsigned short r, w, b, t;
	for (unsigned short i = 0; i < 4; i++)
	{
		for (unsigned short j = 0; j < 32; j++)
		{
			r = i;
			w = j << 2;
			r |= w;
			w = text[i][j];
			w <<= 7;
			r |= w;
			b = 0;	t = 1;
			for (unsigned short k = 0; k < 15; k++)
			{
				if (r & t)
				{
					b = 1;
				}
				t <<= 1;
			}
			w = 1 << 15;
			if (b == 1)
			{
				r |= w;
			}
			result[i][j] = r;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			std::bitset<16> x(result[i][j]);
			cout << x << endl;
		}
	}
}

//Завдання 3
//Реалізувати завдання 2 з використанням структур з бітовими полями та об’єднаннями.
void task3()
{

}

//Завдання 4
/*
Вхідний рядок байтів має довжину, кратну 8, написати програму що кодує його за наступною схемою: 
вісім біт першого байта записуються, як нулеві біти перших восьми байтів, 
вісім біт другого – перші біти других восьми байтів і т.д. для кожних восьми байтів вхідної послідовності.
*/
void task4()
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
	case 4:
		task4();
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
