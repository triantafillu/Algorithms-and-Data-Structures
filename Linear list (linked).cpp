#include <iostream>
using namespace std;

//����� ������
struct Node
{
    int data;
    Node* link;
};

Node* head = NULL;

//�������, �� �������� ������ �� �������
bool IfEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//�������, �� �������� ������
void ToEmpty()
{
    head = NULL;
    cout << "������ ������" << endl;
}

//�������, �� �������� ������� � ������� ������
void Insert_beg(int el)
{
    Node* ptr = new Node();
    ptr->data = el;
    ptr->link = head;
    head = ptr;
}

//�������, �� �������� ������� � ����� ������
void Insert_end(int el)
{
    Node* ptr = new Node();
    ptr->data = el;
    ptr->link = NULL;
    if (IfEmpty())
    {
        head = ptr;
    }
    else
    {
        Node* temp = head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = ptr;
    }
}

//�������, �� �������� ������� �� ������� �������
void Insert_ind(int el, int pos)
{
    Node* element = new Node;
    element->data = el;
    element->link = NULL;
    Node* curr = head;
    if (pos == 1)
    {
        element->link = head;
        head = element;
    }
    else
    {
        for (int i = 1; i < (pos - 1); i++)
        {
            if ((curr != NULL) && (curr->link != NULL))
            {
                curr = curr->link;
            }
        }
        if ((curr != NULL) && (curr->link != NULL))
        {
            element->link = curr->link;
            curr->link = element;
        }
        else
        {
            cout << "��������� �������� �������" << endl;
        }
    }
}

//�������, �� ������� ������� � ���� ������
void Delete_end()
{
    Node* ptr = new Node();
    Node* prev = new Node();

    if (IfEmpty())
    {
        cout << "������ ������" << endl;
    }
    else if (head->link == NULL)//���� ���� ����� � ������
    {
        ptr = head;
        head = NULL;
        free(ptr);
    }
    else
    {
        ptr = head;
        while (ptr->link != NULL)
        {
            prev = ptr;
            ptr = ptr->link;
        }
        prev->link = NULL;
        free(ptr);
    }
}

//�������, �� ������� ������� �� �������� ��������
void Delete_ind(int pos)
{
    if (IfEmpty())
    {
        cout << "������ ������" << endl;
    }
    else
    {
        Node* curr = head;
        for (int i = 1; i < pos; i++)
        {
            if (curr != NULL)
            {
                curr = curr->link;
            }
        }
        if (curr != NULL)
        {
            if (curr == head)
            {
                head = head->link;
                delete(curr);
                curr = head;
            }
            else
            {
                Node* tmp = head;
                while (tmp->link != curr)
                {
                    tmp = tmp->link;
                }
                tmp->link = curr->link;
                delete(curr);
                curr = tmp;
            }
        }

    }  
}

//�������, �� ���� ������� � ������
string FindEl(int el)
{
    Node* tmp = head;
    while (tmp != NULL)
    {
        if (el = tmp->data)
        {
            return "������� ��������\n";
            break;
        }
        else
        {
            tmp = tmp->link;
        }
    }
    return "E������ �� ��������\n";
}
 
//�������� ������� ��� ���������� ������� �������� � ������
int Length()
{
    int length = 0;
    Node*tmp = head;
    while (tmp != NULL)
    {
        length++;
        tmp = tmp->link;
    }
    return length;
}

//�������, �� ����� ������
void Sort()
{
    int length, l, ptr;
    Node*tmp = head;
    length = Length();
    l = length;
    for (int i = 0; i < (length - 1); i++)
    {
        for (int j = 0; j < (l - 1); j++)
        {
            if (tmp->data > tmp->link->data)
            {
                ptr = tmp->data;
                tmp->data = tmp->link->data;
                tmp->link->data = ptr;
            }
            tmp = tmp->link;
        }
        l--;
        tmp = head;
    } 
}

//�������, �� �������� ������ �� �����
void Display()
{
    Node*tmp = head;
    cout << "C�����: "<<endl;
    while (tmp!= NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->link;
    }
    cout << endl;
}


int main()
{
    setlocale(LC_ALL, "rus");
    int n;
    int i = 0, a, pos;
    string y, z;

    cout << "���i� ������i�:" << endl;
    cout << "1. ������ ������� � �i���� ������" << endl << "2. ������ ������� � ������� ������ "<< endl << "3. ������ ������� �� ������ �����i�"<< endl<< "4. �������� ������� � �i��� ������" << endl << "5. �������� ������� �� ���� ��������"<<endl<<"6. ����������� ��������" << endl << "7. ��������� ������ �� �����" << endl <<"8. ���������� ������"<<endl<< "9. ����������� ������" << endl;

    do
    {
        cout << "����i�� ����� ������i�: ";
        cin >> n;
        cout << endl;
        switch (n)
        {
        case 1:
            do
            {
                i++;
                cout << "����i�� " << i << " ������� ������: " << endl;
                cin >> a;
                Insert_end(a);
                cout << "����i�� � (yes), ���� ������ �������� ���������� ������. ���������� - n(no)" << endl;
                cin >> y;
            } while (y != "y");
            Display();
            cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
            cin >> z;
            cout << endl << endl;
            break;

        case 2:
            do
            {
                cout << "����i�� ������� ������: " << endl;
                cin >> a;
                Insert_beg(a);
                cout << "����i�� � (yes), ���� ������ �������� ���������� ������. ���������� - n(no)" << endl;
                cin >> y;
            } while (y != "y");
            Display();
            cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
            cin >> z;
            cout << endl << endl;
            break;

        case 3:
            cout << "����i�� ������� ������: " << endl;
            cin >> a;
            cout << "����i�� �����i�: " << endl;
            cin >> pos;
            Insert_ind(a, pos);
            Display();
            cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
            cin >> z;
            cout << endl << endl;
            break;

        case 4:
            Delete_end();
            Display();
            cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
            cin >> z;
            cout << endl << endl;
            break;

        case 5:
            cout << "����i�� �����i�: " << endl;
            cin >> pos;
            Delete_ind(pos);
            Display();
            cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
            cin >> z;
            cout << endl << endl;
            break;

        case 6:
            cout << "����i�� ������� ������: " << endl;
            cin >> a;
            cout<< FindEl(a)<<endl;
            cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
            cin >> z;
            cout << endl << endl;
            break;

        case 7:
            Display();
            cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
            cin >> z;
            cout << endl << endl;
            break;

        case 8:
            Sort();
            Display();
            cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
            cin >> z;
            cout << endl << endl;
            break;

        case 9:
            ToEmpty();
            cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
            cin >> z;
            cout << endl << endl;

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