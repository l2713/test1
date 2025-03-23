#include <stdio.h>
#include <stdlib.h>

typedef char VertexType;
typedef int EdgeType;

#define MAXSIZE 100
#define MAX 0x7fffffff
//表示邻接矩阵
typedef struct
{
	VertexType vertex[MAXSIZE];//顶点数组
	EdgeType arc[MAXSIZE][MAXSIZE];//二维数组
	int vertex_num;//顶点数量
	int edge_num;//边数量
}Mat_Grph;


void create_graph(Mat_Grph* G)//造图函数
{
	G->vertex_num = 9;
	G->edge_num = 15;
	//依次给每一个顶点赋值
	G->vertex[0] = 'A';
	G->vertex[1] = 'B';
	G->vertex[2] = 'C';
	G->vertex[3] = 'D';
	G->vertex[4] = 'E';
	G->vertex[5] = 'F';
	G->vertex[6] = 'G';
	G->vertex[7] = 'H';
	G->vertex[8] = 'I';
	//初始化矩阵
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (i == j)
			{//对角线全部为0（带权值的邻接矩阵的性质）
				G->arc[i][j] = 0;
			}
			else
			{//不是对角线的全部变成max，无穷
				G->arc[i][j] = MAX;
			}

		}
	}
	//将有连接的两个顶点之间的权值赋在矩阵上
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
	//运用对称，把下三角也填充完毕
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
	int min;//存放最小值
	int weight[MAXSIZE];//存放待选的权值
	int vex_index[MAXSIZE];//值表示出发点，下标表示到达点，如果值为1，下标为0，那么表示从B顶点到A顶点

	//先从顶点A开始
	weight[0] = 0; //vex_index某点与下标对应点的权重
	vex_index[0] = 0;//A顶点与A顶点相连
	//从1开始循环，第0个位置已经赋值为0了
	for (i = 1; i < G->vertex_num; i++)
	{
		weight[i] = G->arc[0][i];//对weight数组进行初始化（因为一开始从A顶点找权值最小的顶点，所以此数组中存放与A顶点相关的所有路径权值
		vex_index[i] = 0;//都从0开始连接，也就是A顶点
	}

	for (int i = 1; i < G->vertex_num; i++)
	{
		min = MAX;
		j = 0;
		k = 0;
		//找到最小的，与之连接
		while (j < G->vertex_num)//j从0变到8
		{
			if (weight[j] != 0 && weight[j] < min)
			{//找距离A顶点最近的权值
				min = weight[j];//并且赋值到min上
				k = j;//找到距离最小的那个顶点，并且记录下来
			}
			j++;
		}

		//printf("(%d, %d)\n", vex_index[k], k);//输出：（0，1）
		printf("(%c, %c)\n", G->vertex[vex_index[k]], G->vertex[k]);//输出：（A,B）
		weight[k] = 0;//B顶点被找到后，AB之间的路径就不能再选了，此时数组在B顶点的值为0，表示此路径不能再走了

		//找新连接结点的待选路径
		for (j = 0; j < G->vertex_num; j++)
		{
			//与新结点可连接的边进行比较，有比weight小的就替换
			if (weight[j] != 0 && G->arc[k][j] < weight[j])
			{
				weight[j] = G->arc[k][j];//把权值小的边赋值到weight数组内，表示被放到待选组内
				vex_index[j] = k;//此时距离k顶点最近的顶点是j,那么在此数组中，表示k顶点距离它们最近
			}
		}

	}
}

int main(int argc, char const* argv[])
{
	//Mat_Grph* G = (Mat_Grph*)malloc(sizeof(Mat_Grph));
	Mat_Grph G;
	//造图
	create_graph(&G);
	//调用函数
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
//邻接矩阵
typedef struct
{
	VertexType vertex[MAXSIZE];//顶点数组
	EdgeType arc[MAXSIZE][MAXSIZE];//二维数组
	int vertex_num;//顶点数量
	int edge_num;//边数量
}Mat_Grph;
//边结构体
typedef struct
{
	int begin;//开始顶点
	int end;//结束顶点(无向图）
	int weight;//表示权值
}Edge;

//造图函数
void create_graph(Mat_Grph* G)
{
	//9个顶点，15条边
	G->vertex_num = 9;
	G->edge_num = 15;
	//依次给数组的每一个元素赋上对应的顶点
	G->vertex[0] = 'A';
	G->vertex[1] = 'B';
	G->vertex[2] = 'C';
	G->vertex[3] = 'D';
	G->vertex[4] = 'E';
	G->vertex[5] = 'F';
	G->vertex[6] = 'G';
	G->vertex[7] = 'H';
	G->vertex[8] = 'I';
	//每行每列，双层循环去赋值
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (i == j)
			{//对角线元素赋值为0
				G->arc[i][j] = 0;
			}
			else
			{//不是对角线的元素初始化全部赋值为∞
				G->arc[i][j] = MAX;
			}

		}
	}
	//根据顶点之间的连线去加上权值
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
	//对称原则，根据上三角赋值下三角
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}

void swap(Edge* edges, int i, int j)
{//分别把每一个变量做一个交换
	int temp;//中间变量
	//开始顶点交换
	temp = edges[i].begin;
	edges[i].begin = edges[j].begin;
	edges[j].begin = temp;
	//结束顶点交换
	temp = edges[i].end;
	edges[i].end = edges[j].end;
	edges[j].end = temp;
	//权值交换
	temp = edges[i].weight;
	edges[i].weight = edges[j].weight;
	edges[j].weight = temp;
}
//排序算法对权值进一步排序
void sortEdges(Edge edges[], int edge_num)//传入边数组，边数量
{
	for (int i = 0; i < edge_num; i++)
	{
		for (int j = i + 1; j < edge_num; j++)
		{
			if (edges[i].weight > edges[j].weight)
			{
				swap(edges, i, j);//进行交换
			}
		}
	}
}
//为了确认拿出来的顶点放在哪里，使两个顶点之间连接
int find(int* parent, int index)
{
	while (parent[index] > 0)
	{
		index = parent[index];
	}
	return index;
}

void Kruskal(Mat_Grph G)//直接把图传进来
{
	Edge edges[MAXEDGE];//15条边要用数组存放
	int k = 0;//当做下标使用，一开始先找第一组最小的边

	for (int i = 0; i < G.vertex_num; i++)
	{
		for (int j = i + 1; j < G.vertex_num; j++)
		{//找最小的权值
			if (G.arc[i][j] < MAX)
			{
				edges[k].begin = i;//找到后把i的值给初始顶点
				edges[k].end = j;//j的值给结束顶点
				edges[k].weight = G.arc[i][j];//把对应的最小权值赋到weight上
				k++;//接着找第二组，第三组。重复
			}
		}
	}

	sortEdges(edges, G.edge_num);//此时数组内已经被排好序了

	int parent[MAXSIZE];//下标和值分别表示两个顶点，这个数组表示这两个顶点之间相连
	//初始化这个数组，每个元素都为0
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
			parent[n] = m;//把这两个顶点连接起来，表示有着权值最小的边
			//printf("(%d, %d) %d\n", edges[i].beigin, edges[i].end, edges[i].weight);//输出数字
			printf("(%c, %c) %d\n", G.vertex[edges[i].begin], G.vertex[edges[i].end], edges[i].weight);//数字当下标，输出对应的顶点
		}
	}
}

int main(int argc, char const* argv[])
{
	//造图
	Mat_Grph G;
	create_graph(&G);
	//调用函数
	Kruskal(G);
	return 0;
}