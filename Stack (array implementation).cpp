#include <iostream>

//Виділення неперервної ділянки пам'яті для стеку
#define SIZE 100 

using namespace std;

//Створення стеку фіксованого розміру SIZE
int S[SIZE]; 

//top-індекс вершини стеку, оскільки стек пустий = -1
int top = -1;

//Функція, що перевіряє стек на порожність
bool Empty()
{
	if (top == -1)
	{
        cout << "Стек пустий"<<endl;
		return true;
	}
	else
	{
        cout << "Стек має елементи" << endl;
		return false;
	}
}

//Функція, що перевіряє стек на переповнення
bool Overflow()
{
    if (top == (SIZE - 1))
    {
        cout << "Стек заповнений"<<endl;
        return true;
    }
    else
    {
        cout << "В стеку ще є мiсце" << endl;
        return false;
    }
}

//Функція, що додає елемент до стеку
void Push(int stack[], int value)
{
	if (Overflow())
	{
		cout << "Стек заповнений"<<endl;
	}
	else
	{
		top++;
		stack[top] = value;
	}
}

//Функція, що видаляє верхній елемент зі стеку та присвоює його змінній x
int Pop(int stack[])
{
    if (Empty())
    {
        cout << "Стек пустий"<<endl;
    }
    else
    {
        int x = stack[top];
        top--;
        cout << "x= " << x<<endl;
        return x;
    }
}

//Функція, що читає верхній елемент стеку без його видалення
void Top(int stack[])
{
    if (Empty())
    {
        cout << "Стек пустий"<<endl;
    }
    else
    {
        cout << "Вершина стеку: " << stack[top]<<endl;
    }
}

void Display(int stack[])
{
    
        cout << "Стек:" << endl;
        for (int i = 0; i <= top; i++)
        {
            cout << stack[i] << " ";
        }
        cout << endl;  
}

int main()
{
    setlocale(LC_ALL, "rus");
    int i = 0, a;
    string y, z; //індикатори кінця циклу
    int n;
    cout << "Набiр операцiй:" << endl;
    cout << "1. Додати елементи до масиву" << endl << "2. Видалення елемента зi стеку i присвоювання його значення змiннiй x" << endl << "3. Перевiрка стеку на порожнiсть" << endl << "4. Читання елемента без його видалення зi стеку" << endl << "5. Перевiрка переповнення стеку" << endl;
    

    do
    {
        cout << "Введiть номер операцiї: ";
        cin >> n;
        cout << endl;
        switch (n)
        {
        case 1:
            //Заповнення стеку:
            do
            {
                i++;
                cout << "Введiть " << i << " елемент стека: " << endl;
                cin >> a;
                Push(S, a);
                cout << "Введiть у (yes), якщо хочете зупинити заповнення стеку. Продовжити - n(no)" << endl;
                cin >> y;
            }
            while (y != "y");
            Display(S);
            cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
            cin >> z;
            cout << endl<<endl;
            break;

        case 2:
            Pop(S);
            Display(S);
            cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
            cin >> z;
            cout << endl<<endl;
            break;

        case 3:
            Empty();
            cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
            cin >> z;
            cout << endl<<endl;
            break;

        case 4:
            Top(S);
            cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
            cin >> z;
            cout << endl<<endl;
            break;

        case 5:
            Overflow();
            cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
            cin >> z;
            cout << endl<<endl;
            break;

        default:
            cout << "Невизначена операцiя"<<endl;
            cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
            cin >> z;
            cout << endl<<endl;
            break;
        }
    } while (z != "y");
    return 0;
}




