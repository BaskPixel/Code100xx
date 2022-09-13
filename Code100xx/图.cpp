#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
//邻接边
typedef struct EdgeNode
{
	int adjvex;
	int weight;
	struct EdgeNode* nextEdge;
}EdgeNode;

//定点表结点
typedef struct VertexNode
{
	char data;
	EdgeNode* firstEdge;
}VertexNode, Adjust[100];

typedef struct
{
	Adjust vertex;
	int numNodes, numEdges;
}AdjGraph;

//有向图
void CreatAlGraph(AdjGraph* G, char data[])
{
	int i, j;
	EdgeNode* pe;
	G->numNodes = 5;
	G->numEdges = 6;

	for (i = 0; i < G->numNodes; i++)
	{
		G->vertex[i].data = data[i];
		G->vertex[i].firstEdge = NULL; /* 将边表置为空表 */
	}

	//A->B
	i = 0; j = 1;
	pe = (EdgeNode*)malloc(sizeof(EdgeNode));
	pe->adjvex = j; /* 邻接序号为j */
	pe->nextEdge = G->vertex[i].firstEdge; /* 将pe的指针指向当前顶点上指向的结点 */
	G->vertex[i].firstEdge = pe; /* 将当前顶点的指针指向pe */
	//A-D
	i = 0; j = 3;
	pe = (EdgeNode*)malloc(sizeof(EdgeNode));
	pe->adjvex = j; /* 邻接序号为j */
	pe->nextEdge = G->vertex[i].firstEdge; /* 将pe的指针指向当前顶点上指向的结点 */
	G->vertex[i].firstEdge = pe; /* 将当前顶点的指针指向pe */
	//A->E
	i = 0; j = 4;
	pe = (EdgeNode*)malloc(sizeof(EdgeNode));
	pe->adjvex = j; /* 邻接序号为j */
	pe->nextEdge = G->vertex[i].firstEdge; /* 将pe的指针指向当前顶点上指向的结点 */
	G->vertex[i].firstEdge = pe; /* 将当前顶点的指针指向pe */
	//B->C
	i = 1; j = 2;
	pe = (EdgeNode*)malloc(sizeof(EdgeNode));
	pe->adjvex = j; /* 邻接序号为j */
	pe->nextEdge = G->vertex[i].firstEdge; /* 将pe的指针指向当前顶点上指向的结点 */
	G->vertex[i].firstEdge = pe; /* 将当前顶点的指针指向pe */
	//D->E
	i = 3; j = 4;
	pe = (EdgeNode*)malloc(sizeof(EdgeNode));
	pe->adjvex = j; /* 邻接序号为j */
	pe->nextEdge = G->vertex[i].firstEdge; /* 将pe的指针指向当前顶点上指向的结点 */
	G->vertex[i].firstEdge = pe; /* 将当前顶点的指针指向pe */
	//E->C
	i = 4; j = 2;
	pe = (EdgeNode*)malloc(sizeof(EdgeNode));
	pe->adjvex = j; /* 邻接序号为j */
	pe->nextEdge = G->vertex[i].firstEdge; /* 将pe的指针指向当前顶点上指向的结点 */
	G->vertex[i].firstEdge = pe; /* 将当前顶点的指针指向pe */
}
//无向图
void CreatAlGraph2(AdjGraph* G, char data[])
{
	int i, j;
	EdgeNode* pe;
	G->numNodes = 5;
	G->numEdges = 14;

	for (i = 0; i < G->numNodes; i++)
	{
		G->vertex[i].data = data[i];
		G->vertex[i].firstEdge = NULL; /* 将边表置为空表 */
	}
	//A-B
	i = 0; j = 1;
	pe = (EdgeNode*)malloc(sizeof(EdgeNode));
	pe->adjvex = j;
	pe->nextEdge = G->vertex[i].firstEdge;
	G->vertex[i].firstEdge = pe;
	i = 1; j = 0;
	pe = (EdgeNode*)malloc(sizeof(EdgeNode));
	pe->adjvex = j;
	pe->nextEdge = G->vertex[i].firstEdge;
	G->vertex[i].firstEdge = pe;
	//A-D
	i = 0; j = 3;
	pe = (EdgeNode*)malloc(sizeof(EdgeNode));
	pe->adjvex = j;
	pe->nextEdge = G->vertex[i].firstEdge;
	G->vertex[i].firstEdge = pe;
	i = 3; j = 0;
	pe = (EdgeNode*)malloc(sizeof(EdgeNode));
	pe->adjvex = j;
	pe->nextEdge = G->vertex[i].firstEdge;
	G->vertex[i].firstEdge = pe;
	//D-B
	i = 1; j = 3;
	pe = (EdgeNode*)malloc(sizeof(EdgeNode));
	pe->adjvex = j;
	pe->nextEdge = G->vertex[i].firstEdge;
	G->vertex[i].firstEdge = pe;
	i = 3; j = 1;
	pe = (EdgeNode*)malloc(sizeof(EdgeNode));
	pe->adjvex = j;
	pe->nextEdge = G->vertex[i].firstEdge;
	G->vertex[i].firstEdge = pe;
	//B-C
	i = 1; j = 2;
	pe = (EdgeNode*)malloc(sizeof(EdgeNode));
	pe->adjvex = j;
	pe->nextEdge = G->vertex[i].firstEdge;
	G->vertex[i].firstEdge = pe;
	i = 2; j = 1;
	pe = (EdgeNode*)malloc(sizeof(EdgeNode));
	pe->adjvex = j;
	pe->nextEdge = G->vertex[i].firstEdge;
	G->vertex[i].firstEdge = pe;
	//B-E
	i = 1; j = 4;
	pe = (EdgeNode*)malloc(sizeof(EdgeNode));
	pe->adjvex = j;
	pe->nextEdge = G->vertex[i].firstEdge;
	G->vertex[i].firstEdge = pe;
	i = 4; j = 1;
	pe = (EdgeNode*)malloc(sizeof(EdgeNode));
	pe->adjvex = j;
	pe->nextEdge = G->vertex[i].firstEdge;
	G->vertex[i].firstEdge = pe;
	//D-E
	i = 3; j = 4;
	pe = (EdgeNode*)malloc(sizeof(EdgeNode));
	pe->adjvex = j;
	pe->nextEdge = G->vertex[i].firstEdge;
	G->vertex[i].firstEdge = pe;
	i = 4; j = 3;
	pe = (EdgeNode*)malloc(sizeof(EdgeNode));
	pe->adjvex = j;
	pe->nextEdge = G->vertex[i].firstEdge;
	G->vertex[i].firstEdge = pe;
	//E-C
	i = 2; j = 4;
	pe = (EdgeNode*)malloc(sizeof(EdgeNode));
	pe->adjvex = j;
	pe->nextEdge = G->vertex[i].firstEdge;
	G->vertex[i].firstEdge = pe;
	i = 4; j = 2;
	pe = (EdgeNode*)malloc(sizeof(EdgeNode));
	pe->adjvex = j;
	pe->nextEdge = G->vertex[i].firstEdge;
	G->vertex[i].firstEdge = pe;
}
void DFS(AdjGraph* G, int v, int visited[])
{
	EdgeNode* e = G->vertex[v].firstEdge;
	visited[v] = true;
	cout << G->vertex[v].data << " ";
	while (e)
	{
		if (visited[e->adjvex] == false)
		{
			DFS(G, e->adjvex, visited);
		}
		e = e->nextEdge;
	}
}
void DFSTraver(AdjGraph* G)
{
	int visited[100];
	for (int i = 0; i < 100; i++)visited[i] = false;
	for (int j = 0; j < G->numNodes; j++)
	{
		if (visited[j] == false)
		{
			DFS(G, j, visited);
		}
	}
}

