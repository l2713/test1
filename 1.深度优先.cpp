#include <stdio.h>
typedef char VertexType;//���������������char
typedef int EdgeType;//�ߵ�����������int 
#define MAXSIZE 100
 //��ʾ�ڽӾ���
typedef struct
{
	VertexType vertex[MAXSIZE];//��Ŷ��������
	EdgeType arc[MAXSIZE][MAXSIZE];//��ά����
	int vertex_num;//���������
	int edge_num;//�ߵ�����
}Mat_Grph;

int visited[MAXSIZE];//��ʾ�����Ƿ񱻷��ʹ���0��ʾû�б����ʣ�1��ʾ������

void create_graph(Mat_Grph* G)//��ͼ����
{
	G->vertex_num = 9;//��������Ϊ9
	G->edge_num = 15;//����Ϊ15��
	//���θ�ÿһ�����㶼��Ŷ��ڵ��ַ�
	G->vertex[0] = 'A';
	G->vertex[1] = 'B';
	G->vertex[2] = 'C';
	G->vertex[3] = 'D';
	G->vertex[4] = 'E';
	G->vertex[5] = 'F';
	G->vertex[6] = 'G';
	G->vertex[7] = 'H';
	G->vertex[8] = 'I';
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[i][j] = 0;
		}
	}//�ڽӾ��󣬾��о��У�ȫ��ѭ����ʼ����ֵΪ0
	//�ٸ��ݶ�Ӧ��ͼ���������ӵ��������㣬�ھ����и�ֵΪ1����ʾ������
	//A-B A-F
	G->arc[0][1] = 1;
	G->arc[0][5] = 1;

	//B-C B-G B-I
	G->arc[1][2] = 1;
	G->arc[1][6] = 1;
	G->arc[1][8] = 1;

	//C-D C-I
	G->arc[2][3] = 1;
	G->arc[2][8] = 1;

	//D-E D-G D-H D-I
	G->arc[3][4] = 1;
	G->arc[3][6] = 1;
	G->arc[3][7] = 1;
	G->arc[3][8] = 1;

	//E-F E-H
	G->arc[4][5] = 1;
	G->arc[4][7] = 1;

	//F-G
	G->arc[5][6] = 1;

	//G-H
	G->arc[6][7] = 1;
	//�ԶԽ���Ϊ�ᣬ�����Ǻ��������ǶԳƵģ����п��԰������ǽ������Ǹ�ֵ
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

void dfs(Mat_Grph G, int i)//����ͼ��Ҫ�����ʵĶ���
{
	visited[i] = 1;//��ʾ�˽�����ڿ�ʼ���ʣ���ֵΪ1
	printf("%c\n", G.vertex[i]);//���Ұ�����ӡ����

	for (int j = 0; j < G.vertex_num; j++)
	{//��A�ĺ��п�ʼ�ң������ߵ�
		if (G.arc[i][j] == 1 && visited[j] == 0)
		{//�ҵ��Ǻ�A���������ߣ�����Ŀǰ��û�б����ʹ��Ķ���
			dfs(G, j);//�ٰ�j����ȥ����jΪ���㣬�ݹ麯��
	}
}

int main()
{
	Mat_Grph G;//����ṹ�����
	create_graph(&G);//��ͼ����
	//��ʼ�����ж��㶼��û�б����ʹ�
	for (int i = 0; i < G.vertex_num; i++)
	{
		visited[i] = 0;
	}
	dfs(G, 0);//����ͼ�Ͷ����±�
	return 0;
}











