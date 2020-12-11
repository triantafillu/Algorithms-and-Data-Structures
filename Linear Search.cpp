#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;
int counter_compare = 0;

//Функція, що виводить масив
void displayArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

//Лінійний пошук
int LinearSearch(int A[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] == key)
        {
            return i;
        }
        counter_compare++;
    }
    return -1;
}

//Функція, що рандомно заповнює масив
void RandArray(int A[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        //Генерація чисел 0-1000
        A[i] = rand() % 1000;
    }
}

//Функція, що дозволяє користувачу ввести масив 
void InputArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "[" << i + 1 << "] = ";
        cin >> A[i];
        cout << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int y;
    cout << "Набiр операцiй:" << endl;
    cout << "1. Рандомний масив" << endl << "2. Ввести масив" << endl;
    int n;
    int size;

    do
    {
        cin >> n;

        if (n == 1)
        {
            cout << "Введiть кiлькiсть елементiв масиву: " << endl;
            cin >> size;
            int* arr = new int[size];
            int key;
            
            RandArray(arr, size);
            displayArray(arr, size);

            cout << "Введiть елемент, який бажаєте знайти:" << endl;
            cin >> key;
            int ind = LinearSearch(arr, size, key);
            if (ind != -1)
            {
                cout << "Елемент " << key << " знайдено пiд iндексом [" << ind << "]" << endl;
            }
            else
            {
                cout << "Елемент не знайдено" << endl;
            }

            cout << "Кiлькiсть порiвнянь: " << counter_compare << endl;
            counter_compare = 0;

            cout << "Введiть 0, щоб завершити виконання програми, продовжити - 1" << endl;
            cin >> y;
        }
        else
        {
        cout << "Введiть кiлькiсть елементiв масиву: " << endl;
        cin >> size;
        int* arr1 = new int[size];
        int key;

        InputArray(arr1, size);
        cout << "Введiть елемент, який бажаєте знайти:" << endl;
        cin >> key;
        int ind = LinearSearch(arr1, size, key);
        if (ind != -1)
        {
            cout << "Елемент " << key << " знайдено пiд iндексом [" << ind << "]" << endl;
        }
        else
        {
            cout << "Елемент не знайдено" << endl;
        }
        cout << "Кiлькiсть порiвнянь: " << counter_compare << endl;
        counter_compare = 0;

        cout << "Введiть 0, щоб завершити виконання програми, продовжити - 1" << endl;
        cin >> y;
        }

    } while (y != 0);

    return 0;
}