#include <iostream>
#define SIZE 5 //фіксований розмір черги

using namespace std;

class Queue
{
	//Ініціалізація:
private:
	int front; //індекс першого елемента
	int rear; //індекс останнього елемента
	int arr[SIZE]; 

public:
	//Конструктор для екземплярів класу Queue:
	Queue()
	{
		front = -1;
		rear = -1;
		for (int i = 0; i < SIZE; i++)
		{
			arr[i] = 0;
		}
	}

	//Функція, що перевіряє стек на порожність
	bool Empty1()//Для перевірки всередині інших функцій
	{
		if (front == -1 && rear == -1)
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
		if (front == -1 && rear == -1)
		{
			cout << "Черга пуста" << endl;
		}
		else
		{
			cout << "В черзi є елементи" << endl;
		}
	}

	//Функція, що перевіряє стек на переповнення
	bool Overflow1()//Для перевірки всередині інших функцій
	{
		if (rear == (SIZE - 1))
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
		if (rear == (SIZE - 1))
		{
			cout << "Черга заповнена" << endl;
		}
		else
		{
			cout << "В черзi є мiсце" << endl;
		}
	}

	//Функція, що додає елемент до черги
	void Insert(int value)
	{
		if (Overflow1())
		{
			cout << "Черга заповнена" << endl;
		}
		else if (Empty1())
		{
			rear = 0;
			front = 0;
			arr[rear] = value;
		}
		else
		{
			rear++;
			arr[rear] = value;
		}
	}

	//Функція, що видаляє верхній елемент зі стеку та присвоює його змінній x
	int Remove()
	{
		int x;
		if (Empty1())
		{
			cout << "Черга пуста" << endl;
		}
		else if (front == rear)
		{
			x = arr[front];
			arr[front] = 0;
			rear = -1;
			front = -1;
			cout << "x = " << x << endl;
			return x;
		}
		else
		{
			x = arr[front];
			arr[front] = 0;
			front++;
			cout << "x = " << x << endl;
			return x;
		}
	}
	void Display()
	{
		cout << "Черга:" << endl;
		for (int i = 0; i < SIZE; i++)
		{
			cout << arr[i] << " ";
		}
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
			Q.Display();
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 2:
			Q.Remove();
			Q.Display();
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