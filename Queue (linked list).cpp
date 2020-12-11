#include <iostream>
#define SIZE 10
using namespace std;

int k = 0;

//Структура нового вузла черги
struct Node 
{
    int data;
    Node*link;

    //Функція, що створює новий вузол
    Node(int num)
    {
        data = num; //num стає значенняя вузла
        link = NULL; //оскільки немає потреби обновлювати вказівник
    }
};

//Структура черги
struct Queue 
{
    Node* front, * rear;

    //Функція, що створює нову чергу
    Queue()
    {
        front = rear = NULL; //ще немає елементів, тому null
    }

	bool Empty1()//Для перевірки всередині інших функцій
	{
		if (front == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Empty2()//Для консольного виклику
	{
		if (front == NULL)
		{
			cout << "Черга пуста" << endl;
		}
		else
		{
			cout << "В черзi є елементи" << endl;
		}
	}

	//Функція, що перевіряє чергу на переповнення
	bool Overflow1()//Для перевірки всередині інших функцій
	{
		if (k == (SIZE - 1))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Overflow2()//Для консольного виклику
	{
		if (k == (SIZE - 1))
		{
			cout << "Черга заповнена" << endl;
		}
		else
		{
			cout << "В черзi є мiсце" << endl;
		}
	}

	//Функція, що додає елемент до черги
    void Insert(int x)
    {
		k++; //рахує кількість елементів стеку
		if (k <= SIZE)
		{
			Node* new_el = new Node(x); //створення нового вузла
			if (rear == NULL)
			{
				front = rear = new_el;
			}
			rear->link = new_el;
			rear = new_el;
		}
    }

	//Функція, що видаляє верхній елемент зі стеку та присвоює його змінній x
    int Remove()
    {
        if (Empty1())
        {
            cout << "Черга пуста" << endl;
        }
        Node* last_el = front;
        int x = front->data;
		cout << "x = " << x << endl;
        front = front->link;
        if (front == NULL)
        {
            rear = NULL;
        }
		
        delete (last_el);
        return x;
    }
};

int main()
{
	setlocale(LC_ALL, "rus");
	Queue Q;
	int n;
	int i = 0, a;
	string y, z;

	cout << "Набiр операцiй:" << endl;
	cout << "1. Додати елементи до черги" << endl << "2. Видалення елемента з черги i присвоювання його значення змiннiй x" << endl << "3. Перевiрка черги на порожнiсть" << endl << "4. Перевiрка переповнення черги" << endl;

	do
	{
		cout << "Введiть номер операцiї: ";
		cin >> n;
		cout << endl;
		switch (n)
		{
		case 1:
			cout << "Розмiр черги: " << SIZE << endl;
			do
			{
				i++;
				cout << "Введiть " << i << " елемент черги: " << endl;
				cin >> a;
				Q.Insert(a);
				cout << "Введiть у (yes), якщо хочете зупинити заповнення черги. Продовжити - n(no)" << endl;
				cin >> y;
			} while (y != "y");
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 2:
			Q.Remove();
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 3:
			Q.Empty2();
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 4:
			Q.Overflow2();
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