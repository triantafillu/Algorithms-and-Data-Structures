#include <iostream>
#include <map>

using namespace  std;

//��������� "�����"
struct Edge
{
public:
	int v1; //�������, � ��� ��������
	int v2; //������� � ��� �������
	int weight; //���� �������
};

//�������, �� ����� ������ ����� � ������ �������_1 �������_2 ����
void PrintEdgeList(Edge list[], int n)
{
	for (int i = 0; i < n; i++)
	{
		//��� ������� ������� ������ � ������� ���������
		if (list[i].v1 < list[i].v2)
		{
			/*+1, ������� ������� ������� � ����� �������� �� ���������� � ������ ������
			��������� ����� (���������, ������ 1 ������� �������� 0 = [0])*/
			cout << list[i].v1 + 1 << " " << list[i].v2 + 1 << " " << list[i].weight;
			cout << endl;
		}
		else
		{
			cout << list[i].v2 + 1 << " " << list[i].v1 + 1 << " " << list[i].weight;
			cout << endl;
		}
	}
}

/*�������, �� ���� �������� ����� � ��������� �����
������� ������ (�����, ������)
����� - �����, �� ������� �� MST
i����� - �������, ��� ����� ������� �� "�������"*/
tuple <Edge, int> MinEdge(Edge array[], bool U[], int E)
{
	//�������, ���� ��� ���� ������������, �� ��� ������� �������
	Edge e;
	e.weight = INT_MAX; //��� ������� ���������, ������� ����� ���� �����
	int v; //������ ������� �������

	for (int i = 0; i < E; i++)
	{
		//���� ���� � ������ �������,� ����� �, �� ���� ����� �� ���� e
		if ((U[array[i].v1] && !U[array[i].v2]) && array[i].weight < e.weight)
		{
			e = array[i]; //C�� ��������� ������
			v = array[i].v2; // ����� ������� �������
		}
		else if (U[array[i].v2] && !U[array[i].v1] && array[i].weight < e.weight)
		{
			e = array[i];
			v = array[i].v1;
		}
	}
	
	return { e, v };
}


//������� ������ MST �� ���������� �����
void Prim(Edge array[], int V, int E)
{
	//�������� �������� �����
	Edge* MST = new Edge[V - 1];

	//true - ������� �������, false - ���������
	bool* U = new bool[V];

	//³������ �� ������� ��� ����� �� ��������
	for (int i = 1; i < V; i++)
	{
		U[i] = false;
	}
	
	//����� - �������
	U[0] = true;

	cout << "����� �������� ������" << endl;
	for (int i = 0; i < V - 1; i++)
	{
		int j;
		Edge e;
		
		//������ �������� �����
		tie(e, j) = MinEdge(array, U, E);

		//������ ����� �� MST
		MST[i] = e;

		//³������ ������� �� �������
		U[j] = true;

		//��������� �������� ����������
		cout << i+1 << ")" << endl;
		cout << MST[i].v1 + 1 << " " << MST[i].v2 + 1 << " " << MST[i].weight;
		cout << endl;
	}
	cout << endl;
	cout << "MST:" << endl;
	cout << "C����� ����� (�������_1  �������_2  ����):" << endl;
	PrintEdgeList(MST, V - 1);
}

//������� ������� ����� �� ��������� ������ �����
void InputGraph(Edge input[], int n)
{
	int v1, v2, w;
	cout << "����i�� ������ ����� (�������_1  �������_2  ����):" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> v1 >> v2 >> w;

		//������� � ������� ��� �������� ������ ������� ����������� 0-V
		v1 = v1 - 1;
		v2 = v2 - 1;
		input[i].v1 = v1;
		input[i].v2 = v2;
		input[i].weight = w;
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int V, E;
	cout << "����i�� �i���i��� ������ �� �����:" << endl;
	cin >> V >> E;
	Edge* arr = new Edge[E];

	InputGraph(arr, E);

	cout << endl;

	Prim(arr, V, E);
}