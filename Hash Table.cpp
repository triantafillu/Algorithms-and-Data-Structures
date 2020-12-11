#include <iostream>
#include <cmath>
using namespace std;

//����, �� ����� ������ ������
class Item
{
public:
	//���������� ���� �������
	double x;
	double y;

	//������ ����������
	double p;
	double f;
	
	//��� � ��
	double angle;

	//�����������
	Item(int x, int y)
	{
		this->x = x;
		this->y = y;
		this->angle = Angle(x,y);
		this->p = polarP(x, y);
		this->f = polarF(x, y);
	}

	//�����, �� ���� ��� � �� (� ��������)
	double Angle(int x, int y)
	{
		double vectorLength = sqrt(x * x + y * y);
		double yLength = abs(y);
		double angle = (acos(yLength / vectorLength)*180)/3.14;
		return angle;
	}

	//�����, �� ���� ������� ���������� �
	double polarP(int x, int y)
	{
		double p = sqrt(x * x + y * y);
		return p;
	}

	//�����, �� ���� ������� ���������� f
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

	//�����, �� �������� �������
	void displayObject(int x, int y)
	{
		Item* temp = new Item(x, y);
		cout << "x = " << temp->x << endl;
		cout << "y = " << temp->y << endl;
		cout << "��� � �� = " << temp->angle << endl;
		cout << "p = " << temp->p << endl;
		cout << "f = " << temp->f << endl;
	}

};

//����, �� ����� ���-�������
class HashTable
{
private:
	//������������ ����� �������
	int maxSize;
	//�������� ����� �������
	int currSize;
	Item** arr;

public:

	//�����������
	HashTable(int s)
	{
		maxSize = s;
		currSize = 0;
		
		//��������� ������
		arr = new Item* [maxSize]; 

		//��������� �������� ������
		for (int i = 0; i < maxSize; i++)
		{
			arr[i] = NULL;
		}

	}

	//����� ��� ��������� �� ������ ��������
	int Hash1(int angle)
	{
		int index = angle % maxSize;
		return index;
	}

	//����� ��� ��������� �� ������ ��������
	int Hash2(int angle)
	{
		int prime = 8;
		int index = prime - angle % prime;
		return index;
	}

	//�����, �� �������� ����� �� ������������
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

	//�����, �� ���� ������� �� �������
	void insertItem(int x, int y)
	{
		//���� ��� ������� ���������
		if (isFull())
		{
			return;
		}
		Item* temp = new Item(x, y);
		
		//������������ ������� �� ������ ��������
		int ind1 = Hash1(temp->angle);

		//� ��� ����糿
		if (arr[ind1] != NULL)
		{
			//������������ ������� �� ������ ��������
			int ind2 = Hash2(temp->angle);
			int i = 1;
			while (true)
			{
				//������� ���������
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
		
		//���� ����糿 �� ����������
		else
		{
			arr[ind1] = temp;
		}

		currSize++;
	}
	
	/*�����, �� ���� ������� � �������
	void searchItem(int x, int y)
	{
		int count=0;
		for (int i = 0; i < currSize; i++)
		{
			if ((arr[i]->x = x) && (arr[i]->y = y))
			{
				cout << "������ � ������������ (" << x << "," << y << ") ����������� �i� i������� " << i << endl;
				count++;
			}
		}
		if (count == 0)
		{
			cout << "������� �� ��������" << endl;
		}
	}*/

	//�����, �� �������� ���-������� �� �������
	void Display()
	{
		for (int i = 0; i < maxSize; i++)
		{
			if (arr[i] != NULL)
			{
				cout <<endl<< "[" << i << "]" << endl;
				cout << "x = " << arr[i]->x << endl;
				cout << "y = " << arr[i]->y << endl;
				cout << "��� � �� = " << arr[i]->angle << endl;
				cout << "p = " << arr[i]->p << endl;
				if (arr[i]->f != NULL)
				{
					cout << "f = " << arr[i]->f << endl;
				}
				else
				{
					cout << "f �� i���"<<endl;
				}
			}	
		}
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	int i = 0, a, x,y;
	string p, z; //���������� ���� �����
	int n;
	cout << "����i�� ����i� ���-������i:" << endl;
	cin >> a;
	HashTable* ht = new HashTable(a);
	cout << "���i� ������i�:" << endl;
	cout << "1. �������� ���-������� " << endl << "2. ������ �������� �� ���-������i" << endl << "3. ������� ���-�������" << endl;

	do
	{
		cout << "����i�� ����� ������i�: ";
		cin >> n;
		cout << endl;
		switch (n)
		{
		case 1:
			cout << "���-������� ��������" << endl;
			break;

		case 2:
			do
			{
				i++;
				cout << "����i�� ���������� �i��� �������: " << endl<<"x = ";
				cin >> x;
				cout<< "y = ";
				cin >> y;
				ht->insertItem(x, y);
				cout <<"����i�� � (yes), ���� ������ �������� ����������. ���������� - n(no)" << endl;
				cin >> p;
				
			} while (p != "y");
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		/*case 3:
			cout << "����i�� ���������� �i��� �������: " << endl << "x = ";
			cin >> x;
			cout << "y = ";
			cin >> y;
			ht->searchItem(x, y);
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;*/

		case 3:
			ht->Display();
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		default:
			cout << "����������� ������i�" << endl;
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;
		}
	} while (z != "y");

	return 0;
}
