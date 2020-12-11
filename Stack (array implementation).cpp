#include <iostream>

//�������� ���������� ������ ���'�� ��� �����
#define SIZE 100 

using namespace std;

//��������� ����� ����������� ������ SIZE
int S[SIZE]; 

//top-������ ������� �����, ������� ���� ������ = -1
int top = -1;

//�������, �� �������� ���� �� ���������
bool Empty()
{
	if (top == -1)
	{
        cout << "���� ������"<<endl;
		return true;
	}
	else
	{
        cout << "���� �� ��������" << endl;
		return false;
	}
}

//�������, �� �������� ���� �� ������������
bool Overflow()
{
    if (top == (SIZE - 1))
    {
        cout << "���� ����������"<<endl;
        return true;
    }
    else
    {
        cout << "� ����� �� � �i���" << endl;
        return false;
    }
}

//�������, �� ���� ������� �� �����
void Push(int stack[], int value)
{
	if (Overflow())
	{
		cout << "���� ����������"<<endl;
	}
	else
	{
		top++;
		stack[top] = value;
	}
}

//�������, �� ������� ������ ������� � ����� �� �������� ���� ����� x
int Pop(int stack[])
{
    if (Empty())
    {
        cout << "���� ������"<<endl;
    }
    else
    {
        int x = stack[top];
        top--;
        cout << "x= " << x<<endl;
        return x;
    }
}

//�������, �� ���� ������ ������� ����� ��� ���� ���������
void Top(int stack[])
{
    if (Empty())
    {
        cout << "���� ������"<<endl;
    }
    else
    {
        cout << "������� �����: " << stack[top]<<endl;
    }
}

void Display(int stack[])
{
    
        cout << "����:" << endl;
        for (int i = 0; i <= top; i++)
        {
            cout << stack[i] << " ";
        }
        cout << endl;  
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
                Push(S, a);
                cout << "����i�� � (yes), ���� ������ �������� ���������� �����. ���������� - n(no)" << endl;
                cin >> y;
            }
            while (y != "y");
            Display(S);
            cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
            cin >> z;
            cout << endl<<endl;
            break;

        case 2:
            Pop(S);
            Display(S);
            cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
            cin >> z;
            cout << endl<<endl;
            break;

        case 3:
            Empty();
            cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
            cin >> z;
            cout << endl<<endl;
            break;

        case 4:
            Top(S);
            cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
            cin >> z;
            cout << endl<<endl;
            break;

        case 5:
            Overflow();
            cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
            cin >> z;
            cout << endl<<endl;
            break;

        default:
            cout << "����������� ������i�"<<endl;
            cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
            cin >> z;
            cout << endl<<endl;
            break;
        }
    } while (z != "y");
    return 0;
}




