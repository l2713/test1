#include <stdio.h>

typedef int VertexType;
typedef int EdgeType;

#define MAXSIZE 100
#define MAXEDGE 200
#define MAX 0x10000
//表示邻接矩阵
typedef struct
{
	VertexType vertex[MAXSIZE];//表示顶点数组
	EdgeType arc[MAXSIZE][MAXSIZE];//表示二维数组
	int vertex_num;//表示顶点数量
	int edge_num;//表示边的数量
}Mat_Graph;
//造图函数
void createGraph(Mat_Graph* G)
{
	G->vertex_num = 9;//顶点数量为9
	G->edge_num = 16;//边数量为15

	for (int i = 0; i < G->vertex_num; i++)
	{
		G->vertex[i] = i;//此时顶点数组存放的都是数字，如：0，1，2，3，4等等,并不是顶点V0,V1,V2,V3等等，在一定程度上，表示的就是顶点
	}

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (i == j)
			{//对角线元素全部为0
				G->arc[i][j] = 0;
			}
			else
			{//其他元素全部初始化为max,也就是∞
				G->arc[i][j] = MAX;
			}
		}
	}

	//根据两个有连接顶点之间的权值给对应位置赋值
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
	//利用对称，给下三角元素赋值
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = i; j < G->vertex_num; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
}
//返回下一次要观察哪一个顶点
int choose(int distance[], int found[], int vertex_num)
{
	//找的是离V0最近顶点的权值，以及哪个顶点，用两个变量进行保存
	int min = MAX;//保存的是权值
	int minPos = -1;//保存的是顶点
	for (int i = 0; i < vertex_num; i++)
	{
		if (distance[i] < min && found[i] == 0)//利用循环找距离最小的顶点且它还没有被访问过
		{
			min = distance[i];//min此时变成距离最小的那个权值
			minPos = i;//minpos保存此时距离最小的顶点，同时又当作新的顶点的使用
		}
	}
	return minPos;//返回此时距离最小的顶点
}
void dijkstra(Mat_Graph G, int begin)//传入的是V0，从V0顶点开始找
{
	int found[MAXSIZE];//用来表示顶点是否被访问过，0表示没有，1表示已经被访问
	int path[MAXSIZE];//用来表示距离某个顶点距离最近的顶点，值表示一个顶点，下标表示一个顶点
	int distance[MAXSIZE];//V0到达每一个顶点的最短距离
	for (int i = 0; i < G.vertex_num; i++)
	{//对这三个数组进行初始化
		found[i] = 0;//所有顶点都先变为0，表示都还没有被访问过
		path[i] = -1;//全部赋值成-1
		distance[i] = G.arc[begin][i];//数组赋值成第一行（也就是第0行）的值
	}

	found[begin] = 1;//表示访问此顶点
	distance[begin] = 0;//从V0顶点到V0顶点之间的距离

	int next;//下一个要观察的顶点　
	for (int i = 1; i < G.vertex_num; i++)//循环从1开始，0已经被观察过了
	{	//1
		next = choose(distance, found, G.vertex_num);//返回接下来要访问的顶点
		//printf("%d", next);
		found[next] = 1;//表示V1这个顶点已经被访问过了
		for (int j = 0; j < G.vertex_num; j++)
		{//用来判断是否为距离最近的顶点
			if (found[j] == 0)//如果是没有被访问过的顶点
			{
				//此时换了顶点，更新distance数组
				if (distance[next] + G.arc[next][j] < distance[j])
				{//此时找到了最小的距离就是distance[next]+G.arc[next][j]
					distance[j] = distance[next] + G.arc[next][j];//将最小距离的权值赋值给distance,是从V0开始的距离
					path[j] = next;//此时j点就是距离最近的顶点
				}
			}
		}
	}



	for (int i = 1; i < G.vertex_num; i++)
	{
		//正向打印
		printf("V0 -> v%d : %d\n", i, distance[i]);//循环打印初始顶点到每个顶点的最近距离

		//反向打印
		int j = i;//把最末端的顶点赋值给j，当作最开始的顶点
		printf("V%d <- ", i);
		while (path[j] != -1)//当存在与它最近距离的顶点时
		{
			//不断的循环打印
			printf("V%d <- ", path[j]);//打印与它最近的顶点
			j = path[j];//再把它当作下标，找与它最近距离的顶点
		}
		//假如j为8,那么找与顶点8最近的顶点，那么path[j]就为7，并且赋值到j也为7，再找距离7最近距离的顶点值，再把这个值当作数组下标，一次次寻找
		printf("V0\n");//一直找到开始顶点

	}

}

