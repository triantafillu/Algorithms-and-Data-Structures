#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Глобальні змінні (щоб можна було використати з будь-якої частини програми)
int counter_swap = 0;
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

//Функція, що міняє елементи місцями
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int Partition(int A[], int low, int high, int n) //n - щоб виводити проміжні результати
{
    int pivot = A[high];
    int j = low; //Індекс розділення

    for (int i = low; i < high; i++)
    {
        if (A[i] <= pivot)
        {
            //Поміняти місцямиfor (int i = low; i < high; i++)
            swap(&A[i], &A[j]);
            j++;
            counter_swap++;
        }
        counter_compare++;
    }

    //Поміняти місцями поточний розділювач з індексом
    swap(&A[j], &A[high]);
    counter_swap++;

    //Виведення проміжних результатів
    displayArray(A, n);
    cout << endl;

    return j;   
}

//Швидке сортування
void QuickSort(int A[], int low, int high, int n)
{
    if (low < high)
    {
        int j = Partition(A, low, high,n);
        QuickSort(A, low, j - 1,n);
        QuickSort(A, j + 1, high,n);
    }
    
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

            //Створення та сортування масиву
            RandArray(arr, size);
            QuickSort(arr, 0, size-1,  size);
            cout << "Вiсортований масив:" << endl;
            displayArray(arr, size-1);

            cout << "Кiлькiсть порiвнянь: " << counter_compare << endl;
            cout << "Кiлькiсть перестановок: " << counter_swap << endl;

            //Обнулення лічильників
            counter_compare = 0;
            counter_swap = 0;

            cout << "Введiть 0, щоб завершити виконання програми, продовжити - 1" << endl;
            cin >> y;
        }
        else
        {
            cout << "Введiть кiлькiсть елементiв масиву: " << endl;
            cin >> size;
            int* arr1 = new int[size];

            //Створення та сортування масиву
            InputArray(arr1, size);
            QuickSort(arr1, 0, size-1, size);
            cout << "Вiсортований масив:" << endl;
            displayArray(arr1, size);

            cout << "Кiлькiсть порiвнянь: " << counter_compare << endl;
            cout << "Кiлькiсть перестановок: " << counter_swap << endl;

            //Обнулення лічильників
            counter_compare = 0;
            counter_swap = 0;

            cout << "Введiть 0, щоб завершити виконання програми, продовжити - 1" << endl;
            cin >> y;
        }

    } while (y != 0);

    return 0;
}

