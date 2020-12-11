#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Функція, що виводить масив
void displayArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

//Сортування Шелла
void ShellSort(int A[], int n)
{
    int counter_swap = 0;
    int counter_compare = 0;

    int gap = n / 2;
    while (gap > 0)
    {
        int j = 0;
        for (int i = gap; i < n; i++)
        {
            int temp = A[i];
            for (j = i; j >= gap && A[j - gap] > temp; j -= gap) //Перевірка, чи елемент j-gap більше поточного елемента
            {
                A[j] = A[j - gap];
                
                if (A[j] = A[j-gap]) //Якщо відбулася перестановка
                {
                    counter_swap++; 
                } 
            }
            A[j] = temp; //Поміняти елементи місцями

            counter_compare++; //В кінці кожного порівняння 

            //Проміжні результати
            displayArray(A, n);

            cout << endl;
        }
        gap /= 2;
    }

    cout << "Кiлькiсть порiвнянь: " << counter_compare << endl;
    cout << "Кiлькiсть перестановок: " << counter_swap << endl;
}

//Функція, що рандомно заповнює масив
void RandArray(int A[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        //Генерація чисел 0-1000
        A[i] = rand()%1000; 
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
    cout << "Набiр операцiй:"<<endl;
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
            RandArray(arr, size);
            ShellSort(arr, size);
            cout << "Вiсортований масив:" << endl;
            displayArray(arr, size);
            cout << "Введiть 0, щоб завершити виконання програми, продовжити - 1" << endl;
            cin >> y;
        }
        else
        {
            cout << "Введiть кiлькiсть елементiв масиву: " << endl;
            cin >> size;
            int* arr1 = new int[size];
            InputArray(arr1, size);
            ShellSort(arr1, size);
            cout << "Вiсортований масив:" << endl;
            displayArray(arr1, size);
            cout << "Введiть 0, щоб завершити виконання програми, продовжити - 1" << endl;
            cin >> y;
        }

    } while (y != 0);

    return 0;
}

