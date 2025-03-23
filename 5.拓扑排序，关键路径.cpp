//#include <stdio.h>
//#include <stdlib.h>
//
//typedef int VertextType;
//typedef int EdgeType;
//
//#define MAXSIZE 100
//�ڽӾ���
//typedef struct
//{
//	VertextType vertex[MAXSIZE];//������
//	EdgeType arc[MAXSIZE][MAXSIZE];//��ά����
//	int vertex_num;//��������
//	int edge_num;//������
//}Mat_Graph;
//��ʾ�ڽӱ�
//��ʾ�ߵĽṹ��
//typedef struct EdgeNode
//{
//	int edge_vex;//��ʾ������±꣬V0�±��ʾΪ0
//	struct EdgeNode* next;//����ļ�ͷ
//}EdgeNode;
//��ﶥ��Ľṹ��
//typedef struct VertextNode
//{
//	int in;//��ʾ����������Ϊ��
//	VertextType data;//��ﶥ��Ԫ��
//	EdgeNode* head;//���������ȥ�ļ�ͷ
//}VertextNode;
//
//typedef VertextNode Adj_List[MAXSIZE];//adjacency�����ڽ�
//��������ڽӱ�
//typedef struct
//{
//	Adj_List adj_list;
//	int vertex_num;//��������
//	int edge_num;//������
//}Adj_Graph;
//
//typedef Adj_Graph* Adj_List_Graph;
//
//int top = -1;//��ʼ��top��ջ��ָ��
//int stack[MAXSIZE];//ջ����
//��ջ����
//void push(int e)
//{
//	if (top > MAXSIZE)
//	{
//		printf("����\n");
//		return;
//	}
//
//	top++;
//	stack[top] = e;
//}
//��ջ����
//int pop()
//{
//	if (top == -1)
//	{//���ж��Ƿ�Ϊ��
//		printf("�յ�\n");
//		return 0;
//	}
//
//	int elem = stack[top];
//	top--;
//	return elem;
//}
//�ж�ջ�Ƿ�Ϊ��
//int is_empty()
//{
//	if (top == -1)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}
//��ͼ����
//void create_graph(Mat_Graph* G)
//{
//	G->vertex_num = 14;//��������
//	G->edge_num = 20;//������
//
//	for (int i = 0; i < G->vertex_num; i++)
//	{
//		G->vertex[i] = i;//��ÿһ�����㶼ֱ��������0��1��2����ʾ
//	}
//
//	for (int i = 0; i < G->vertex_num; i++)
//	{
//		for (int j = 0; j < G->vertex_num; j++)
//		{
//			G->arc[i][j] = 0;//��ʼ��ÿһ��Ԫ�ض���0
//		}
//	}
//	�������ӵ��������㸳ֵ1����ʾ������
//	G->arc[0][4] = 1;
//	G->arc[0][5] = 1;
//	G->arc[0][11] = 1;
//	G->arc[1][2] = 1;
//	G->arc[1][4] = 1;
//	G->arc[1][8] = 1;
//	G->arc[2][5] = 1;
//	G->arc[2][6] = 1;
//	G->arc[2][9] = 1;
//	G->arc[3][2] = 1;
//	G->arc[3][13] = 1;
//	G->arc[4][7] = 1;
//	G->arc[5][8] = 1;
//	G->arc[5][12] = 1;
//	G->arc[6][5] = 1;
//	G->arc[8][7] = 1;
//	G->arc[9][10] = 1;
//	G->arc[9][11] = 1;
//	G->arc[10][13] = 1;
//	G->arc[12][9] = 1;
//}
//
//void create_adj_graph(Mat_Graph G, Adj_List_Graph* ALG)//�ڽӾ��󴫽���ת�����ڽӱ�
//{
//	EdgeNode* e;
//
//	*ALG = (Adj_List_Graph)malloc(sizeof(Adj_Graph));//���ٿռ����ڽӱ�
//	(*ALG)->vertex_num = G.vertex_num;//���ڽӾ����еĶ��㸳ֵ���ڽӱ���
//	(*ALG)->edge_num = G.edge_num;//���ڽӾ����еı߸�ֵ���ڽӱ���
//
//	���ڽӱ�����ʼ��
//	for (int i = 0; i < G.vertex_num; i++)
//	{
//		(*ALG)->adj_list[i].in = 0;//���ȫ��Ϊ0
//		(*ALG)->adj_list[i].data = G.vertex[i];//ÿ������Ԫ��ȫ�����ɣ�0��1���������ַ����ʾ
//		(*ALG)->adj_list[i].head = NULL;//ָ��ȫ��ָ��գ���ʱ��������һ�����㣩
//	}
//
//	for (int i = 0; i < G.vertex_num; i++)
//	{
//		for (int j = 0; j < G.vertex_num; j++)
//		{
//			if (G.arc[i][j] == 1)//�����������֮��������
//			{
//				e = (EdgeNode*)malloc(sizeof(EdgeNode));//���ڴ��п��ٿռ�
//				e->edge_vex = j;//�����Ӷ��㸳ֵ��ȥ
//				ͷ�巨
//				e->next = (*ALG)->adj_list[i].head;
//				(*ALG)->adj_list[i].head = e;
//				(*ALG)->adj_list[j].in++;//��ʱ�����ӵĶ�����ȼ�һ
//			}
//		}
//	}
//}
//����������
//void topological_sort(Adj_List_Graph ALG)
//{
//	EdgeNode* e;
//	int curr;
//	int k;
//
//	for (int i = 0; i < ALG->vertex_num; i++)
//	{
//		if (ALG->adj_list[i].in == 0)//���Ϊ0
//		{
//			push(i);//ֱ����ջ
//		}
//	}
//
//	while (is_empty() != 0)
//	{
//		curr = pop();//��ջ����curr�н�
//		printf("V%d -> ", ALG->adj_list[curr].data);//�����ʱ�Ķ���
//		e = ALG->adj_list[curr].head;//���������ӵ�һ�������e
//
//		while (e != NULL)
//		{
//			k = e->edge_vex;//�ٸ�ֵ��k
//			ALG->adj_list[k].in--;//�ٽ����������ȼ�1
//			if (ALG->adj_list[k].in == 0)//�����ʱ����������Ϊ0
//			{
//				push(k);//������ջ
//			}
//			e = e->next;//�ٽ�����������һ�����㸳ֵ��e����ȥ�жϺ��涥�����������ֱ���������ӵĶ���Ϊ��
//		}
//	}
//}
//
//int main(int argc, char const* argv[])
//{
//	Mat_Graph G;//�ڽӾ���ṹ�����
//	Adj_List_Graph ALG;//�ڽӱ�ָ��ı���
//	create_graph(&G);//���ڽӾ���
//	create_adj_graph(G, &ALG);//�ڽӾ���ת�����ڽӱ�
//	topological_sort(ALG);//��������
//	return 0;
//}


