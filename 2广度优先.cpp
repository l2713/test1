#include<stdio.h>
typedef char vertextype;//���������������char
typedef int edgetype;//�ߵ�����������int
#define maxsize 100
 //��ʾ�ڽӾ���
typedef struct
{
	vertextype vertex[maxsize];//������Ŷ��������
	edgetype arc[maxsize][maxsize];//��ʾ��ά����
	int vertex_num;//���������
	int edge_num;//�ߵ�����
}mat_grph;
int visited[maxsize];//������ʾ�����Ƿ񱻷��ʹ���0��ʾû�б����ʣ�1��ʾ�Ѿ���������
int front = 0;//��ͷ
int rear = 0;//��β
int queue[maxsize];//����
void create_graph(mat_grph* g)//��ͼ����
{
	g->vertex_num = 9;//��������Ϊ9��
	g->edge_num = 15;//������Ϊ15��
	//���ζ�ÿһ�����������Ӧ���ַ�
	g->vertex[0] = 'A';
	g->vertex[1] = 'B';
	g->vertex[2] = 'C';
	g->vertex[3] = 'D';
	g->vertex[4] = 'E';
	g->vertex[5] = 'F';
	g->vertex[6] = 'G';
	g->vertex[7] = 'H';
	g->vertex[8] = 'I';
	//��ʼ����ά����
	for (int i = 0; i < g->vertex_num; i++)
	{
		for (int j = 0; j < g->vertex_num; j++)
		{
			g->arc[i][j] = 0;
		}
	}
	//�������������������ӵĲ��ֱ�ʾ����
	//A-B A-F
	g->arc[0][1] = 1;
	g->arc[0][5] = 1;
	//B-C B-G B-I
	g->arc[1][2] = 1;
	g->arc[1][6] = 1;
	g->arc[1][8] = 1;
	//C-D  C-I
	g->arc[2][3] = 1;
	g->arc[2][8] = 1;
	//D-E D-G D-H D-I
	g->arc[3][4] = 1;
	g->arc[3][6] = 1;
	g->arc[3][7] = 1;
	g->arc[3][8] = 1;
	//E-F E-H
	g->arc[4][5] = 1;
	g->arc[4][7] = 1;
	//F-G
	g->arc[5][6] = 1;
	//G-H
	g->arc[6][7] = 1;
	//���öԳƣ��������ǲ��ֱ�ʾ����
	for (int i = 0; i < g->vertex_num; i++)
	{
		for (int j = 0; j < g->vertex_num; j++)
		{
			g->arc[j][i] = g->arc[i][j];
		}
	}
}
void bfs(mat_grph g)//����ͼ����
{
	int i = 0;//���붥��
	visited[i] = 1;//�˶����Ѿ�������
	printf("%c\n",g.vertex[i]);//��ӡ����
	queue[rear] = i;//�˶��������
	rear++;//��βָ����Զָ���βԪ�ص���һ��
	while (front != rear)//���в�Ϊ��ʱ
	{
		i = queue[front];//��ͷԪ�س���
		front++; //��ͷ��һ
		for (int j = 0; j < g.vertex_num; j++)
		{//�ڶ���ĺ���ȥ��
			if (g.arc[i][j] == 1 && visited[j] == 0)
			{//��ö����������һ�û�б����ʹ�������
				visited[j] = 1;//�����Ƕ����1
				printf("%c\n",g.vertex[j]);//��ӡ����
				queue[rear] = j;//���˶��㶼��ӽ���
				rear++;//��βָ���1
			}
		}
	}
}
int main()
{
	//��ͼ
	mat_grph g;
	create_graph(&g);
	//��ʼ�����ж��㶼û�б����ʹ�
	for (int i = 0; i < g.vertex_num; i++)
	{
		visited[i] = 0;
	}
	bfs(g);
	return 0;
}