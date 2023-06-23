#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <stack>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#pragma warning (disable: 4996)
using namespace std;

int task_manager()
{
	int task_number;
RENUMBER:	printf("Menu:\n     1.  Task 1\n     2.  Task 2\n     3.  Task 3\n     4.  Task 4\n     5.  Task 5\n     6.  Task 6\n");
	printf("Enter task number you wanna do: ");
	scanf_s("%d", &task_number);
	if (task_number < 1 || task_number > 6)
	{
		system("cls");
		printf("There is only 6 options!\n\n");
		goto RENUMBER;
	}
	return task_number;
}

//Задано натуральне число n . Розробити програму для обчислення заданих сум, використовуючи рекурсивні процедури або функції.
int factorial(int k)
{
	if (k != 1 && k != 0)
	{
		return k * factorial(--k);
	}
	else
	{
		return 1;
	}
}
double sum(double a, double b, int n, int k)
{
	if (k <= n)
	{
		double res = a * b / factorial(k);
		return res + sum(0.5 * (sqrt(b) + 0.5 * sqrt(a)), 2 * a * a + b, n, ++k);
	}
	else
	{
		return 0;
	}
}
void task1()
{
	cout << " Enter n: ";
	int n;
	cin >> n;
	double Sum = sum(1, 1, n, 1);
	cout << " Sum: " << Sum;
}

/*. Задано текст, в якому є круглі дужки.Розробити програму, яка перевіряє
збалансованість дужок у заданому тексті.Якщо дужки збалансовані, то для
кожної пари друкує їх номери позицій у тексті за зростанням номерів дужок,
що закриваються.Якщо дужки не збалансовані, то виводить повідомлення
про це.*/
void task2()
{
	char text[200];
	cout << " Enter your text: ";
	cin >> text;
	int size = sizeof(text) / sizeof(char);
	stack<char> st;
	int k = 0;
	bool match_chacker = true;
	for (int i = 0; i < size; i++)
	{
		if (text[i] == '(')
		{
			st.push('(');
		}
		if (text[i] == ')')
		{
			if (st.empty())
			{
				cout << " Don`t match";
				match_chacker = false;
			}
			else
			{
				st.pop();
			}
		}
	}
	if (!st.empty())
	{
		cout << " Don`t match";
		match_chacker = false;
	}
	if (match_chacker == true)
	{
		for (int i = 0; i < size; i++)
		{
			if (text[i] == ')')
			{
				for (int j = i - 1; j >= 0; j--)
				{
					if (text[j] == '(')
					{
						cout << " ( = " << j << ", ) = " << i << endl;
						text[j] = 0;
						text[i] = 0;
						break;
					}
				}
			}
		}
	}
}

/* Розробити програму для розв’язання задачі згідно варіанту.
Створюємо текстовий файл текстовим редактором. Зчитуємо дані з
вхідного файлу, здійснюємо обробку даних, результати зберігаємо в іншому
текстовому файлі. Назви вхідного і вихідного файлу вводяться як текстові
рядки.*/
/* Задано текст, слова в якому розділені пробілами і розділовими знаками.
Розробити програму, яка вилучає з цього тексту всі слова з подвоєнням літер
і записує їх в окремий рядок, розділяючи пробілами. Друкує окремо вилучені
слова і текст, що залишився після вилучення слів. */
bool DoublingLetters(char word[])
{
	for (int j = 0; j < strlen(word) - 1; j++)
	{
		if (word[j] == word[j + 1])
		{
			return true;
		}
	}
	return false;
}
void task3()
{
	FILE* dat, * res, * res1;
	if ((dat = fopen("file.txt", "r")) == NULL)
	{
		printf("Файл даних не відкритий");
		return;
	}
	if ((res = fopen("res.txt", "w")) == NULL)
	{
		printf("Файл результату не відкритий");
		return;
	}
	if ((res1 = fopen("res1.txt", "w")) == NULL)
	{
		printf("Файл результату не відкритий");
		return;
	}
	char text[300], word[300], text1[300] = "";
	int c = 0;
	while (fgets(text, 300, dat) != NULL)
	{
		for (int i = 0; i <= strlen(text); i++)
		{
			if (text[i] != ' ' && text[i] != '.' && text[i] != ',' && text[i] != '?' && text[i] != '!' && text[i] != ';' && text[i] != ':' && text[i] != '\"' && text[i] != '\n' && text[i] != '\0')
			{
				word[c] = text[i];
				c++;
			}
			else
			{
				word[c] = '\0';
				if (DoublingLetters(word))
				{
					fprintf(res, "%s ", word);
					printf("%s   ", &word);
				}
				else
				{
					strcat(text1, word);
				}
				int n = strlen(text1);
				text1[n] = text[i];
				text1[n + 1] = '\0';
				strcpy(word, "");
				c = 0;
			}
		}
		fprintf(res1, "%s ", text1);
		printf("\n%s   ", &text1);
		strcpy(text1, "");
	}
	fclose(dat);
	fclose(res);
	fclose(res1);
}

