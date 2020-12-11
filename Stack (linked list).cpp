#include <iostream>
//Виділення неперервної ділянки пам'яті для стеку
#define SIZE 100 

using namespace std;

int k = 0;//лічильник кількості елементів стеку

//Структура, що створює новий вузол стеку
struct Node
{
	int num;
	Node* link;
};
Node* top = NULL;

//Функція, що перевіряє стек на порожність
bool Empty1() //Для перевірки всередині інших функцій
{
	if (top == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Empty2() //Для консольного виклику
{
	if (top == NULL)
	{
		cout << "Стек пустий" << endl;
		return true;
	}
	else
	{
		cout << "Стек має елементи" << endl;
		return false;
	}
}

//Функція, що додає елемент до стеку
void Push(int value)
{
	k++; //рахує кількість елементів стеку
	if (k <= SIZE)
	{
		Node* new_el = new Node();
		new_el->num = value;
		new_el->link = top;
		top = new_el;
	}
	
}

//Функція, що перевіряє стек на переповнення
bool Overflow()
{
	if (k == (SIZE - 1))
	{
		cout << "Стек заповнений" << endl;
		return true;
	}
	else
	{
		cout << "В стеку ще є мiсце" << endl;
		return false;
	}
}

//Функція, що видаляє верхній елемент зі стеку та присвоює його змінній x
void Pop()
{
	if (Empty1())
	{
		cout << "Стек пустий" << endl;
	}
	else
	{
		Node* new_el = top;
		int x = top->num;
		cout << "x= " << x << endl;
		top = top->link;
		delete(new_el);
	}
}
 
//Функція, що читає верхній елемент стеку без його видалення
void Top()
{
	if (Empty1())
	{
		cout << "Стек пустий" << endl;
	}
	else
	{
		cout << "Вершина стеку: " << top->num<<endl;
	}
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
				Push(a);
				cout << "Введiть у (yes), якщо хочете зупинити заповнення стеку. Продовжити - n(no)" << endl;
				cin >> y;
			} while (y != "y");
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 2:
			Pop();
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 3:
			Empty2();
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 4:
			Top();
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 5:
			Overflow();
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		default:
			cout << "Невизначена операцiя" << endl;
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;
		}
	} while (z != "y");
	return 0;
}





