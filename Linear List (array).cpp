#include <iostream>
//Գ�������� ����� ������
#define SIZE 10

using namespace std;

class List
{
private:
	int length; //ʳ������ �������� ������
	int arr[SIZE]; //�����, � ����� ���� ���������� ������

//��������, � ����� �����䳺 ����������:
public:
	//�����������, �� ������� ������:
	List() 
	{
		length = 0; //��������� ������� ������
	}

	//�������, �� �������� ������ �� �������
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

	//�������, �� �������� ������ �� ������������
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

	//�������, �� �������� ������� � ����� ������
	void Insert(int el) //el-element
	{
		if (Overflow())
		{
			cout << "������ ����������" << endl;
		}
		else
		{
			arr[length] = el; // ��������� ��������� �������� ����������� �������� ������
			length++; //��������� ������ �� 1
		}
	}

	//�������, �� �������� ������� �� ������� �������
	void Insert_ind(int el, int pos) //el-element
	{
		if (Overflow())
		{
			cout << "������ ����������" << endl;
		}
		else
		{
			if (pos <= length)
			{
				//��������� ���� ��� ��������
				for (int i = length; i > (pos - 1); i--)
				{
					arr[i] = arr[i - 1];
				}
				arr[pos-1] = el;
				length++;
			}
			else
			{
				cout << "������ �����i� ���� � ������" << endl;
			} 
		}
	}

	//�������, �� �������� ������
	void ToEmpty()
	{
		length = 0;
		cout << "������ ������";
	}

	//�������, �� ������� �������
	int Delete(int el)
	{
		int count = 0;
		if (IfEmpty())
		{
			cout << "������ ������" << endl;
		}
		else
		{
			for (int i = 0; i < length; i++)
			{
				if (arr[i] == el)//����� ��������
				{
					for (int j = i; j < (length - 1); j++)//����� ������ ����
					{
						arr[j] = arr[j + 1];
					}
					count++;
					break;
				}
			}
			length=length-1; //��������� ������� ������ ��� �������� ���������� ��������
			if (count == 0)
			{
				cout << "������� �� ��������";
			}
			else
			{
				//���������:
				cout << "����� ������ :\n";
				for (int i = 0; i < length; i++)
				{
					cout << arr[i] << " ";
				}
				cout<<endl;
			}
		}
		return length;
	}
	
	//�������, �� �������� ������ �� �����
	void Display()
	{
		cout << "������:" << endl;
		for (int i = 0; i < length; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	//�������, �� ����� ������ �� ����������
	int Sort()
	{
		//���������� ����������
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

	//�������, �� ���� ������� � ������
	void FindEl(int el)
	{
		for (int i=0; i<length; i++)
			if (arr[i] == el)
			{
				cout << "������� '" << el << "' - �� ������� ����� " << i + 1 << endl;
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

	cout << "���i� ������i�:" << endl;
	cout << "1. ������ �������� �� ������" << endl << "2. ������ ������� �� ������ �����i�"<<endl<<"3. �������� ������� �i ������" << endl << "4. ����������� ��������" << endl << "5. ��������� ������ �� �����" << endl  << "6. ���������� ������" << endl<< "7. ����������� ������"<<endl;

	do
	{
		cout << "����i�� ����� ������i�: ";
		cin >> n;
		cout << endl;
		switch (n)
		{
		case 1:
			cout << "����i� ������: " << SIZE << endl;
			do
			{
				i++;
				cout << "����i�� " << i << " ������� ������: " << endl;
				cin >> a;
				L.Insert(a);
				cout << "����i�� � (yes), ���� ������ �������� ���������� ������. ���������� - n(no)" << endl;
				cin >> y;
			} while (y != "y");
			L.Display();
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 2:
			cout << "����i�� ������� ������: " << endl;
			cin >> a;
			cout << "����i�� �����i�: " << endl;
			cin >> pos;
			L.Insert_ind(a, pos);
			L.Display();
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;
		case 3:
			cout << "����i�� ������� ������, ���� ������ ��������:  " << endl;
			cin >> a;
			L.Delete(a);
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 4:
			cout << "����i�� ������� ������, ���� ������ ������:  " << endl;
			cin >> a;
			L.FindEl(a);
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 5:
			L.Display();
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 6:
			L.Sort();
			L.Display();
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 7:
			L.ToEmpty();
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