#include <iostream>
#define SIZE 5 //���������� ����� �����

using namespace std;

class Queue
{
	//�����������:
private:
	int front; //������ ������� ��������
	int rear; //������ ���������� ��������
	int arr[SIZE]; 

public:
	//����������� ��� ���������� ����� Queue:
	Queue()
	{
		front = -1;
		rear = -1;
		for (int i = 0; i < SIZE; i++)
		{
			arr[i] = 0;
		}
	}

	//�������, �� �������� ���� �� ���������
	bool Empty1()//��� �������� �������� ����� �������
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

	void Empty2()//��� ����������� �������
	{
		if (front == -1 && rear == -1)
		{
			cout << "����� �����" << endl;
		}
		else
		{
			cout << "� ����i � ��������" << endl;
		}
	}

	//�������, �� �������� ���� �� ������������
	bool Overflow1()//��� �������� �������� ����� �������
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

	void Overflow2()//��� ����������� �������
	{
		if (rear == (SIZE - 1))
		{
			cout << "����� ���������" << endl;
		}
		else
		{
			cout << "� ����i � �i���" << endl;
		}
	}

	//�������, �� ���� ������� �� �����
	void Insert(int value)
	{
		if (Overflow1())
		{
			cout << "����� ���������" << endl;
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

	//�������, �� ������� ������ ������� � ����� �� �������� ���� ����� x
	int Remove()
	{
		int x;
		if (Empty1())
		{
			cout << "����� �����" << endl;
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
		cout << "�����:" << endl;
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

	cout << "���i� ������i�:" << endl;
	cout << "1. ������ �������� �� �����" << endl << "2. ��������� �������� � ����� i ������������ ���� �������� ��i��i� x" << endl << "3. �����i��� ����� �� ������i���" << endl << "4. �����i��� ������������ �����" << endl;

	do
	{
		cout << "����i�� ����� ������i�: ";
		cin >> n;
		cout << endl;
		switch (n)
		{
		case 1:
			cout << "����i� �����: " << SIZE << endl;
			do
			{
				i++;
				cout << "����i�� " << i << " ������� �����: " << endl;
				cin >> a;
				Q.Insert(a);
				cout << "����i�� � (yes), ���� ������ �������� ���������� �����. ���������� - n(no)" << endl;
				cin >> y;
			} while (y != "y");
			Q.Display();
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 2:
			Q.Remove();
			Q.Display();
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 3:
			Q.Empty2();
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 4:
			Q.Overflow2();
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