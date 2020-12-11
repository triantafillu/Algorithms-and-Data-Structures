#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

//������� � ����� ������� root - �� �������� ������, �� root - �� �������� �������

//�������, �� �������� ������ �� ���������
bool ifEmpty1(Node* root)//��� ������������ �������� ����� �������
{
	if (root == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ifEmpty2(Node* root)//��� ����������� ������������
{
	if (root == NULL)
	{
		cout << "������ �����" << endl;
	}
	else
	{
		cout << "������ �� ��������" << endl;
	}
}

//�������, �� �������� ������� � ������
Node* insertNode(Node*root, int info)
{
	//���� ������ ����� (���� �����), �� ���������� ������� ��� ������
	if (root == NULL)
	{ 
		root->data = info;
		root->left = NULL;
		root->right = NULL;
	}

	//���� ����� ����� ����� �����, �� ������� �� ���� �����
	else if (info <= root->data)
	{
		root->left = insertNode(root->left, info);
	}

	//���� ����� ����� ����� �����, �� ������� �� ������ �����
	else
	{
		root->right = insertNode(root->right, info);
	}
	return root;
}

//�������, �� ���� ��������� ������� ������
Node* minNode(Node* root)
{
	Node* el = new Node();
	if (ifEmpty1(root))
	{
		cout << "������ �����" << endl;
		return NULL;
	}
	while (root->left != NULL)
	{
		root = root->left;
	}
	el->data = root->data;
	return el;
}

//�������, �� ������� ������� � ������
Node* deleteNode(Node* root, int info)
{
	//���� � ����� ���� �����
	if (ifEmpty1(root))
	{
		cout << "������ �����" << endl;
		return root;
	}

	//����� �������� �� ��������� ������:

	//���� ����� � ��� ����:
	else if (info < root->data)
	{
		root->left = deleteNode(root->left, info);
	}

	//���� ����� � ����� ����:
	else if (info > root->data)
	{
		root->right = deleteNode(root->right, info);
	}

	//���� ������� ��������:
	else
	{
		//���� ������� - ������:
		if (root->left == NULL && root->right == NULL)
		{
			delete root; //��������� �����
			root = NULL; //������� root ��� �� �� ������
			return root; 
		}

		//���� ������� �� 1 ������:

		//������ (���� = NULL):
		else if (root->left == NULL)
		{
			Node* temp = root; //���������� ����� �� ���������� ����������� �����
			root = root->right; //���������� ������� ����� ������
			delete temp; //��������� �����
			return root;
		}

		//���� (������ = NULL):
		else if (root->right == NULL)
		{
			Node* temp = root; //���������� ����� �� ���������� ����������� �����
			root = root->left; //���������� ����� ����� ������
			delete temp; //��������� �����
			return root;
		}

		//���� ������� �� 2 ������:
		else
		{
			Node* temp = minNode(root->right); //����� ���������� �������� � ����� ���� ������
			root->data = temp->data; //���������� ���������� �������� �� ���� ����������� ��������
			root->right = deleteNode(root->right, temp->data);
			return root;
		}
	}
}

//�������, �� ���� ������� � ����� �� �������� ���� �������� ����� var
void findNode(Node* root, int info)
{
	int x;
	if (ifEmpty1(root))
	{
		cout << "������ �����" << endl;
	}

	//���� ������� �������� ������� ���������� ��������:
	else if (root->data == info)
	{
		cout << "������� ��������" << endl;
		x = root->data;
		cout << "x = " << x << endl;
	}

	//����������� ����� �� ���� �����
	else if (info <= root->data)
	{
		findNode(root->left, info);
	}

	//����������� ����� �� ������ �����
	else
	{
		findNode(root->right, info);
	}
}

//�������, �� ������� ������
void deleteTree(Node* root)
{
	if (ifEmpty1(root))
	{
		cout << "������ �����  " << endl;
	}
	else
	{
		deleteTree(root->left);
		deleteTree(root->right);
		delete (root);
		cout << "������ ��������" << endl;
	}
}

//�������, �� ����� ������
Node*copyTree(Node* root)
{
	if (ifEmpty1(root))
	{
		cout << "������ �����" << endl;
		return NULL;
	}
	else
	{
		Node* newNode = new Node();
		newNode->data = root->data;
		newNode->left = copyTree(root->left);
		newNode->right = copyTree(root->right);
		cout << "������ ����i������" << endl;
		return newNode;
	}
}
 
//�������, �� �������� �� �������� ������ �� ����� � ������� ���������
void displayTree(Node* root)
{
	if (ifEmpty1(root))
	{
		cout << "������ �����" << endl;
	}
	else
	{
		//���� � ������ �������, �� �������� (����� ������� ����)
		if (root->left != NULL)
		{
			displayTree(root->left);
		}
		cout << root->data << " ";
		if (root->right != NULL)
		{
			displayTree(root->right);
		}
	}
}

//����� � ������: root - left - right
void Preorder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data <<endl;
	Preorder(root->left);
	Preorder(root->right);
}

//����������� �����: left - root - right
void Inorder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	Inorder(root->left);
	cout << root->data <<endl;
	Inorder(root->right);
}

//����� � �������: left - right - root
void Postorder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	Postorder(root->left);
	Postorder(root->right);
	cout << root->data << endl;
}


int main()
{
	setlocale(LC_ALL, "rus");
	int i = 0, a, x;
	string y, z; //���������� ���� �����
	int n;
	Node* root = NULL;
	cout << "���i� ������i�:" << endl;
	cout << "1. �������� �i����� ������ " << endl << "2. ������ �������� �� �i������� ������" << endl << "3. �����i��� �i������� ������ �� ������i���" << endl << "4. ��������� �������� � �i������� ������" << endl << "5. ��������� ������" << endl<<"6. ����������� �� ����������� �����"<<endl<<"7. ����i����� ������"<<endl<<"8. ������� �� ������� ��i �������� ������"<<endl<<"9. ����������� ���i�"<<endl<<"10. ���i� � ������ "<<endl<<"11. ���i� � ������� "<<endl;

	do
	{
		cout << "����i�� ����� ������i�: ";
		cin >> n;
		cout << endl;
		switch (n)
		{
		case 1:
			cout << "�i����� ������ ��������" << endl;
			break;

		case 2:
			do
			{
				i++;
				cout << "����i�� ������� " << endl;
				cin >> a;
				root = insertNode(root,a);
				cout << "����i�� � (yes), ���� ������ �������� ���������� �����. ���������� - n(no)" << endl;
				cin >> y;
			} while (y != "y");
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 4:
			cout << "����i�� ������� " << endl;
			cin >> a;
			deleteNode(root,a);
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 3:
			ifEmpty2(root);
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 5:
			deleteTree(root);
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 6:
			cout << "����i�� ������� " << endl;
			cin >> a;
			findNode(root, a);
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 7:
			copyTree(root);
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 8:
			cout << "�������� ������:" << endl;
			displayTree(root);
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 9:
			cout << "����������� ���i�:"<< endl;
			Inorder(root);
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 10:
			cout << "���i� � ������:"<< endl;
			Preorder(root);
			cout << "����i�� � (yes), ���� ������ �������� ��������. ���������� - n(no)" << endl;
			cin >> z;
			cout << endl << endl;
			break;

		case 11:
			cout << "���i� � ������� " << endl;
			Postorder(root);
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