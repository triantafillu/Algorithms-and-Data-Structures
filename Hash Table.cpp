#include <iostream>
#include <cmath>
using namespace std;

//Клас, що описує фігуру вектор
class Item
{
public:
	//Координати кінця вектора
	double x;
	double y;

	//Полярні координати
	double p;
	double f;
	
	//Кут з ОУ
	double angle;

	//Конструктор
	Item(int x, int y)
	{
		this->x = x;
		this->y = y;
		this->angle = Angle(x,y);
		this->p = polarP(x, y);
		this->f = polarF(x, y);
	}

	//Метод, що рахує кут з ОУ (в градусах)
	double Angle(int x, int y)
	{
		double vectorLength = sqrt(x * x + y * y);
		double yLength = abs(y);
		double angle = (acos(yLength / vectorLength)*180)/3.14;
		return angle;
	}

	//Метод, що рахує полярну координату р
	double polarP(int x, int y)
	{
		double p = sqrt(x * x + y * y);
		return p;
	}

	//Метод, що рахує полярну координату f
	double polarF(int x, int y)
	{
		double f;
		if (x != 0)
		{
			f = atan(y / x);
		}
		else
		{
			f = NULL;
		}
		return f;
	}

	//Метод, що виводить елемент
	void displayObject(int x, int y)
	{
		Item* temp = new Item(x, y);
		cout << "x = " << temp->x << endl;
		cout << "y = " << temp->y << endl;
		cout << "кут з ОУ = " << temp->angle << endl;
		cout << "p = " << temp->p << endl;
		cout << "f = " << temp->f << endl;
	}

};

//Клас, що описує хеш-таблицю
class HashTable
{
private:
	//Максимальний розмір таблиці
	int maxSize;
	//Поточний розмір таблиці
	int currSize;
	Item** arr;

public:

	//Конструктор
	HashTable(int s)
	{
		maxSize = s;
		currSize = 0;
		
		//Створення масиву
		arr = new Item* [maxSize]; 

		//Створення елементів масиву
		for (int i = 0; i < maxSize; i++)
		{
			arr[i] = NULL;
		}

	}

	//Метод для хешування за першою формулою
	int Hash1(int angle)
	{
		int index = angle % maxSize;
		return index;
	}

	//Метод для хешування за другою формулою
	int Hash2(int angle)
	{
		int prime = 8;
		int index = prime - angle % prime;
		return index;
	}

	//Метод, що перевіряє масив на переповнення
	bool isFull()
	{
		if (currSize == maxSize)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//Метод, що додає елемент до таблиці
	void insertItem(int x, int y)
	{
		//Якщо хеш таблиця заповнена
		if (isFull())
		{
			return;
		}
		Item* temp = new Item(x, y);
		
		//Розрахування індекса за першою формулою
		int ind1 = Hash1(temp->angle);

		//В разі коллізії
		if (arr[ind1] != NULL)
		{
			//Розрахування індекса за другою формулою
			int ind2 = Hash2(temp->angle);
			int i = 1;
			while (true)
			{
				//Подвійне хешування
				int newIndex = (ind1 + i * ind2) % maxSize;
				if (arr[newIndex] == NULL)
				{
					arr[newIndex] = temp;
					break;
				}
				else
				{
					i++;
				}
			}
			
		}
		
		//Якщо коллізії не відбувається
		else
		{
			arr[ind1] = temp;
		}

		currSize++;
	}
	
	/*Метод, що шукає елемент в таблиці
	void searchItem(int x, int y)
	{
		int count=0;
		for (int i = 0; i < currSize; i++)
		{
			if ((arr[i]->x = x) && (arr[i]->y = y))
			{
				cout << "Вектор з координатами (" << x << "," << y << ") знаходиться пiд iндексом " << i << endl;
				count++;
			}
		}
		if (count == 0)
		{
			cout << "Елемент не знайдено" << endl;
		}
	}*/

	//Метод, що виводить хеш-таблицю на консоль
	void Display()
	{
		for (int i = 0; i < maxSize; i++)
		{
			if (arr[i] != NULL)
			{
				cout <<endl<< "[" << i << "]" << endl;
				cout << "x = " << arr[i]->x << endl;
				cout << "y = " << arr[i]->y << endl;
				cout << "кут з ОУ = " << arr[i]->angle << endl;
				cout << "p = " << arr[i]->p << endl;
				if (arr[i]->f != NULL)
				{
					cout << "f = " << arr[i]->f << endl;
				}
				else
				{
					cout << "f не iснує"<<endl;
				}
			}	
		}
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	int i = 0, a, x,y;
	string p, z; //індикатори кінця циклу
	int n;
	cout << "Введiть розмiр хеш-таблицi:" << endl;
	cin >> a;
	HashTable* ht = new HashTable(a);
	cout << "Набiр операцiй:" << endl;
	cout << "1. Створити хеш-таблицю " << endl << "2. Додати елементи до хеш-таблицi" << endl << "3. Вивести хеш-таблицю" << endl;

	do
	{
		cout << "Введiть номер операцiї: ";
		cin >> n;
		cout << endl;
		switch (n)
		{
		case 1:
			cout << "Хеш-таблиця створена" << endl;
			break;

		case 2:
			do
			{
				i++;
				cout << "Введiть координати кiнця вектора: " << endl<<"x = ";
				cin >> x;
				cout<< "y = ";
				cin >> y;
				ht->insertItem(x, y);
				cout <<"Введiть у (yes), якщо хочете зупинити заповнення. Продовжити - n(no)" << endl;
				cin >> p;
				
			} while (p != "y");
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		/*case 3:
			cout << "Введiть координати кiнця вектора: " << endl << "x = ";
			cin >> x;
			cout << "y = ";
			cin >> y;
			ht->searchItem(x, y);
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;*/

		case 3:
			ht->Display();
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
