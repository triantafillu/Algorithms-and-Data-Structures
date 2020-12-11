#include <iostream>
#define SIZE 10
using namespace std;

int k = 0;

//��������� ������ ����� �����
struct Node 
{
    int data;
    Node*link;

    //�������, �� ������� ����� �����
    Node(int num)
    {
        data = num; //num ��� ��������� �����
        link = NULL; //������� ���� ������� ����������� ��������
    }
};

//��������� �����
struct Queue 
{
    Node* front, * rear;

    //�������, �� ������� ���� �����
    Queue()
    {
        front = rear = NULL; //�� ���� ��������, ���� null
    }

	bool Empty1()//��� �������� �������� ����� �������
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

	void Empty2()//��� ����������� �������
	{
		if (front == NULL)
		{
			cout << "����� �����" << endl;
		}
		else
		{
			cout << "� ����i � ��������" << endl;
		}
	}

	//�������, �� �������� ����� �� ������������
	bool Overflow1()//��� �������� �������� ����� �������
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

	void Overflow2()//��� ����������� �������
	{
		if (k == (SIZE - 1))
		{
			cout << "����� ���������" << endl;
		}
		else
		{
			cout << "� ����i � �i���" << endl;
		}
	}

	//�������, �� ���� ������� �� �����
    void Insert(int x)
    {
		k++; //���� ������� �������� �����
		if (k <= SIZE)
		{
			Node* new_el = new Node(x); //��������� ������ �����
			if (rear == NULL)
			{
				front = rear = new_el;
			}
			rear->link = new_el;
			rear = new_el;
		}
    }

	//�������, �� ������� ������ ������� � ����� �� �������� ���� ����� x
    int Remove()
    {
        if (Empty1())
        {
            cout << "����� �����" << endl;
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
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 2:
			Q.Remove();
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