#include <iostream>
#include <algorithm>

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
			cout << list[i].v2 + 1 << " " << list[i].v1 +1<< " " << list[i].weight;
			cout << endl;
		}
	}
}

/*�������� ������� ������� ���� ����� 
�� �� �����, �� � ���������� ���������������
��� ���������� ������ �����*/
bool CompareWeights(Edge a, Edge b)
{
	if (b.weight > a.weight)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//�������, �� �������� �� ������� ����� ����
bool IfCycle(int v1, int v2, int graph[])
{
	//���� ������� �������� �� ���� ����� (��������� ����), ��������� true

	//������� ���� ����� ����� ������� �������

	//������, �� ��� ����� �������� �������
	while (graph[v1] != v1)
	{
		v1 = graph[v1];
	}
	while (graph[v2] != v2)
	{
		v2 = graph[v2];
	}

	//���� ����� ���
	if (v1 != v2)
	{
		graph[v1] = v2;
		return false;
	}
	//���� ���� �����
	else
	{
		return true;
	}
}

int Find(int v, int graph[])
{
	if (graph[v] == v)
	{
		return v;
	}
	else
	{
		return Find(graph[v], graph);
	}
}

//������� ������ MST �� ���������� ��������
void Kruskal(Edge array[], int V, int E)
{
	//³���������� ����� �� �����
	sort(array, array + E, CompareWeights);

	/*�������� �����, �� ���������� ��������� �����, 
	���� ���� ������ ���������� ��� �����*/
	int* graph = new int[V];
	for (int i = 0; i < V; i++)
	{
		graph[i] = i;
	}

	//�������� �������� �����
	Edge* MST = new Edge[V - 1];

	//���� ������� �����, ������� � �������� �����
	int c = 0;

	int i = 0;
	cout << "����� �������� ������" << endl;
	while (c != (V - 1))
	{
		Edge e = array[i];

		//int vertex1 = Find(e.v1, graph);
		//int vertex2 = Find(e.v2, graph);
		//���� �� ������� ����
		if (!IfCycle(e.v1, e.v2, graph))
		//if (vertex1!=vertex2)
		{
			//��'������ ����� � ���� �����
			//graph[vertex1] = vertex2;

			//������ ����� � �������� �����
			MST[c] = e;
			c++;

			//��������� �������� ����������
			cout << c << ")" << endl;
			cout << e.v1 + 1 << " " << e.v2 + 1 << " " << e.weight;
			cout << endl;
		}
		i++;
	}
	cout << "MST:" << endl;
	cout << "C����� ����� (�������_1  �������_2  ����):" << endl;

	//����������� ���������
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

	Kruskal(arr, V, E);
}