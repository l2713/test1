#include <stdio.h>

typedef int VertexType;
typedef int EdgeType;

#define MAXSIZE 100
#define MAXEDGE 200
#define MAX 0x10000
//��ʾ�ڽӾ���
typedef struct
{
	VertexType vertex[MAXSIZE];//��ʾ��������
	EdgeType arc[MAXSIZE][MAXSIZE];//��ʾ��ά����
	int vertex_num;//��ʾ��������
	int edge_num;//��ʾ�ߵ�����
}Mat_Graph;
//��ͼ����
void createGraph(Mat_Graph* G)
{
	G->vertex_num = 9;//��������Ϊ9
	G->edge_num = 16;//������Ϊ15

	for (int i = 0; i < G->vertex_num; i++)
	{
		G->vertex[i] = i;//��ʱ���������ŵĶ������֣��磺0��1��2��3��4�ȵ�,�����Ƕ���V0,V1,V2,V3�ȵȣ���һ���̶��ϣ���ʾ�ľ��Ƕ���
	}

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (i == j)
			{//�Խ���Ԫ��ȫ��Ϊ0
				G->arc[i][j] = 0;
			}
			else
			{//����Ԫ��ȫ����ʼ��Ϊmax,Ҳ���ǡ�
				G->arc[i][j] = MAX;
			}
		}
	}

	//�������������Ӷ���֮���Ȩֵ����Ӧλ�ø�ֵ
	G->arc[0][1] = 1;
	G->arc[0][2] = 5;

	G->arc[1][2] = 3;
	G->arc[1][3] = 7;
	G->arc[1][4] = 5;

	G->arc[2][4] = 1;
	G->arc[2][5] = 7;

	G->arc[3][4] = 2;
	G->arc[3][6] = 3;

	G->arc[4][5] = 3;
	G->arc[4][6] = 6;
	G->arc[4][7] = 9;

	G->arc[5][7] = 5;

	G->arc[6][7] = 2;
	G->arc[6][8] = 7;

	G->arc[7][8] = 4;
	//���öԳƣ���������Ԫ�ظ�ֵ
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = i; j < G->vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}
//������һ��Ҫ�۲���һ������
int choose(int distance[], int found[], int vertex_num)
{
	//�ҵ�����V0��������Ȩֵ���Լ��ĸ����㣬�������������б���
	int min = MAX;//�������Ȩֵ
	int minPos = -1;//������Ƕ���
	for (int i = 0; i < vertex_num; i++)
	{
		if (distance[i] < min && found[i] == 0)//����ѭ���Ҿ�����С�Ķ���������û�б����ʹ�
		{
			min = distance[i];//min��ʱ��ɾ�����С���Ǹ�Ȩֵ
			minPos = i;//minpos�����ʱ������С�Ķ��㣬ͬʱ�ֵ����µĶ����ʹ��
		}
	}
	return minPos;//���ش�ʱ������С�Ķ���
}
void dijkstra(Mat_Graph G, int begin)//�������V0����V0���㿪ʼ��
{
	int found[MAXSIZE];//������ʾ�����Ƿ񱻷��ʹ���0��ʾû�У�1��ʾ�Ѿ�������
	int path[MAXSIZE];//������ʾ����ĳ�������������Ķ��㣬ֵ��ʾһ�����㣬�±��ʾһ������
	int distance[MAXSIZE];//V0����ÿһ���������̾���
	for (int i = 0; i < G.vertex_num; i++)
	{//��������������г�ʼ��
		found[i] = 0;//���ж��㶼�ȱ�Ϊ0����ʾ����û�б����ʹ�
		path[i] = -1;//ȫ����ֵ��-1
		distance[i] = G.arc[begin][i];//���鸳ֵ�ɵ�һ�У�Ҳ���ǵ�0�У���ֵ
	}

	found[begin] = 1;//��ʾ���ʴ˶���
	distance[begin] = 0;//��V0���㵽V0����֮��ľ���

	int next;//��һ��Ҫ�۲�Ķ��㡡
	for (int i = 1; i < G.vertex_num; i++)//ѭ����1��ʼ��0�Ѿ����۲����
	{	//1
		next = choose(distance, found, G.vertex_num);//���ؽ�����Ҫ���ʵĶ���
		//printf("%d", next);
		found[next] = 1;//��ʾV1��������Ѿ������ʹ���
		for (int j = 0; j < G.vertex_num; j++)
		{//�����ж��Ƿ�Ϊ��������Ķ���
			if (found[j] == 0)//�����û�б����ʹ��Ķ���
			{
				//��ʱ���˶��㣬����distance����
				if (distance[next] + G.arc[next][j] < distance[j])
				{//��ʱ�ҵ�����С�ľ������distance[next]+G.arc[next][j]
					distance[j] = distance[next] + G.arc[next][j];//����С�����Ȩֵ��ֵ��distance,�Ǵ�V0��ʼ�ľ���
					path[j] = next;//��ʱj����Ǿ�������Ķ���
				}
			}
		}
	}



	for (int i = 1; i < G.vertex_num; i++)
	{
		//�����ӡ
		printf("V0 -> v%d : %d\n", i, distance[i]);//ѭ����ӡ��ʼ���㵽ÿ��������������

		//�����ӡ
		int j = i;//����ĩ�˵Ķ��㸳ֵ��j�������ʼ�Ķ���
		printf("V%d <- ", i);
		while (path[j] != -1)//�����������������Ķ���ʱ
		{
			//���ϵ�ѭ����ӡ
			printf("V%d <- ", path[j]);//��ӡ��������Ķ���
			j = path[j];//�ٰ��������±꣬�������������Ķ���
		}
		//����jΪ8,��ô���붥��8����Ķ��㣬��ôpath[j]��Ϊ7�����Ҹ�ֵ��jҲΪ7�����Ҿ���7�������Ķ���ֵ���ٰ����ֵ���������±꣬һ�δ�Ѱ��
		printf("V0\n");//һֱ�ҵ���ʼ����

	}

}

