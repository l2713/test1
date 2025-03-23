#include<stdio.h>
typedef char vertextype;//顶点的数据类型用char
typedef int edgetype;//边的数据类型用int
#define maxsize 100
 //表示邻接矩阵
typedef struct
{
	vertextype vertex[maxsize];//用来存放顶点的数组
	edgetype arc[maxsize][maxsize];//表示二维数组
	int vertex_num;//顶点的数量
	int edge_num;//边的数量
}mat_grph;
int visited[maxsize];//用来表示顶点是否被访问过，0表示没有被访问，1表示已经被访问了
int front = 0;//队头
int rear = 0;//队尾
int queue[maxsize];//队列
void create_graph(mat_grph* g)//造图函数
{
	g->vertex_num = 9;//顶点数量为9个
	g->edge_num = 15;//边数量为15个
	//依次对每一个顶点输入对应的字符
	g->vertex[0] = 'A';
	g->vertex[1] = 'B';
	g->vertex[2] = 'C';
	g->vertex[3] = 'D';
	g->vertex[4] = 'E';
	g->vertex[5] = 'F';
	g->vertex[6] = 'G';
	g->vertex[7] = 'H';
	g->vertex[8] = 'I';
	//初始化二维矩阵
	for (int i = 0; i < g->vertex_num; i++)
	{
		for (int j = 0; j < g->vertex_num; j++)
		{
			g->arc[i][j] = 0;
		}
	}
	//把上三角两个顶点连接的部分表示出来
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
	//运用对称，把下三角部分表示出来
	for (int i = 0; i < g->vertex_num; i++)
	{
		for (int j = 0; j < g->vertex_num; j++)
		{
			g->arc[j][i] = g->arc[i][j];
		}
	}
}
void bfs(mat_grph g)//传入图进来
{
	int i = 0;//传入顶点
	visited[i] = 1;//此顶点已经被访问
	printf("%c\n",g.vertex[i]);//打印出来
	queue[rear] = i;//此顶点先入队
	rear++;//队尾指针永远指向队尾元素的下一个
	while (front != rear)//队列不为空时
	{
		i = queue[front];//队头元素出队
		front++; //队头加一
		for (int j = 0; j < g.vertex_num; j++)
		{//在顶点的横向去找
			if (g.arc[i][j] == 1 && visited[j] == 0)
			{//与该顶点有连接且还没有被访问过发顶点
				visited[j] = 1;//将它们都变成1
				printf("%c\n",g.vertex[j]);//打印出来
				queue[rear] = j;//将此顶点都入队进来
				rear++;//队尾指针加1
			}
		}
	}
}
int main()
{
	//造图
	mat_grph g;
	create_graph(&g);
	//初始化所有顶点都没有被访问过
	for (int i = 0; i < g.vertex_num; i++)
	{
		visited[i] = 0;
	}
	bfs(g);
	return 0;
}