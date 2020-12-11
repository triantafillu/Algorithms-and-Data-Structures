#include <iostream>
//�������� ���������� ������ ���'�� ��� �����
#define SIZE 100 

using namespace std;

int k = 0;//�������� ������� �������� �����

//���������, �� ������� ����� ����� �����
struct Node
{
	int num;
	Node* link;
};
Node* top = NULL;

//�������, �� �������� ���� �� ���������
bool Empty1() //��� �������� �������� ����� �������
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

bool Empty2() //��� ����������� �������
{
	if (top == NULL)
	{
		cout << "���� ������" << endl;
		return true;
	}
	else
	{
		cout << "���� �� ��������" << endl;
		return false;
	}
}

//�������, �� ���� ������� �� �����
void Push(int value)
{
	k++; //���� ������� �������� �����
	if (k <= SIZE)
	{
		Node* new_el = new Node();
		new_el->num = value;
		new_el->link = top;
		top = new_el;
	}
	
}

//�������, �� �������� ���� �� ������������
bool Overflow()
{
	if (k == (SIZE - 1))
	{
		cout << "���� ����������" << endl;
		return true;
	}
	else
	{
		cout << "� ����� �� � �i���" << endl;
		return false;
	}
}

//�������, �� ������� ������ ������� � ����� �� �������� ���� ����� x
void Pop()
{
	if (Empty1())
	{
		cout << "���� ������" << endl;
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
 
//�������, �� ���� ������ ������� ����� ��� ���� ���������
void Top()
{
	if (Empty1())
	{
		cout << "���� ������" << endl;
	}
	else
	{
		cout << "������� �����: " << top->num<<endl;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	int i = 0, a;
	string y, z; //���������� ���� �����
	int n;
	cout << "���i� ������i�:" << endl;
	cout << "1. ������ �������� �� ������" << endl << "2. ��������� �������� �i ����� i ������������ ���� �������� ��i��i� x" << endl << "3. �����i��� ����� �� ������i���" << endl << "4. ������� �������� ��� ���� ��������� �i �����" << endl << "5. �����i��� ������������ �����" << endl;


	do
	{
		cout << "����i�� ����� ������i�: ";
		cin >> n;
		cout << endl;
		switch (n)
		{
		case 1:
			//���������� �����:
			do
			{
				i++;
				cout << "����i�� " << i << " ������� �����: " << endl;
				cin >> a;
				Push(a);
				cout << "����i�� � (yes), ���� ������ �������� ���������� �����. ���������� - n(no)" << endl;
				cin >> y;
			} while (y != "y");
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 2:
			Pop();
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 3:
			Empty2();
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 4:
			Top();
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 5:
			Overflow();
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