int main(int argc, char const* argv[])
{
	Mat_Graph G;
	createGraph(&G);
	int begin = 0;//从V0顶点开始找
	dijkstra(G, begin);//将邻接矩阵和顶点传进去，调用此算法
	return 0;
}





#include<stdio.h>
typedef int VertexType;
typedef int EdgeType;
#define MAXSIZE 100
#define MAXEDGE 200
#define MAX 0x10000
//邻接矩阵
typedef struct
{
	VertexType vertex[MAXSIZE];//顶点数组
	EdgeType arc[MAXSIZE][MAXSIZE];//二维数组
	int vertex_num;//顶点数量
	int edge_num;//边数量
}Mat_Graph;
void createGraph(Mat_Graph* G)
{
	G->vertex_num = 9;//9个顶点
	G->edge_num = 16;//16条边
	for (int i = 0; i < G->vertex_num; i++)
	{
		G->vertex[i] = i;//此时顶点数组里面存放的全部为数字，0，1，2，3等等
	}
	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (i == j)
			{//对角线全部赋值为0
				G->arc[i][j] = 0;
			}
			else
			{//其余元素为∞
				G->arc[i][j] = MAX;
			}
		}
	}
	//将有连接的两个顶点赋值
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
	//利用对称，给下三角赋值
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
	int path[MAXSIZE][MAXSIZE];//表示起始顶点到末尾顶点，值表示末尾顶点，如果有中间顶点，就表示中间顶点的值
	int distance[MAXSIZE][MAXSIZE];//用来优化二维矩阵，并且表示他们之间的最短距离
	//初始化两个数组
	for (int i = 0; i < G.vertex_num; i++)
	{
		for (int j = 0; j < G.vertex_num; j++)
		{
			distance[i][j] = G.arc[i][j];//把邻接矩阵的值赋值到另一个二维数组中
			path[i][j] = j;//表示的是两个顶点之间的相连，赋值到末尾顶点
		}
	}
	//j:起始顶点    i：中转顶点    k:终止顶点
	for (int i = 0; i < G.vertex_num; i++)
	{
		for (int j = 0; j < G.vertex_num; j++)
		{
			for (int k = 0; k < G.vertex_num; k++)
			{
				if (distance[j][k] > distance[j][i] + distance[i][k])
				{//此时找到了中间顶点，使距离最小
					distance[j][k] = distance[j][i] + distance[i][k];//将最短距离赋值到二维矩阵中
					path[j][k] = path[j][i];//把一个顶点到另一个顶点的值（也就是末尾顶点）赋值为到达中间顶点的值（也就是中间顶点）
				}
			}
		}
	}
	//输出
	int k;
	for (int i = 0; i < G.vertex_num; i++)
	{//i遍历所有顶点
		for (int j = i + 1; j < G.vertex_num; j++)
		{
			printf("V%d->V%d weight:%d",i,j,distance[i][j]);//打印从V0顶点到后顶点的，且他们之间的最短距离
			k = path[i][j];
			printf("path:V%d",i);//path从起始顶点开始
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
	//造图函数
	createGraph(&G);
	//调用函数
	floyd(G);
	return 0;
}

