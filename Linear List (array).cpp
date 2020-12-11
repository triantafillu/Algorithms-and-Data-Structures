#include <iostream>
//Фіксований розмір списку
#define SIZE 10

using namespace std;

class List
{
private:
	int length; //Кількість елементів списку
	int arr[SIZE]; //Масив, в якому буде зберігатись список

//Елементи, з якими взаємодіє користувач:
public:
	//Конструктор, що створює список:
	List() 
	{
		length = 0; //Початкова довжина списку
	}

	//Функція, що перевіряє список на пустоту
	bool IfEmpty()
	{
		if (length == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//Функція, що перевіряє список на переповнення
	bool Overflow()
	{
		if (length == (SIZE - 1))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//Функція, що вставляє елемент в кінець списку
	void Insert(int el) //el-element
	{
		if (Overflow())
		{
			cout << "Список заповнений" << endl;
		}
		else
		{
			arr[length] = el; // Присвоєння введеного значення оостанньому елементу списка
			length++; //Збільшення списку на 1
		}
	}

	//Функція, що вставляю елемент на введену позицію
	void Insert_ind(int el, int pos) //el-element
	{
		if (Overflow())
		{
			cout << "Список заповнений" << endl;
		}
		else
		{
			if (pos <= length)
			{
				//Звільнення місця для елемента
				for (int i = length; i > (pos - 1); i--)
				{
					arr[i] = arr[i - 1];
				}
				arr[pos-1] = el;
				length++;
			}
			else
			{
				cout << "Заданої позицiї немає в списку" << endl;
			} 
		}
	}

	//Функція, що спустошує список
	void ToEmpty()
	{
		length = 0;
		cout << "Список пустий";
	}

	//Функція, що видаляє елемент
	int Delete(int el)
	{
		int count = 0;
		if (IfEmpty())
		{
			cout << "Список пустий" << endl;
		}
		else
		{
			for (int i = 0; i < length; i++)
			{
				if (arr[i] == el)//Пошук елемента
				{
					for (int j = i; j < (length - 1); j++)//Здвиг масива вліво
					{
						arr[j] = arr[j + 1];
					}
					count++;
					break;
				}
			}
			length=length-1; //Зменшення довжини масиву щоб уникнути повторення елементів
			if (count == 0)
			{
				cout << "Елемент не знайдено";
			}
			else
			{
				//Виведення:
				cout << "Новий список :\n";
				for (int i = 0; i < length; i++)
				{
					cout << arr[i] << " ";
				}
				cout<<endl;
			}
		}
		return length;
	}
	
	//Функція, що виводить список на екран
	void Display()
	{
		cout << "Список:" << endl;
		for (int i = 0; i < length; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	//Функція, що сортує список за зростанням
	int Sort()
	{
		//Сортування бульбашкою
		int temp;
		for (int i = 0; i < (length - 1); i++)
		{
			for (int j = 0; j < (length - i - 1); j++)
			{
				if (arr[j] > arr[j + 1])
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		return arr[length];
	}

	//Функція, що шукає елемент в списку
	void FindEl(int el)
	{
		for (int i=0; i<length; i++)
			if (arr[i] == el)
			{
				cout << "Елемент '" << el << "' - це елемент номер " << i + 1 << endl;
			}
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	List L;
	int n;
	int i = 0, a,pos;
	string y, z;

	cout << "Набiр операцiй:" << endl;
	cout << "1. Додати елементи до списку" << endl << "2. Додати елемент на задану позицiю"<<endl<<"3. Видалити елемент зi списку" << endl << "4. Знаходження елементу" << endl << "5. Виведення списку на екран" << endl  << "6. Сортування списку" << endl<< "7. Спустошення списку"<<endl;

	do
	{
		cout << "Введiть номер операцiї: ";
		cin >> n;
		cout << endl;
		switch (n)
		{
		case 1:
			cout << "Розмiр списку: " << SIZE << endl;
			do
			{
				i++;
				cout << "Введiть " << i << " елемент списку: " << endl;
				cin >> a;
				L.Insert(a);
				cout << "Введiть у (yes), якщо хочете зупинити заповнення списку. Продовжити - n(no)" << endl;
				cin >> y;
			} while (y != "y");
			L.Display();
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 2:
			cout << "Введiть елемент списку: " << endl;
			cin >> a;
			cout << "Введiть позицiю: " << endl;
			cin >> pos;
			L.Insert_ind(a, pos);
			L.Display();
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;
		case 3:
			cout << "Введiть елемент списку, який хочете видалити:  " << endl;
			cin >> a;
			L.Delete(a);
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 4:
			cout << "Введiть елемент списку, який хочете знайти:  " << endl;
			cin >> a;
			L.FindEl(a);
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 5:
			L.Display();
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 6:
			L.Sort();
			L.Display();
			cout << "Введiть у (yes), якщо хочете зупинити програму. Продовжити - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 7:
			L.ToEmpty();
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