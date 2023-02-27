// lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
* Реалізувати:
1.	Функції введення масивів з консолі та запис масивів в текстовий файл(текстові файли);
2.	Функції введення розміру масиву(масивів) з консолі, створення масиву(масивів) з використанням датчика випадкових чисел та 
запис масиву(масивів) в бінарний файл(бінарний файли);
3.	Функції розв’язання задач згідно варіанту з використанням динамічних масивів.
Вхідні дані зчитаються з файлів, результати записуються в нові файли та виводиться в консоль.
4.	Функцію читає дані з файлів в контейнер (vector, valarray або array) та з контейнера дані виводиться в консоль.
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <tuple>
#include <math.h>
using namespace std;
const int MAX_SIZE = 200;

//Завдання 1
//Із одновимірного масиву А розміру N побудувати масив В із всіх додатних елементів.
void task1(int N, int A[])
{
    int B[MAX_SIZE], B_index = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] > 0)
        {
            B[B_index] = A[i];
            B_index++;
        }
    }

    if (B_index == 0)
    {
        printf("There is no positive numbers!");
    }
    else
    {
        for (int i = 0; i < B_index; i++)
        {
            printf("B[%d]: %d\n", i, B[i]);
        }
    }
}

//Завдання 2
/*>>Зауваження. При розв’язуванні використати змінну(або декілька змінних) типу вказівник,
яка би вказувала поточний елемент масиву(або на деякий елемент масиву), що
розглядається (у приклад 5 змінна – вказівник pC вказує на поточний елемент масиву C).
Заданий одномірний масив цілих чисел А розміру N.
   Знайти номер останнього максимального елемента серед додатних елементів, починаючи з першого елемента, більшого заданого числа Т.*/
void task2(int N, int A[])
{
    int T, max_index = 0, positive_index = 0;
    printf("Enter T: ");
    scanf_s("%d", &T);
    int max = T;

    for (int i = 0; i < N; i++)
    {
        if (A[i] > 0)
        {
            positive_index++;
            if (A[i] > T && A[i] >= max)
            {
                max = A[i];
                max_index = positive_index;
            }
        }
    }

    if (max_index == 0)
    {
        printf("There is no positive number bigger that %d!", T);
    }
    else
    {
        printf("Index of max positive number bigger than %d: %d", T, max_index);
    }
}

//Завдання 3
/*Задано дійсні величини a,b (a < b) і масив чисел X (n), n <= 200.
Розробити програму, яка обчислює суму всіх X (i) < a , добуток всіх X (i) > b
і знаходить max X(i) та min X(i) серед X(i)є[a,b], i=1,2,...,n.*/
void task3(int N, double X[])
{
    float a, b;
AB:  printf("Enter a: ");
    scanf_s("%f", &a);
    printf("Enter b: ");
    scanf_s("%f", &b);
    if (a >= b)
    {
        printf("a must be less than b!\n");
        goto AB;
    }

    float Sum = 0, Mult = 1, max = a, min = b;
    bool Sum_flag = false, Mult_flag = false, MinMax_flag = false;
    for (int i = 0; i < N; i++)
    {
        if (X[i] < a)
        {
            Sum += X[i];
            Sum_flag = true;
        }
        else if (X[i] > b)
        {
            Mult *= X[i];
            Mult_flag = true;
        }
        else
        {
            MinMax_flag = true;
            if (X[i] > max)
            {
                max = X[i];
            }
            if (X[i] < min)
            {
                min = X[i];
            }
        }
    }

    if (Sum_flag == true)
    {
        printf("Sum of numbers less than a = %0.2f\n", Sum);
    }
    else
    {
        printf("There is no number less than a\n");
    }
    if (Mult_flag == true)
    {
        printf("Mult of numbers bigger than b = %0.2f\n", Mult);
    }
    else
    {
        printf("There is no number bigger than b\n");
    }
    if (MinMax_flag == true)
    {
        printf("Max number between a and b = %0.2f\n", max);
        printf("Min number between a and b = %0.2f\n", min);
    }
    else
    {
        printf("There is no number between a and b\n");
    }
}

//Меню
int realise_functions()
{
    int function_number = 0;
    printf("Possible functions:\n   Function 1: Input/Output from console to file\n   Function 2: Input array from console + Input random numbers to array + Output array to binary file\n   Function 3: Input/Output array from file to file to console\n   Function 4: InputOutput array from file to vector to console\n");
    printf("Enter function number you want to use: ");
    scanf_s("%d", &function_number);
    system("cls");
    return function_number;
}
int realise_tasks()
{
    printf("Tasks:\n   Task 1: Array of positive numbers\n   Task 2: Index of last max number\n   Task 3: Find stuff in between\n");
    int task_manager = 0;
    printf("Enter task number you want to do: ");
    scanf_s("%d", &task_manager);
    system("cls");
    return task_manager;
}

