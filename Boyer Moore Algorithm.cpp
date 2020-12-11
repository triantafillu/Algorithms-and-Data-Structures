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

//Функція обчислення таблиці зсувів
void PreFunc(char key[], int ks, int table[])
{
    //Заповнити усі входження як -1 (тобто не входить)
    for (int i = 0; i < 256; i++)
    {
        table[i] = -1;
    }
    //Заповнити значення за таблицею кодів ASCII
    for (int i = 0; i < ks; i++)
    {
        table[char(key[i])] = i;
    }
}

//Функція пошуку за алгоритмом БМ
void BM(char text[], int n, char key[], int ks)
{
    //Створити масив для функції заповнення таблиці
    int table[256];

    //Заповнити таблицю
    PreFunc(key, ks, table);
    int shift = 0; //Значення здвигу по масиву з текстом
    bool ind=false;

    //При закінченні здвинеться на кінець масиву
    while (shift <= (n-ks))
    {
        int j = ks - 1; //Оскільки останній індекс буде на 1 менше кількості елементів

        //Проходження по масиву з текстом зліва направо перевіряючи фрагмент справа наліво
        while (key[j] == text[shift + j] && j >= 0)
        {
            j--;
            counter_compare++;
        }

        //Якщо фрагмент буде знайдено повністю, то j стане менше 0
        if (j < 0)
        {
            cout << "Фрагмент знайдено пiд iндексом " << shift << endl;
            ind = true;

            //Якщо здвиг закінчує масив, додати масив, щоб вийти з циклу
            if ((shift + ks) < n)
            {
                //Звинути так, щоб наступний елемент в масиві з текстом збігався з останнім його входженням у фрагмент
                shift += ks - table[text[shift + ks]];
            }
            else
            {
                shift += 1;
            }
        }
        else
        {
            //Якщо здвиг закінчує масив, додати масив, щоб вийти з циклу
            if (j - table[key[shift + j]] > 0)
            {
                //Звинути так, щоб наступний елемент в масиві з текстом збігався з останнім його входженням у фрагмент
                shift += j - table[text[shift + j]];
            }
            else
            {
                shift += 1;
            }
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

            BM(arr, size, key, ks);

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

            BM(arr1, size, key1, ks);

            cout << "Кiлькiсть порiвнянь: " << counter_compare << endl;
            counter_compare = 0;

            cout << "Введiть 0, щоб завершити виконання програми, продовжити - 1" << endl;
            cin >> y;
        }

    } while (y != 0);

    return 0;
}