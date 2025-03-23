#include <stdio.h>
#include <stdlib.h>

typedef char VertexType;
typedef int EdgeType;

#define MAXSIZE 100
#define MAX 0x7fffffff
//��ʾ�ڽӾ���
typedef struct
{
	VertexType vertex[MAXSIZE];//��������
	EdgeType arc[MAXSIZE][MAXSIZE];//��ά����
	int vertex_num;//��������
	int edge_num;//������
}Mat_Grph;


void create_graph(Mat_Grph* G)//��ͼ����
{
	G->vertex_num = 9;
	G->edge_num = 15;
	//���θ�ÿһ�����㸳ֵ
	G->vertex[0] = 'A';
	G->vertex[1] = 'B';
	G->vertex[2] = 'C';
	G->vertex[3] = 'D';
	G->vertex[4] = 'E';
	G->vertex[5] = 'F';
	G->vertex[6] = 'G';
	G->vertex[7] = 'H';
	G->vertex[8] = 'I';
	//��ʼ������
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (i == j)
			{//�Խ���ȫ��Ϊ0����Ȩֵ���ڽӾ�������ʣ�
				G->arc[i][j] = 0;
			}
			else
			{//���ǶԽ��ߵ�ȫ�����max������
				G->arc[i][j] = MAX;
			}

		}
	}
	//�������ӵ���������֮���Ȩֵ���ھ�����
	//A-B A-F
	G->arc[0][1] = 10;
	G->arc[0][5] = 11;

	//B-C B-G B-I
	G->arc[1][2] = 18;
	G->arc[1][6] = 16;
	G->arc[1][8] = 12;

	//C-D C-I
	G->arc[2][3] = 22;
	G->arc[2][8] = 8;

	//D-E D-G D-H D-I
	G->arc[3][4] = 20;
	G->arc[3][6] = 24;
	G->arc[3][7] = 16;
	G->arc[3][8] = 21;

	//E-F E-H
	G->arc[4][5] = 26;
	G->arc[4][7] = 7;

	//F-G
	G->arc[5][6] = 17;

	//G-H
	G->arc[6][7] = 19;
	//���öԳƣ���������Ҳ������
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

void prim(Mat_Grph* G)
{
	int i, j, k;
	int min;//�����Сֵ
	int weight[MAXSIZE];//��Ŵ�ѡ��Ȩֵ
	int vex_index[MAXSIZE];//ֵ��ʾ�����㣬�±��ʾ����㣬���ֵΪ1���±�Ϊ0����ô��ʾ��B���㵽A����

	//�ȴӶ���A��ʼ
	weight[0] = 0; //vex_indexĳ�����±��Ӧ���Ȩ��
	vex_index[0] = 0;//A������A��������
	//��1��ʼѭ������0��λ���Ѿ���ֵΪ0��
	for (i = 1; i < G->vertex_num; i++)
	{
		weight[i] = G->arc[0][i];//��weight������г�ʼ������Ϊһ��ʼ��A������Ȩֵ��С�Ķ��㣬���Դ������д����A������ص�����·��Ȩֵ
		vex_index[i] = 0;//����0��ʼ���ӣ�Ҳ����A����
	}

	for (int i = 1; i < G->vertex_num; i++)
	{
		min = MAX;
		j = 0;
		k = 0;
		//�ҵ���С�ģ���֮����
		while (j < G->vertex_num)//j��0�䵽8
		{
			if (weight[j] != 0 && weight[j] < min)
			{//�Ҿ���A���������Ȩֵ
				min = weight[j];//���Ҹ�ֵ��min��
				k = j;//�ҵ�������С���Ǹ����㣬���Ҽ�¼����
			}
			j++;
		}

		//printf("(%d, %d)\n", vex_index[k], k);//�������0��1��
		printf("(%c, %c)\n", G->vertex[vex_index[k]], G->vertex[k]);//�������A,B��
		weight[k] = 0;//B���㱻�ҵ���AB֮���·���Ͳ�����ѡ�ˣ���ʱ������B�����ֵΪ0����ʾ��·������������

		//�������ӽ��Ĵ�ѡ·��
		for (j = 0; j < G->vertex_num; j++)
		{
			//���½������ӵı߽��бȽϣ��б�weightС�ľ��滻
			if (weight[j] != 0 && G->arc[k][j] < weight[j])
			{
				weight[j] = G->arc[k][j];//��ȨֵС�ı߸�ֵ��weight�����ڣ���ʾ���ŵ���ѡ����
				vex_index[j] = k;//��ʱ����k��������Ķ�����j,��ô�ڴ������У���ʾk��������������
			}
		}

	}
}

int main(int argc, char const* argv[])
{
	//Mat_Grph* G = (Mat_Grph*)malloc(sizeof(Mat_Grph));
	Mat_Grph G;
	//��ͼ
	create_graph(&G);
	//���ú���
	prim(&G);
	return 0;
}





#include <stdio.h>
#include <stdlib.h>

typedef char VertexType;
typedef int EdgeType;

