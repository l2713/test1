//#include <stdio.h>
//#include <stdlib.h>
//
//typedef int VertextType;
//typedef int EdgeType;
//
//#define MAXSIZE 100
//邻接矩阵
//typedef struct
//{
//	VertextType vertex[MAXSIZE];//边数组
//	EdgeType arc[MAXSIZE][MAXSIZE];//二维数组
//	int vertex_num;//顶点数量
//	int edge_num;//边数量
//}Mat_Graph;
//表示邻接表
//表示边的结构体
//typedef struct EdgeNode
//{
//	int edge_vex;//表示顶点的下标，V0下标表示为0
//	struct EdgeNode* next;//链表的箭头
//}EdgeNode;
//表达顶点的结构体
//typedef struct VertextNode
//{
//	int in;//表示这个结点的入度为几
//	VertextType data;//表达顶点元素
//	EdgeNode* head;//顶点延伸出去的箭头
//}VertextNode;
//
//typedef VertextNode Adj_List[MAXSIZE];//adjacency毗邻邻接
//表达整个邻接表
//typedef struct
//{
//	Adj_List adj_list;
//	int vertex_num;//顶点数量
//	int edge_num;//边数量
//}Adj_Graph;
//
//typedef Adj_Graph* Adj_List_Graph;
//
//int top = -1;//初始化top，栈顶指针
//int stack[MAXSIZE];//栈数组
//入栈函数
//void push(int e)
//{
//	if (top > MAXSIZE)
//	{
//		printf("满了\n");
//		return;
//	}
//
//	top++;
//	stack[top] = e;
//}
//出栈函数
//int pop()
//{
//	if (top == -1)
//	{//先判断是否为空
//		printf("空的\n");
//		return 0;
//	}
//
//	int elem = stack[top];
//	top--;
//	return elem;
//}
//判断栈是否为空
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
//造图函数
//void create_graph(Mat_Graph* G)
//{
//	G->vertex_num = 14;//顶点数量
//	G->edge_num = 20;//边数量
//
//	for (int i = 0; i < G->vertex_num; i++)
//	{
//		G->vertex[i] = i;//对每一个顶点都直接用数字0，1，2，表示
//	}
//
//	for (int i = 0; i < G->vertex_num; i++)
//	{
//		for (int j = 0; j < G->vertex_num; j++)
//		{
//			G->arc[i][j] = 0;//初始化每一个元素都是0
//		}
//	}
//	对有连接的两个顶点赋值1，表示有连接
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
//void create_adj_graph(Mat_Graph G, Adj_List_Graph* ALG)//邻接矩阵传进来转换成邻接表
//{
//	EdgeNode* e;
//
//	*ALG = (Adj_List_Graph)malloc(sizeof(Adj_Graph));//开辟空间存放邻接表
//	(*ALG)->vertex_num = G.vertex_num;//将邻接矩阵中的顶点赋值到邻接表中
//	(*ALG)->edge_num = G.edge_num;//将邻接矩阵中的边赋值到邻接表中
//
//	对邻接表做初始化
//	for (int i = 0; i < G.vertex_num; i++)
//	{
//		(*ALG)->adj_list[i].in = 0;//入度全部为0
//		(*ALG)->adj_list[i].data = G.vertex[i];//每个顶点元素全部赋成，0，1，这类数字方便表示
//		(*ALG)->adj_list[i].head = NULL;//指针全部指向空（暂时不完善下一个顶点）
//	}
//
//	for (int i = 0; i < G.vertex_num; i++)
//	{
//		for (int j = 0; j < G.vertex_num; j++)
//		{
//			if (G.arc[i][j] == 1)//如果两个顶点之间有连接
//			{
//				e = (EdgeNode*)malloc(sizeof(EdgeNode));//堆内存中开辟空间
//				e->edge_vex = j;//将连接顶点赋值过去
//				头插法
//				e->next = (*ALG)->adj_list[i].head;
//				(*ALG)->adj_list[i].head = e;
//				(*ALG)->adj_list[j].in++;//此时有连接的顶点入度加一
//			}
//		}
//	}
//}
//拓扑排序函数
//void topological_sort(Adj_List_Graph ALG)
//{
//	EdgeNode* e;
//	int curr;
//	int k;
//
//	for (int i = 0; i < ALG->vertex_num; i++)
//	{
//		if (ALG->adj_list[i].in == 0)//入度为0
//		{
//			push(i);//直接入栈
//		}
//	}
//
//	while (is_empty() != 0)
//	{
//		curr = pop();//出栈，用curr承接
//		printf("V%d -> ", ALG->adj_list[curr].data);//输出此时的顶点
//		e = ALG->adj_list[curr].head;//把它所连接的一个顶点给e
//
//		while (e != NULL)
//		{
//			k = e->edge_vex;//再赋值给k
//			ALG->adj_list[k].in--;//再将这个顶点入度减1
//			if (ALG->adj_list[k].in == 0)//如果此时这个顶点入度为0
//			{
//				push(k);//继续入栈
//			}
//			e = e->next;//再将它后连接哪一个顶点赋值给e，再去判断后面顶点的入度情况，直到它所连接的顶点为空
//		}
//	}
//}
//
//int main(int argc, char const* argv[])
//{
//	Mat_Graph G;//邻接矩阵结构体变量
//	Adj_List_Graph ALG;//邻接表指针的变量
//	create_graph(&G);//造邻接矩阵
//	create_adj_graph(G, &ALG);//邻接矩阵转换成邻接表
//	topological_sort(ALG);//拓扑排序
//	return 0;
//}