//Даний набір цілих чисел. Знайти кількість нулів у вихідному наборі. Використовувати ітератор ptin_iterator та алгоритм count.
void task4()
{
	list<int> myList;
	int size;
	cout << " Enter list size: ";
	cin >> size;
	cout << " Enter number set: ";
	for (int i = 0; i < size; i++)
	{
		int temp;
		cin >> temp;
		myList.push_back(temp);
	}
	list<int>::iterator ptin_iterator = myList.begin();
	int zero = count(ptin_iterator, myList.end(), 0);
	cout << "0 count: " << zero;
}

/* Дано числа A і B та вектори V1 і V2, кожен з яких містить не менше
10 елементів. Заповнити перші 5 елементів кожного вектора значеннями A, а
останні 5 – значеннями B. При перетворенні вектора V1 використовувати два
виклики алгоритму fill, при перетворенні вектора V2 використовувати два
виклики алгоритму fill_n.*/
void task5()
{
	int A, B;
	cout << " Enter A: ";
	cin >> A;
	cout << " Enter B: ";
	cin >> B;

	vector<int> V1(10), V2(10);

	vector<int>::iterator it = V1.begin();
	fill(it, it + 5, A);
	it += 5;
	fill(it, it + 5, B);
	for (int i : V1)
	{
		cout << i << "   ";
	}
	cout << endl;

	it = V2.begin();
	fill_n(it, 5, A);
	it += 5;
	fill_n(it, 5, B);
	for (int i : V2)
	{
		cout << i << "   ";
	}
}

/* Дано вектор V. визначити кількість повторень кожного числа у
векторі V і вивести всі різні елементи вектора V разом з кількістю їх повторень (у
порядку зростання значень елементів); кількість повторень виводити відразу після
значення відповідного елемента. Використовувати допоміжне відображення M
(клас map), ключами якого є різні елементи вектора V, а значеннями кількість
повторень цих елементів. При заповненні відображення M не використовувати
умовні конструкції (достатньо операцій індексування [] та інкременту). Елементи
вектора V (при заповненні відображення M) та елементи відображення M (при
виведенні отриманих результатів) перебирати в циклі з параметром ітератором
відповідного контейнера.*/
void task6()
{
	vector<int> V;
	map<int, int> M;

	cout << " Enter vector size: ";
	int size;
	cin >> size;
	cout << " Enter vector: ";
	for (int i = 0; i < size; i++)
	{
		int temp;
		cin >> temp;
		V.push_back(temp);
	}
	sort(V.begin(), V.end());
	auto itr = V.begin();
	auto itrend = V.end();
	--itrend;
	do {
		int temp = 1;
		while (*itr == *(++itr))
		{
			temp++;
			if (itr == itrend)
				break;
		}
		--itr;
		M.insert({ *(itr), temp });
		itr++;
	} while (itr != itrend);
	for (auto itr = M.begin(); itr != M.end(); ++itr)
	{
		cout << itr->first << " -> " << itr->second << endl;
	}
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
	case 5:
		task5();
		break;
	case 6:
		task6();
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