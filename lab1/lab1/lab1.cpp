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
using namespace std;
const int MAX_SIZE = 200;

void task1()
{
    //Із одновимірного масиву А розміру N побудувати масив В із всіх додатних елементів.
    int A[MAX_SIZE], N, B[MAX_SIZE], B_index = 0;
RESIZE1:  printf("Enter N: ");
    scanf_s("%d", &N);
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
    /*>>Зауваження. При розв’язуванні використати змінну(або декілька змінних) типу вказівник,
яка би вказувала поточний елемент масиву(або на деякий елемент масиву), що
розглядається (у приклад 5 змінна – вказівник pC вказує на поточний елемент масиву C).
Заданий одномірний масив цілих чисел А розміру N.
   Знайти номер останнього максимального елемента серед додатних елементів, починаючи з першого елемента, більшого заданого числа Т.*/
    int A[MAX_SIZE], N, T, max_index = 0, positive_index = 0;
    printf("Enter T: ");
    scanf_s("%d", &T);
RESIZE2:  printf("Enter N: ");
    scanf_s("%d", &N);
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
RESIZE3:  printf("Enter N: ");
    scanf_s("%d", &N);
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
    int task_manager = 0;
TASK:  printf("Enter task number you want to do: ");
    scanf_s("%d", &task_manager);

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
        printf("Please enter number from 1 to 3!\n");
        goto TASK;
    }

    string answer;
FIN:  printf("\nDo you want to do one more task? Enter 'yes' if you do, and 'no' if you don`t: ");
    cin >> answer;
    if (answer == "yes")
    {
        goto TASK;
    }
    if (answer == "no")
    {
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
