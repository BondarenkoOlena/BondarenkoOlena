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
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <vector>
using namespace std;
const int MAX_SIZE = 200;

int realise_functions()
{
    int function_number = 0;
    printf("Possible functions:\n   Function 1: Input/Output from console to file\n   Function 2: Input array from console\n   Function 3: Input random numbers to array\n   Function 4: Output array to binary file\n");
    printf("Enter function number you want to use: ");
    scanf_s("%d", &function_number);
    system("cls");
    return function_number;
}

//Функції введення масивів з консолі та запис масивів в текстовий файл(текстові файли);
void output_file_for_int(int N, int A[])
{
    ofstream MyFile("file.txt");

    for (int i = 0; i < N; i++)
    {
        MyFile << A[i] << "   ";
    }

    MyFile.close();
}
void output_file_for_float(int N, float A[])
{
    ofstream MyFile("file.txt");

    for (int i = 0; i < N; i++)
    {
        MyFile << A[i] << "   ";
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
        A[i] = rand() % 100;
    }
    return A;
}
float* random_array_for_float(int N)
{
    srand(time(0));
    float X[MAX_SIZE];
    for (int i = 0; i < N; i++)
    {
        X[i] = rand() % 100;
    }
    return X;
}
void output_binary_file_for_int(int N, int A[])
{
    ofstream MyFile("binary.dat", ios::out | ios::binary);
    for (int i = 0; i < N; i++)
    {
        MyFile.write((char*)&A[i], sizeof(int));
    }
    MyFile.close();
}
void output_binary_file_for_float(int N, float A[])
{
    ofstream MyFile("binary.dat", ios::out | ios::binary);
    for (int i = 0; i < N; i++)
    {
        MyFile.write((char*)&A[i], sizeof(float));
    }
    MyFile.close();
}

//Функції розв’язання задач згідно варіанту з використанням динамічних масивів.
//Вхідні дані зчитаються з файлів, результати записуються в нові файли та виводиться в консоль.
void read_from_file_to_file_to_console()
{
    ofstream MyFile;
    MyFile.open("file.txt", ios::out);
}

//Функцію читає дані з файлів в контейнер (vector, valarray або array) та з контейнера дані виводиться в консоль.
vector<int> read_from_file_to_container_to_console_for_int()
{
    std::streampos file_size;
    std::ifstream file("file.txt", std::ios::out);

    file.seekg(0, std::ios::end);
    file_size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<int> A(file_size);
    file.read((char*)&A[0], file_size);

    for (int i = 0; i < A.size(); i++)
    {
        printf("A[%d]: %d", i, A[i]);
    }
    return A;
}
vector<float> read_from_file_to_container_to_console_for_float()
{
    std::streampos file_size;
    std::ifstream file("file.txt", std::ios::out);

    file.seekg(0, std::ios::end);
    file_size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<float> X(file_size);
    file.read((char*)&X[0], file_size);

    for (int i = 0; i < X.size(); i++)
    {
        printf("X[%d]: %f", i, X[i]);
    }
    return X;
}

void task1()
{
    int function_number = realise_functions();
    //Із одновимірного масиву А розміру N побудувати масив В із всіх додатних елементів.
    int A[MAX_SIZE], N, B[MAX_SIZE], B_index = 0;
RESIZE1:  N = input_arrays_size();
    if (N > 0)
    {
        for (int i = 0; i < N; i++)
        {
            printf("Enter A[%d]: ", i);
            scanf_s("%d", &A[i]);
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
    else
    {
        printf("Please enter N > 0!\n");
        goto RESIZE1;
    }
}

void task2()
{
    int function_number = realise_functions();
    /*>>Зауваження. При розв’язуванні використати змінну(або декілька змінних) типу вказівник,
яка би вказувала поточний елемент масиву(або на деякий елемент масиву), що
розглядається (у приклад 5 змінна – вказівник pC вказує на поточний елемент масиву C).
Заданий одномірний масив цілих чисел А розміру N.
   Знайти номер останнього максимального елемента серед додатних елементів, починаючи з першого елемента, більшого заданого числа Т.*/
    int A[MAX_SIZE], N, T, max_index = 0, positive_index = 0;
    printf("Enter T: ");
    scanf_s("%d", &T);
RESIZE2:  N = input_arrays_size();
    if (N > 0)
    {
        for (int i = 0; i < N; i++)
        {
            printf("Enter A[%d]: ", i);
            scanf_s("%d", &A[i]);
            if (A[i] > 0)
            {
                positive_index++;
                if (A[i] > T)
                {
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
    else
    {
        printf("Please enter N > 0!\n");
        goto RESIZE2;
    }
}

void task3()
{
    int function_number = realise_functions();
    /*Задано дійсні величини a,b (a < b) і масив чисел X (n), n <= 200. 
Розробити програму, яка обчислює суму всіх X (i) < a , добуток всіх X (i) > b
і знаходить max X(i) та min X(i) серед X(i)є[a,b], i=1,2,...,n.*/
    float a, b, X[MAX_SIZE];
AB:  printf("Enter a: ");
    scanf_s("%f", &a);
    printf("Enter b: ");
    scanf_s("%f", &b);
    if (a >= b)
    {
        printf("a must be less than b!\n");
        goto AB;
    }

    int N;
RESIZE3:  N = input_arrays_size();
    if (N > 0)
    {
        float Sum = 0, Mult = 1, max = a, min = b;
        bool Sum_flag = false, Mult_flag = false, MinMax_flag = false;
        for (int i = 0; i < N; i++)
        {
            printf("Enter X[%d]: ", i);
            scanf_s("%f", &X[i]);
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
            printf("There is no number less than a");
        }
        if (Mult_flag == true)
        {
            printf("Mult of numbers bigger than b = %0.2f\n", Mult);
        }
        else
        {
            printf("There is no number bigger than b");
        } 
        if (MinMax_flag == true)
        {
            printf("Max number between a and b = %0.2f\n", max);
            printf("Min number between a and b = %0.2f\n", min);
        }
        else
        {
            printf("There is no number between a and b");
        }
    }
    else
    {
        goto RESIZE3;
    }
}

int main()
{
TASK:  printf("Tasks:\n   Task 1: Array of positive numbers\n   Task 2: Index of last max number\n   Task 3: Find stuff in between\n");
    int task_manager = 0;
    printf("Enter task number you want to do: ");
    scanf_s("%d", &task_manager);
    system("cls");

    if (task_manager == 1)
    {
        task1();
    }
    else if (task_manager == 2)
    {
        task2();
    }
    else if (task_manager == 3)
    {
        task3();
    }
    else
    {
        printf("Please enter number from 1 to 3!");
        goto TASK;
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