#include <stdio.h>
#include <stdlib.h>

typedef int VertextType;
typedef int EdgeType;

#define MAXSIZE 100
#define MAX 0x7fffffff
//邻接矩阵
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
	int weight;//表示权重
	struct EdgeNode* next;
}EdgeNode;

typedef struct VertextNode
{
	int in;
	VertextType data;
	EdgeNode* head;
}VertextNode;

typedef VertextNode Adj_List[MAXSIZE];
//邻接表
typedef struct
{
	Adj_List adj_list;
	int vertex_num;
	int edge_num;
}Adj_Graph;

typedef Adj_Graph* Adj_List_Graph;

//造邻接矩阵
void create_graph(Mat_Graph* G)
{
	G->vertex_num = 10;
	G->edge_num = 13;
	//给每一个顶点赋值为相应的数字
	for (int i = 0; i < G->vertex_num; i++)
	{
		G->vertex[i] = i;
	}

	for (int i = 0; i < G->vertex_num; i++)
	{
		for (int j = 0; j < G->vertex_num; j++)
		{
			if (i == j)
			{//对角线元素为0
				G->arc[i][j] = 0;
			}
			else
			{//其他全部为无穷
				G->arc[i][j] = MAX;
			}
		}
	}
	//给有连接的两个顶点赋值
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
//邻接矩阵转邻接表
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
//关键路径函数
void critical_path(Adj_List_Graph ALG)
{
	EdgeNode* e;
	int top = -1;
	int top2 = -1;
	//两个栈
	int stack[MAXSIZE];//第一个栈用来表示正常做事的顺序，相当于是最早时间
	int stack2[MAXSIZE];//第二个栈倒着来，相当于用来表示最晚发生的时间
	int etv[MAXSIZE];
	int ltv[MAXSIZE];
	int curr;//保存出栈内容
	int k;//当下标用
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		if (ALG->adj_list[i].in == 0)
		{
			top++;
			stack[top] = i;
		}
	}
	//初始化最早发生时间的数组
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		etv[i] = 0;
	}
	//第一个栈
	while (top != -1)
	{
		curr = stack[top];
		top--;
		printf("V%d -> ", ALG->adj_list[curr].data);
		//出栈后再把这个东西压入到另一个栈中去
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
			{//取最大值。判断最早发生时间
				etv[k] = etv[curr] + e->weight;
			}
			e = e->next;
		}
	}
	printf("End\n");
	//输出etv数组
	printf("etv: ");
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		printf("%d -> ", etv[i]);
	}
	printf("End\n");
	//默认ltv初始化全部都是最后一个值
	for (int i = 0; i < ALG->vertex_num; i++)
	{
		ltv[i] = etv[ALG->vertex_num - 1];
	}
	//第二个栈
	while (top2 != -1)
	{
		curr = stack2[top2];
		top2--;

		e = ALG->adj_list[curr].head;
		while (e != NULL)
		{
			k = e->edge_vex;

			if (ltv[k] - e->weight < ltv[curr])
			{//找最小值
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
	{//如果发现etv等于ltv在=再将这个顶点输出
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