//Функції введення масивів з консолі та запис масивів в текстовий файл(текстові файли);
void output_file_for_int(int task_manager)
{
RESIZE:  int N;
    printf("Enter N: ");
    scanf_s("%d", &N);
    if (N <= 0)
    {
        printf("Please enter N > 0!\n");
        goto RESIZE;

    }
    int A[MAX_SIZE];
    for (int i = 0; i < N; i++)
    {
        printf("Enter A[%d]: ", i);
        scanf_s("%d", &A[i]);
    }
    if (task_manager == 1)
    {
        task1(N, A);
    }
    else
    {
        task2(N, A);
    }

    ofstream MyFile("file.txt");

    for (int i = 0; i < N; i++)
    {
        MyFile << A[i] << "   ";
    }

    MyFile.close();
}
void output_file_for_float()
{
RESIZE:  int N;
    printf("Enter N: ");
    scanf_s("%d", &N);
    if (N <= 0)
    {
        printf("Please enter N > 0!\n");
        goto RESIZE;
    }
    double X[MAX_SIZE];
    for (int i = 0; i < N; i++)
    {
        printf("Enter X[%d]: ", i);
        scanf_s("%lf", &X[i]);
    }
    task3(N, X);

    ofstream MyFile("doublefile.txt");
    MyFile << N << endl;
    for (int i = 0; i < N; i++)
    {
        MyFile << X[i] << "   ";
    }
    MyFile.close();
}

//Функції введення розміру масиву(масивів) з консолі, створення масиву(масивів) з використанням датчика випадкових чисел та 
//запис масиву(масивів) в бінарний файл(бінарний файли);
int input_arrays_size()
{
    int N;
    printf("Enter N: ");
    scanf_s("%d", &N);
    return N;
}
int* random_array_for_int(int N)
{
    srand(time(0));
    int A[MAX_SIZE];
    for (int i = 0; i < N; i++)
    {
        A[i] = rand();
        if (rand() % 2 == 1)
        {
            A[i] = -A[i];
        }
        printf("A[%d]: %d\n", i, A[i]);
    }
    return A;
}
double* random_array_for_float(int N)
{
    srand(time(0));
    double X[MAX_SIZE];
    for (int i = 0; i < N; i++)
    {
        X[i] = 100 * rand() / (1.0 + rand());
        if (rand() % 2 == 1)
        {
            X[i] = -X[i];
        }
        printf("A[%d]: %lf\n", i, X[i]);
    }
    return X;
}
void output_binary_file_for_int(int task_manager)
{
    int N = input_arrays_size();
    int* A = random_array_for_int(N);
    if (task_manager == 1)
    {
        task1(N, A);
    }
    else
    {
        task2(N, A);
    }
    ofstream MyFile("binary.dat", ios::out | ios::binary);
    for (int i = 0; i < N; i++)
    {
        MyFile.write((char*)&A[i], sizeof(int));
    }
    MyFile.close();
}
void output_binary_file_for_float()
{
    int N = input_arrays_size();
    double* X = random_array_for_float(N);
    task3(N, X);
    ofstream MyFile("binary.dat", ios::out | ios::binary);
    for (int i = 0; i < N; i++)
    {
        MyFile.write((char*)&X[i], sizeof(double));
    }
    MyFile.close();
}

//Функції розв’язання задач згідно варіанту з використанням динамічних масивів.
//Вхідні дані зчитаються з файлів, результати записуються в нові файли та виводиться в консоль.
void read_from_file_to_file_to_console_for_int(int task_manager)
{
    char temp_file_data[MAX_SIZE];
    int temp_index = 0;
    int* pA = new int[MAX_SIZE];
    int A_index = 0;
    ifstream MyFile;
    MyFile.open("file.txt");
    int temp = 0;
    bool negative_indicator = false;

    while (MyFile.good() && temp_index < 200)
    {
        MyFile.get(temp_file_data[temp_index]);
        temp_index++;
    }
    for (int i = 0; i < temp_index; i++)
    {
        if (temp_file_data[i] != ' ' && temp_file_data[i] != '-')
        {
            temp = temp * 10 + int(temp_file_data[i]) - 48;
        }
        else if (temp_file_data[i] == '-')
        {
            negative_indicator = true;
        }
        else
        {
            if (temp_file_data[i + 1] == ' ' && temp_file_data[i + 2] == ' ' && negative_indicator == false)
            {
                pA[A_index] = temp;
                A_index++;
                temp = 0;
            }
            if (temp_file_data[i + 1] == ' ' && temp_file_data[i + 2] == ' ' && negative_indicator == true)
            {
                pA[A_index] = -temp;
                A_index++;
                temp = 0;
                negative_indicator = false;
            }
        }
    }

    for (int i = 0; i < A_index; i++)
    {
        printf("A[%d]: %d\n", i, pA[i]);
    }
    if (task_manager == 1)
    {
        task1(A_index, pA);
    }
    else
    {
        task2(A_index, pA);
    }
    MyFile.close();

    ofstream NewFile("newfile.txt");
    for (int i = 0; i < A_index; i++)
    {
        NewFile << pA[i] << "   ";
    }
    NewFile.close();
}
void read_from_file_to_file_to_console_for_float()
{
    int N;
    double* pX = new double[MAX_SIZE];
    ifstream MyFile("doublefile.txt");
    MyFile >> N;
    double d;
    for (int i = 0; i < N; i++)
    {
        MyFile >> d;
        pX[i] = d;
        printf("X[%d]: %0.3lf\n", i, pX[i]);
    }
    task3(N, pX);
    MyFile.close();

    ofstream NewFile("newdoublefile.txt");
    for (int i = 0; i < N; i++)
    {
        NewFile << pX[i] << "   ";
    }
    NewFile.close();
}

