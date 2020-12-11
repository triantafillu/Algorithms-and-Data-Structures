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

//Функція, що міняє елементи місцями
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//Функція, що знаходить максимальний елемент в масиві
int FindMax(int A[], int n)
{
    int max_el = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max_el)
        {
            max_el = A[i];
        }
    }
    return max_el;
}

//Сортування підрахунком
void CountingSort(int A[], int n, int digit)
{
    int* out_A = new int [n]; //Масив, що тримає вихідні дані
    int i, count_A[10] = { 0 }; //Масив, що підраховує кількість входжень елемента  у вхідний масив, заповнити нулями

    //Підрахувати кількість входжень елементів у у вхідний масив
    for (i = 0; i < n; i++)
    {
        count_A[(A[i] / digit) % 10]++;
    }    

    cout << "Масив для пiдрахунку:" << endl;
    displayArray(count_A, 10);

    //Вирахувати положення елементів у вихідному масиві
    for (i = 1; i < 10; i++)
    {
        count_A[i] += count_A[i - 1];
    }    

    cout << "Масив для пiдрахунку пiсля пiдсумування:" << endl;
    displayArray(count_A, 10);

    //Заповнити вихідний масив
    for (i = n - 1; i >= 0; i--)
    {
        out_A[count_A[(A[i] / digit) % 10] - 1] = A[i];
        count_A[(A[i] / digit) % 10]--;
    }

    //Скопіювати вихідний масив у вхідний масив
    for (i = 0; i < n; i++)
    {
        A[i] = out_A[i];
    }     
}

//Порозрядне сортування 
void RadixSort(int arr[], int n)
{
    //Знайти максимальний елемент 
    int k = FindMax(arr, n);

    //Для кожного розряду (у максимального елемента максимальрна кількість розрядів)
    for (int i = 1; k / i > 0; i *= 10)
    {
        CountingSort(arr, n, i);
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
            RadixSort(arr, size);
            cout << "Вiсортований масив:" << endl;
            displayArray(arr, size - 1);

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
            RadixSort(arr1, size);
            cout << "Вiсортований масив:" << endl;
            displayArray(arr1, size);

            cout << "Введiть 0, щоб завершити виконання програми, продовжити - 1" << endl;
            cin >> y;
        }

    } while (y != 0);

    return 0;
}

