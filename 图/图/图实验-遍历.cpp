#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<vector>
#include <utility>
using namespace std;
typedef char DataType;
#define maxnum 30
typedef struct AdjVNode {
	int Adjv;//邻接点下标
	int Weight = 0;//边权重
	AdjVNode *next;//指向下一个结点
}AdjVNode, *PtrToAdjVNode;
typedef struct Vnode {
	PtrToAdjVNode FirstEdge;
	DataType Data;//顶点的数据
}AdjList[maxnum];
typedef struct GNode {
	int Nv;//顶点数
	int NE;//边数
	AdjList G;//邻接表
}LGreph, *PtrToGNode;


PtrToGNode creatGreph(int num, int edgenum) {
	PtrToGNode Gr = (PtrToGNode)malloc(sizeof(GNode));
	Gr->Nv = num;
	Gr->NE = edgenum;
	for (int v = 0; v < Gr->Nv; v++) {
		Gr->G[v].FirstEdge = NULL;
	}
	return Gr;//返回一个指向图的指针
}
PtrToGNode shuru(int v, int w) {//v是顶点数，w是边数
	PtrToGNode Gr = creatGreph(v,w);
	cout << "请依次输入顶点的值：" << endl;
	for (int x = 0; x < v; x++) {
		cin >> Gr->G[x].Data;
	}
	cout << "请依次输入边:" << endl;
	for (int u = 0; u < w; u++) {
		pair<int, int>edge;
		cin >> edge.first >> edge.second;
		PtrToAdjVNode p = (PtrToAdjVNode)malloc(sizeof(AdjVNode));
		p->Adjv = edge.second;
		p->next = Gr->G[edge.first].FirstEdge;
		Gr->G[edge.first].FirstEdge = p;
		PtrToAdjVNode p2 = (PtrToAdjVNode)malloc(sizeof(AdjVNode));
		p2->Adjv = edge.first;
		p2->next = Gr->G[edge.second].FirstEdge;
		Gr->G[edge.second].FirstEdge = p2;
	}
	return Gr;
	/*
	for (Vnode &x : Gr->G) {
		cout << "请输入第一个结点的出度：" << endl;
		int m;//出度
		cin >> m;
		if (m == 0)x.FirstEdge = NULL;
		else{
			PtrToAdjVNode p = (PtrToAdjVNode)malloc(sizeof(AdjVNode));
			cin >> p->Adjv;
			p->Weight = 0;
			x.FirstEdge = p;
		}
		for (int n = 1; n < m; n++) {
			PtrToAdjVNode p = (PtrToAdjVNode)malloc(sizeof(AdjVNode));
			cin >> p->Adjv;
			p->Weight = 0;

		}
	}*/
}
vector<pair<int, int>>tre;//dfs生成树的边
bool* visited = new bool[maxnum];
vector<char>shuchu;
int FirstAdjvex(PtrToGNode Gr, int v) {
	if (!Gr->G[v].FirstEdge)
		return 0;
	else return(Gr->G[v].FirstEdge->Adjv);
}
int NextAdjvex(PtrToGNode Gr, int v, int w) {
	PtrToAdjVNode p = Gr->G[v].FirstEdge;
	while (p&&p->Adjv != w)p = p->next;
	if (p->Adjv == w && p->next)return(p->next->Adjv);
	else return(0);
}
void DFS(PtrToGNode Gr, int v) {
	visited[v] = true;
	shuchu.push_back(Gr->G[v].Data);
	for (int w = FirstAdjvex(Gr, v); w > 0; w = NextAdjvex(Gr, v, w)) {
		if (!visited[w]) {
			tre.push_back(make_pair(v, w));
			DFS(Gr, w);
		}
	}
	return;
}
void DFSTraverse(PtrToGNode Gr) {

	for (int v = 0; v < Gr->Nv; v++)visited[v] = false;
	for (int v = 0; v < Gr->Nv; v++) {
		if (!visited[v])
			DFS(Gr, v);
	}
	return;
}


vector<pair<int, int>>tre2;//BFS生成树边
vector<char>shuchu2;
void BFSTraverse(PtrToGNode Gr) {
	int temp = 0;
	for (int i = 0; i < Gr->Nv; i++)visited[i] = false;
	queue<int>Q;
	for (int v = 0; v < Gr->Nv; v++) {
		if (!visited[v]) {
			visited[v] = true;
			shuchu2.push_back(Gr->G[v].Data);
			Q.push(v);
			while (!Q.empty()) {
				temp = Q.front(); Q.pop();
				for (int w = FirstAdjvex(Gr, temp); w > 0; w = NextAdjvex(Gr, temp, w)) {
					if (!visited[w]) {
						tre2.push_back(make_pair(temp, w));
						visited[w] = true;
						shuchu2.push_back(Gr->G[w].Data);
						Q.push(w);
					}
				}
			}

		}
	}
}
int main() {
	cout << "请输入顶点个数：" << endl;
	int vex;
	cin >> vex;
	cout << "请输入边个数：" << endl;
	int edg;
	cin >> edg;
	PtrToGNode Graph = shuru(vex, edg);
	
	DFSTraverse(Graph);
	for (char i : shuchu) {
		cout << i << " ";
	}
	cout << endl;
	for (pair<int, int>j : tre) {
		cout << j.first << " " << j.second << endl;
	}
	BFSTraverse(Graph);
	for (char i : shuchu2) {
		cout << i << " ";
	}cout << endl;
	for (pair<int, int>j : tre2) {
		cout << j.first << " " << j.second << endl;
	}
	return 0;
}