int main(int argc, char const* argv[])
{
	Mat_Graph G;
	createGraph(&G);
	int begin = 0;//��V0���㿪ʼ��
	dijkstra(G, begin);//���ڽӾ���Ͷ��㴫��ȥ�����ô��㷨
	return 0;
}





#include<stdio.h>
typedef int VertexType;
typedef int EdgeType;
#define MAXSIZE 100
#define MAXEDGE 200
#define MAX 0x10000
//�ڽӾ���
typedef struct
{
	VertexType vertex[MAXSIZE];//��������
	EdgeType arc[MAXSIZE][MAXSIZE];//��ά����
	int vertex_num;//��������
	int edge_num;//������
}Mat_Graph;
void createGraph(Mat_Graph* G)
{
	G->vertex_num = 9;//9������
	G->edge_num = 16;//16����
	for (int i = 0; i < G->vertex_num; i++)
	{
		G->vertex[i] = i;//��ʱ�������������ŵ�ȫ��Ϊ���֣�0��1��2��3�ȵ�
	}
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (i == j)
			{//�Խ���ȫ����ֵΪ0
				G->arc[i][j] = 0;
			}
			else
			{//����Ԫ��Ϊ��
				G->arc[i][j] = MAX;
			}
		}
	}
	//�������ӵ��������㸳ֵ
	G->arc[0][1] = 1;
	G->arc[0][2] = 5;

	G->arc[1][2] = 3;
	G->arc[1][3] = 7;
	G->arc[1][4] = 5;

	G->arc[2][4] = 1;
	G->arc[2][5] = 7;

	G->arc[3][4] = 2;
	G->arc[3][6] = 3;

	G->arc[4][5] = 3;
	G->arc[4][6] = 6;
	G->arc[4][7] = 9;

	G->arc[5][7] = 5;
	
	G->arc[6][7] = 2;
	G->arc[6][8] = 7;

	G->arc[7][8] = 4;
	//���öԳƣ��������Ǹ�ֵ
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[i][j] = G->arc[i][j];
		}
	}
}
void floyd(Mat_Graph G)
{
	int path[MAXSIZE][MAXSIZE];//��ʾ��ʼ���㵽ĩβ���㣬ֵ��ʾĩβ���㣬������м䶥�㣬�ͱ�ʾ�м䶥���ֵ
	int distance[MAXSIZE][MAXSIZE];//�����Ż���ά���󣬲��ұ�ʾ����֮�����̾���
	//��ʼ����������
	for (int i = 0; i < G.vertex_num; i++)
	{
		for (int j = 0; j < G.vertex_num; j++)
		{
			distance[i][j] = G.arc[i][j];//���ڽӾ����ֵ��ֵ����һ����ά������
			path[i][j] = j;//��ʾ������������֮�����������ֵ��ĩβ����
		}
	}
	//j:��ʼ����    i����ת����    k:��ֹ����
	for (int i = 0; i < G.vertex_num; i++)
	{
		for (int j = 0; j < G.vertex_num; j++)
		{
			for (int k = 0; k < G.vertex_num; k++)
			{
				if (distance[j][k] > distance[j][i] + distance[i][k])
				{//��ʱ�ҵ����м䶥�㣬ʹ������С
					distance[j][k] = distance[j][i] + distance[i][k];//����̾��븳ֵ����ά������
					path[j][k] = path[j][i];//��һ�����㵽��һ�������ֵ��Ҳ����ĩβ���㣩��ֵΪ�����м䶥���ֵ��Ҳ�����м䶥�㣩
				}
			}
		}
	}
	//���
	int k;
	for (int i = 0; i < G.vertex_num; i++)
	{//i�������ж���
		for (int j = i + 1; j < G.vertex_num; j++)
		{
			printf("V%d->V%d weight:%d",i,j,distance[i][j]);//��ӡ��V0���㵽�󶥵�ģ�������֮�����̾���
			k = path[i][j];
			printf("path:V%d",i);//path����ʼ���㿪ʼ
			while (k != j)
			{
				printf("->V%d",k);
				k = path[k][j];
			}
			printf("->V%d\n",j);
		}
		printf("\n");
	}
}
int main()
{
	Mat_Graph G;
	//��ͼ����
	createGraph(&G);
	//���ú���
	floyd(G);
	return 0;
}

