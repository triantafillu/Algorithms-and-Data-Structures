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

//Префіксна функція
void PreFunc(char key[], int ks, int pref[])
{
    int length = 0; //Значенння, що буде записуватися в масив
    pref[0] = 0; //Значення на [0] завжди = 0
    int i = 1;
    while (i < ks)
    {
        //Якщо існує пркфікс==суфікс
        if (key[i] == key[length])
        {
            length++;
            pref[i] = length;
            i++;
            counter_compare++;
        }
        else
        {
            if (length != 0)
            {
                length = pref[length - 1];
            }
            //Якщо не існує - 0
            else
            {
                pref[i] = 0;
                i++;
            }
        }
    }
    

    
}

//Функція пошуку за алгоритмом КМП
void KMP(char text[], int n, char key[], int ks)
{
    //Створити масив для префіксної функції
    int *pref = new int[ks];

    //Виклик префіксної функції
    PreFunc(key, ks, pref);
    for (int i = 0; i < ks; i++)
    {
        cout << pref[i];
    }
    cout << endl;
    int i = 0, j = 0;
    bool ind;
    while (i < n)
    {
        //Якщо символ фрагмента збігається з символом текста - збільшити i та j
        if (key[j] == text[i])
        {
            i++;
            j++;
            counter_compare++;
        }
        //Якщо весь фрагмент збігається
        if (j == ks)
        {
            cout << "Фрагмент знайдено пiд iндексом " << (i - j) << endl;
            j = pref[j - 1];
            ind = true;
        }
        //Якщо фрагмент не збігається
        else if (i < n && key[j] != text[i])
        {
            //Здвинути на значення з префіксного масиву
            if (j != 0)
            {
                j = pref[j - 1];
            }
            //Якщо j==0, здвинути лише на 1
            else
            {
                i++;
            }
            ind = false;
        }
    }
    
    if (!ind)
    {
        cout << "Фрагмент не знайдено" << endl;
    }
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

            KMP(arr, size, key, ks);

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

            KMP(arr1, size, key1, ks);

            cout << "Кiлькiсть порiвнянь: " << counter_compare << endl;
            counter_compare = 0;

            cout << "Введiть 0, щоб завершити виконання програми, продовжити - 1" << endl;
            cin >> y;
        }

    } while (y != 0);

    return 0;
}