//Функцію читає дані з файлів в контейнер (vector, valarray або array) та з контейнера дані виводиться в консоль.
void read_from_file_to_container_to_console_for_int(int task_manager)
{
    char temp_file_data[MAX_SIZE];
    int temp_index = 0;
    int A[MAX_SIZE];
    int A_index = 0;
    vector<int> A_vector;
    ifstream MyFile;
    MyFile.open("file.txt");
    int temp = 0;
    bool negative_indicator = false;
    while (MyFile.good() && temp_index < 200)
    {
        MyFile.get(temp_file_data[temp_index]);
        temp_index++;
    }
    for (int i = 0; i < temp_index; i++)
    {
        if (temp_file_data[i] != ' ' && temp_file_data[i] != '-')
        {
            temp = temp * 10 + int(temp_file_data[i]) - 48;
        }
        else if (temp_file_data[i] == '-')
        {
            negative_indicator = true;
        }
        else
        {
            if (temp_file_data[i + 1] == ' ' && temp_file_data[i + 2] == ' ' && negative_indicator == false)
            {
                A_vector.push_back(temp);
                A[A_index] = temp;
                A_index++;
                temp = 0;
            }
            if (temp_file_data[i + 1] == ' ' && temp_file_data[i + 2] == ' ' && negative_indicator == true)
            {
                A_vector.push_back(-temp);
                A[A_index] = -temp;
                A_index++;
                temp = 0;
            }
        }
    }

    for (int i = 0; i < A_index; i++)
    {
        printf("A[%d]: %d\n", i, A_vector[i]);
    }

    if (task_manager == 1)
    {
        task1(A_index, A);
    }
    else
    {
        task2(A_index, A);
    }
}
void read_from_file_to_container_to_console_for_float()
{
    vector<double> X_vector;
    double X[MAX_SIZE];
    ifstream MyFile("doublefile.txt");
    if (MyFile.fail()) return;
    int N;
    double d;
    MyFile >> N;
    for (int i = 0; i < N; i++)
    {
        MyFile >> d;
        X_vector.push_back(d);
        X[i] = d;
        printf("X[%d]: %0.3lf\n", i, X_vector[i]);
    }
    task3(N, X);
    MyFile.close();
}

int main()
{
TASK:  int task_manager = realise_tasks();
    if (task_manager > 3 || task_manager < 1)
    {
        printf("Please enter number from 1 to 3!\n");
        goto TASK;
    }
FUNK:  int function_manager = realise_functions();
    if (function_manager > 4 || function_manager < 1)
    {
        printf("Please enter number from 1 to 4!\n");
        goto FUNK;
    }
    if (task_manager == 3)
    {
        switch (function_manager)
        {
        case 1:
            output_file_for_float();
            break;
        case 2:
            output_binary_file_for_float();
            break;
        case 3:
            read_from_file_to_file_to_console_for_float();
            break;
        case 4:
            read_from_file_to_container_to_console_for_float();
            break;
        default:
            break;
        }
    }
    else
    {
        switch (function_manager)
        {
        case 1:
            output_file_for_int(task_manager);
            break;
        case 2:
            output_binary_file_for_int(task_manager);
            break;
        case 3:
            read_from_file_to_file_to_console_for_int(task_manager);
            break;
        case 4:
            read_from_file_to_container_to_console_for_int(task_manager);
            break;
        default:
            break;
        }
    }

    string answer;
FIN:  printf("\nDo you want to do one more task? Enter 'yes' if you do, and 'no' if you don`t: ");
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
        system("cls");
        printf("Please enter 'yes' or 'no'\n");
        goto FIN;
    }
}