#include <stdio.h>
#include <stdlib.h>

typedef int VertextType;
typedef int EdgeType;

#define MAXSIZE 100
#define MAX 0x7fffffff
//�ڽӾ���
typedef struct
{
	VertextType vertex[MAXSIZE];
	EdgeType arc[MAXSIZE][MAXSIZE];
	int vertex_num;
	int edge_num;
}Mat_Graph;

typedef struct EdgeNode
{
	int edge_vex;
	int weight;//��ʾȨ��
	struct EdgeNode* next;
}EdgeNode;

typedef struct VertextNode
{
	int in;
	VertextType data;
	EdgeNode* head;
}VertextNode;

typedef VertextNode Adj_List[MAXSIZE];
//�ڽӱ�
typedef struct
{
	Adj_List adj_list;
	int vertex_num;
	int edge_num;
}Adj_Graph;

typedef Adj_Graph* Adj_List_Graph;

//���ڽӾ���
void create_graph(Mat_Graph* G)
{
	G->vertex_num = 10;
	G->edge_num = 13;
	//��ÿһ�����㸳ֵΪ��Ӧ������
	for (int i = 0; i < G->vertex_num; i++)
	{
		G->vertex[i] = i;
	}

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (i == j)
			{//�Խ���Ԫ��Ϊ0
				G->arc[i][j] = 0;
			}
			else
			{//����ȫ��Ϊ����
				G->arc[i][j] = MAX;
			}
		}
	}
	//�������ӵ��������㸳ֵ
	G->arc[0][1] = 3;
	G->arc[0][2] = 4;
	G->arc[1][3] = 5;
	G->arc[1][4] = 6;
	G->arc[2][3] = 8;
	G->arc[2][5] = 7;
	G->arc[3][4] = 3;
	G->arc[4][6] = 9;
	G->arc[4][7] = 4;
	G->arc[5][7] = 6;
	G->arc[6][9] = 2;
	G->arc[7][8] = 5;
	G->arc[8][9] = 3;

}
//�ڽӾ���ת�ڽӱ�
void create_adj_graph(Mat_Graph G, Adj_List_Graph* ALG)
{
	EdgeNode* e;

	*ALG = (Adj_List_Graph)malloc(sizeof(Adj_Graph));
	(*ALG)->vertex_num = G.vertex_num;
	(*ALG)->edge_num = G.edge_num;

	for (int i = 0; i < G.vertex_num; i++)
	{
		(*ALG)->adj_list[i].in = 0;
		(*ALG)->adj_list[i].data = G.vertex[i];
		(*ALG)->adj_list[i].head = NULL;
	}

	for (int i = 0; i < G.vertex_num; i++)
	{
		for (int j = 0; j < G.vertex_num; j++)
		{
			if (G.arc[i][j] != 0 && G.arc[i][j] < MAX)
			{
				e = (EdgeNode*)malloc(sizeof(EdgeNode));
				e->edge_vex = j;
				e->weight = G.arc[i][j];
				e->next = (*ALG)->adj_list[i].head;
				(*ALG)->adj_list[i].head = e;
				(*ALG)->adj_list[j].in++;
			}
		}
	}
}
//�ؼ�·������
void critical_path(Adj_List_Graph ALG)
{
	EdgeNode* e;
	int top = -1;
	int top2 = -1;
	//����ջ
	int stack[MAXSIZE];//��һ��ջ������ʾ�������µ�˳���൱��������ʱ��
	int stack2[MAXSIZE];//�ڶ���ջ���������൱��������ʾ��������ʱ��
	int etv[MAXSIZE];
	int ltv[MAXSIZE];
	int curr;//�����ջ����
	int k;//���±���
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		if (ALG->adj_list[i].in == 0)
		{
			top++;
			stack[top] = i;
		}
	}
	//��ʼ�����緢��ʱ�������
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		etv[i] = 0;
	}
	//��һ��ջ
	while (top != -1)
	{
		curr = stack[top];
		top--;
		printf("V%d -> ", ALG->adj_list[curr].data);
		//��ջ���ٰ��������ѹ�뵽��һ��ջ��ȥ
		top2++;
		stack2[top2] = curr;

		e = ALG->adj_list[curr].head;

		while (e != NULL)
		{
			k = e->edge_vex;
			ALG->adj_list[k].in--;
			if (ALG->adj_list[k].in == 0)
			{
				top++;
				stack[top] = k;
			}

			if (etv[curr] + e->weight > etv[k])
			{//ȡ���ֵ���ж����緢��ʱ��
				etv[k] = etv[curr] + e->weight;
			}
			e = e->next;
		}
	}
	printf("End\n");
	//���etv����
	printf("etv: ");
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		printf("%d -> ", etv[i]);
	}
	printf("End\n");
	//Ĭ��ltv��ʼ��ȫ���������һ��ֵ
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		ltv[i] = etv[ALG->vertex_num - 1];
	}
	//�ڶ���ջ
	while (top2 != -1)
	{
		curr = stack2[top2];
		top2--;

		e = ALG->adj_list[curr].head;
		while (e != NULL)
		{
			k = e->edge_vex;

			if (ltv[k] - e->weight < ltv[curr])
			{//����Сֵ
				ltv[curr] = ltv[k] - e->weight;
			}
			e = e->next;
		}
	}

	printf("ltv: ");
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		printf("%d -> ", ltv[i]);
	}
	printf("End\n");

	for (int i = 0; i < ALG->vertex_num; ++i)
	{//�������etv����ltv��=�ٽ�����������
		if (etv[i] == ltv[i])
		{
			printf("V%d -> ", i);
		}
	}


}

int main(int argc, char const* argv[])
{
	Mat_Graph G;
	Adj_List_Graph ALG;
	create_graph(&G);
	create_adj_graph(G, &ALG);
	critical_path(ALG);
	return 0;
}