//计算所有顶点的入度
void DFS2(AdjGraph* G, int vi, int visited[], int& a)
{
	visited[vi] = true;
	EdgeNode* e = G->vertex[vi].firstEdge;
	while (e)
	{
		a++;
		if (visited[e->adjvex] == false)
		{
			DFS2(G, e->adjvex, visited, a);
		}
		e = e->nextEdge;
	}
}
//计算所有顶点的入度
int inDegree(AdjGraph* G)
{
	int visited[100];
	for (int i = 0; i < G->numNodes; i++)visited[i] = false;
	int inNums = 0;
	for (int j = 0; j < G->numNodes; j++)
	{
		if (visited[j] == false)
		{
			DFS2(G, j, visited, inNums);
		}
	}
	return inNums;
}
//判断顶点vi到vj是否有路径
int Q[1024];
int front, rear;
void BFS(AdjGraph G, int vi, int visited[])
{
	visited[vi] = true;
	EdgeNode* p = G.vertex[vi].firstEdge;

	while (p)
	{
		if (visited[p->adjvex] == false)
		{
			Q[++rear] = p->adjvex;
			visited[p->adjvex] = true;
		}
		p = p->nextEdge;
	}
}
bool HasPathBFS(AdjGraph G, int vi, int vj)
{
	if (vi<0 || vj <0 || vi >G.numNodes || vj > G.numNodes)return false;
	int visited[1024];
	for (int i = 0; i < G.numNodes; i++)
	{
		visited[i] = false;
	}
	front = -1; rear = -1;
	Q[++rear] = vi;
	while (front < rear)
	{
		int next = Q[++front];
		BFS(G, next, visited);
	}
	return visited[vj];
}
//输出从顶点Vi到Vj的所有简单路径
void FindPath(AdjGraph* G, int v, int u, int visited[], int path[], int d)
{
	visited[v] = true;
	EdgeNode* p = G->vertex[v].firstEdge;
	path[d++] = v;
	if (u == v)
	{
		for (int i = 0; i < d; i++)
		{
			cout << G->vertex[path[i]].data << " ";
		}
		cout << endl;
		//输出路径
	}
	while (p)
	{
		if (visited[p->adjvex] == false)
		{
			FindPath(G, p->adjvex, u, visited, path, d);
		}
		p = p->nextEdge;
	}
	visited[v] = false;
}
void FindPathDFS(AdjGraph* G, int vi, int vj)
{
	int visited[1024];
	int path[1024];
	for (int i = 0; i < G->numNodes; i++)
	{
		visited[i] = false;
	}
	FindPath(G, vi, vj, visited, path, 0);
}

