#include <stdio.h>
typedef char VertexType;//顶点的数据类型用char
typedef int EdgeType;//边的数据类型用int 
#define MAXSIZE 100
 //表示邻接矩阵
typedef struct
{
	VertexType vertex[MAXSIZE];//存放顶点的数组
	EdgeType arc[MAXSIZE][MAXSIZE];//二维数组
	int vertex_num;//顶点的数量
	int edge_num;//边的数量
}Mat_Grph;

int visited[MAXSIZE];//表示顶点是否被访问过，0表示没有被访问，1表示被访问

void create_graph(Mat_Grph* G)//造图函数
{
	G->vertex_num = 9;//顶点数量为9
	G->edge_num = 15;//边数为15个
	//依次给每一个顶点都存放对于的字符
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
	}//邻接矩阵，九行九列，全部循环初始化赋值为0
	//再根据对应的图，将有连接的两个顶点，在矩阵中赋值为1，表示有连接
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
	//以对角线为轴，上三角和下三角是对称的，所有可以按上三角将下三角赋值
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

void dfs(Mat_Grph G, int i)//传入图和要被访问的顶点
{
	visited[i] = 1;//表示此结点现在开始访问，赋值为1
	printf("%c\n", G.vertex[i]);//并且把它打印出来

	for (int j = 0; j < G.vertex_num; j++)
	{//从A的横行开始找，有连线的
		if (G.arc[i][j] == 1 && visited[j] == 0)
		{//找的是和A顶点有连线，但是目前还没有被访问过的顶点
			dfs(G, j);//再把j传过去，以j为顶点，递归函数
	}
}

int main()
{
	Mat_Grph G;//创造结构体变量
	create_graph(&G);//造图函数
	//初始化所有顶点都还没有被访问过
	for (int i = 0; i < G.vertex_num; i++)
	{
		visited[i] = 0;
	}
	dfs(G, 0);//传入图和顶点下标
	return 0;
}