#define MAXSIZE 100
#define MAXEDGE 200
#define MAX 0x7fffffff
//�ڽӾ���
typedef struct
{
	VertexType vertex[MAXSIZE];//��������
	EdgeType arc[MAXSIZE][MAXSIZE];//��ά����
	int vertex_num;//��������
	int edge_num;//������
}Mat_Grph;
//�߽ṹ��
typedef struct
{
	int begin;//��ʼ����
	int end;//��������(����ͼ��
	int weight;//��ʾȨֵ
}Edge;

//��ͼ����
void create_graph(Mat_Grph* G)
{
	//9�����㣬15����
	G->vertex_num = 9;
	G->edge_num = 15;
	//���θ������ÿһ��Ԫ�ظ��϶�Ӧ�Ķ���
	G->vertex[0] = 'A';
	G->vertex[1] = 'B';
	G->vertex[2] = 'C';
	G->vertex[3] = 'D';
	G->vertex[4] = 'E';
	G->vertex[5] = 'F';
	G->vertex[6] = 'G';
	G->vertex[7] = 'H';
	G->vertex[8] = 'I';
	//ÿ��ÿ�У�˫��ѭ��ȥ��ֵ
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (i == j)
			{//�Խ���Ԫ�ظ�ֵΪ0
				G->arc[i][j] = 0;
			}
			else
			{//���ǶԽ��ߵ�Ԫ�س�ʼ��ȫ����ֵΪ��
				G->arc[i][j] = MAX;
			}

		}
	}
	//���ݶ���֮�������ȥ����Ȩֵ
	//A-B A-F
	G->arc[0][1] = 10;
	G->arc[0][5] = 11;

	//B-C B-G B-I
	G->arc[1][2] = 18;
	G->arc[1][6] = 16;
	G->arc[1][8] = 12;

	//C-D C-I
	G->arc[2][3] = 22;
	G->arc[2][8] = 8;

	//D-E D-G D-H D-I
	G->arc[3][4] = 20;
	G->arc[3][6] = 24;
	G->arc[3][7] = 16;
	G->arc[3][8] = 21;

	//E-F E-H
	G->arc[4][5] = 26;
	G->arc[4][7] = 7;

	//F-G
	G->arc[5][6] = 17;

	//G-H
	G->arc[6][7] = 19;
	//�Գ�ԭ�򣬸��������Ǹ�ֵ������
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

void swap(Edge* edges, int i, int j)
{//�ֱ��ÿһ��������һ������
	int temp;//�м����
	//��ʼ���㽻��
	temp = edges[i].begin;
	edges[i].begin = edges[j].begin;
	edges[j].begin = temp;
	//�������㽻��
	temp = edges[i].end;
	edges[i].end = edges[j].end;
	edges[j].end = temp;
	//Ȩֵ����
	temp = edges[i].weight;
	edges[i].weight = edges[j].weight;
	edges[j].weight = temp;
}
//�����㷨��Ȩֵ��һ������
void sortEdges(Edge edges[], int edge_num)//��������飬������
{
	for (int i = 0; i < edge_num; i++)
	{
		for (int j = i + 1; j < edge_num; j++)
		{
			if (edges[i].weight > edges[j].weight)
			{
				swap(edges, i, j);//���н���
			}
		}
	}
}
//Ϊ��ȷ���ó����Ķ���������ʹ��������֮������
int find(int* parent, int index)
{
	while (parent[index] > 0)
	{
		index = parent[index];
	}
	return index;
}

void Kruskal(Mat_Grph G)//ֱ�Ӱ�ͼ������
{
	Edge edges[MAXEDGE];//15����Ҫ��������
	int k = 0;//�����±�ʹ�ã�һ��ʼ���ҵ�һ����С�ı�

	for (int i = 0; i < G.vertex_num; i++)
	{
		for (int j = i + 1; j < G.vertex_num; j++)
		{//����С��Ȩֵ
			if (G.arc[i][j] < MAX)
			{
				edges[k].begin = i;//�ҵ����i��ֵ����ʼ����
				edges[k].end = j;//j��ֵ����������
				edges[k].weight = G.arc[i][j];//�Ѷ�Ӧ����СȨֵ����weight��
				k++;//�����ҵڶ��飬�����顣�ظ�
			}
		}
	}

	sortEdges(edges, G.edge_num);//��ʱ�������Ѿ����ź�����

	int parent[MAXSIZE];//�±��ֵ�ֱ��ʾ�������㣬��������ʾ����������֮������
	//��ʼ��������飬ÿ��Ԫ�ض�Ϊ0
	for (int i = 0; i < G.vertex_num; i++)
	{
		parent[i] = 0;
	}

	int n, m;
	for (int i = 0; i < G.edge_num; i++)
	{
		n = find(parent, edges[i].begin);//4
		m = find(parent, edges[i].end);//7

		if (n != m)
		{
			parent[n] = m;//������������������������ʾ����Ȩֵ��С�ı�
			//printf("(%d, %d) %d\n", edges[i].beigin, edges[i].end, edges[i].weight);//�������
			printf("(%c, %c) %d\n", G.vertex[edges[i].begin], G.vertex[edges[i].end], edges[i].weight);//���ֵ��±꣬�����Ӧ�Ķ���
		}
	}
}

int main(int argc, char const* argv[])
{
	//��ͼ
	Mat_Grph G;
	create_graph(&G);
	//���ú���
	Kruskal(G);
	return 0;
}