#pragma region 求无向无权连通图中距离顶点v的最短路径长度为k的所有结点
void Find0(AdjGraph* G, int v, int k)
{
	if (G == NULL)return;
	if (k <= 0)return;
	int visited[1024];
	for (int i = 0; i < G->numNodes; i++)
	{
		visited[i] = false;
	}
	visited[v] = true;
	int level = 0;
	queue<int> Q;
	queue<int> L;
	Q.push(v);
	L.push(level);

	while (!Q.empty() && level <= k)
	{
		int curr = Q.front();
		level = L.front();
		if (level == k)
		{
			while (!Q.empty())
			{
				cout << G->vertex[Q.front()].data << " ";
				Q.pop();
			}
			return;
		}
		Q.pop();
		L.pop();
		EdgeNode* p = G->vertex[curr].firstEdge;
		while (p)
		{
			if (visited[p->adjvex] == false)
			{
				Q.push(p->adjvex);
				L.push(level + 1);
				visited[p->adjvex] = true;
			}
			p = p->nextEdge;
		}
	}
}
#pragma endregion
#pragma region 求图中顶点vi到顶点vj的一条最短路径
void BFS4(AdjGraph* G, int vi, int vj)
{
	if (G == NULL)return;
	int visited[1024], d[1024], Q[1024];
	int f = -1, r = -1;
	for (int i = 0; i < G->numNodes; i++)
	{
		visited[i] = false;
		d[i] = -1;
	}
	visited[vi] = true;
	d[vi] = 0;
	Q[++r] = vi;
	while (f < r)
	{
		int n = Q[++f];
		cout << G->vertex[n].data << " ";
		EdgeNode* p = G->vertex[n].firstEdge;
		while (p)
		{
			if (visited[p->adjvex] == false)
			{
				d[p->adjvex] = d[n] + 1;
				Q[++r] = p->adjvex;
				visited[p->adjvex] = true;
			}
			p = p->nextEdge;
		}
	}
	cout << d[vj] << endl;
}
#pragma endregion


int main()
{
	AdjGraph G;
	char data[5] = { 'A','B','C','D','E' };
	CreatAlGraph(&G, data);
	//CreatAlGraph2(&G, data);
	//DFSTraver(&G);
	//cout << inDegree(&G);
	//cout << HasPathBFS(G, 2, 3);
	//FindPathDFS(&G, 0, 2);
	//Find0(&G, 4, 1);
	BFS4(&G, 0, 1);
	BFS4(&G, 0, 2);
	BFS4(&G, 0, 3);
	BFS4(&G, 0, 4);
	return 0;
}