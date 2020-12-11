#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int counter_compare = 0;

//Функція, що виводить масив
void displayArray(char A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i];
    }
    cout << endl;
}

//Бінарний пошук
bool NativeTextSearch(char text[], int n, char key[], int ks)
{
    for (int i = 0; i <= n - ks; i++)
    {
        int j;
        //Перевірити наявність фрагменту для кожного і
        for (j = 0; j < ks; j++)
        {
            //Якщо один з послідовних елементів не відповідає цьому елементу в фрагменті
            if (text[i + j] != key[j])
            {
                break;
            }
            counter_compare++;
        }

        //Якщо фрагмент повність знайдено
        if (j == ks)
        {
            cout << "Фрагмент знайдено пiд iндексом [" << i <<"]"<< endl;
            return true;
        }
    }
    return false;
}

//Функція, що рандомно заповнює масив
void RandArray(char A[], int n)
{
    //Букви, з яких генерується масив (латинський алфавіт)
    char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u','v', 'w', 'x', 'y', 'z' };

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        //Генерація чисел 0-1000
        A[i] = alphabet[rand() % 26]; 
    }
}

//Функція, що дозволяє користувачу ввести масив 
void InputArray(char A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int y;
    cout << "Набiр операцiй:" << endl;
    cout << "1. Рандомний рядок" << endl << "2. Ввести рядок" << endl;
    int n;
    int size, ks;

    do
    {
        cin >> n;

        if (n == 1)
        {
            cout << "Введiть довжину рядка: " << endl;
            cin >> size;
            char* arr = new char[size];

            RandArray(arr, size);
            displayArray(arr, size);

            cout << "Введiть довжину фрагменту, який бажаєте знайти:" << endl;
            cin >> ks;
            char* key = new char[ks];
            cout << "Введiть фрагмент, який бажаєте знайти:" << endl;
            InputArray(key, ks);

            bool ind = NativeTextSearch(arr,size, key, ks);
            if (!ind)
            {
                cout << "Фрагмент не знайдено" << endl;
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
            char* arr1 = new char[size];

            InputArray(arr1, size);

            cout << "Введiть довжину фрагменту, який бажаєте знайти:" << endl;
            cin >> ks;
            char* key1 = new char[ks];

            cout << "Введiть фрагмент, який бажаєте знайти:" << endl;
            InputArray(key1, ks);

            bool ind = NativeTextSearch(arr1, size, key1, ks);
            if (!ind)
            {
                cout << "Фрагмент не знайдено" << endl;
            }

            cout << "Кiлькiсть порiвнянь: " << counter_compare << endl;
            counter_compare = 0;

            cout << "Введiть 0, щоб завершити виконання програми, продовжити - 1" << endl;
            cin >> y;
        }

    } while (y != 0);

    return 0;
}