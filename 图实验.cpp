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
	int Adjv;//�ڽӵ��±�
	int Weight = 0;//��Ȩ��
	AdjVNode *next;//ָ����һ�����
}AdjVNode,*PtrToAdjVNode;
typedef struct Vnode {
	PtrToAdjVNode FirstEdge;
	DataType Data;//���������
}AdjList[maxnum];
typedef struct GNode {
	int Nv;//������
	int NE;//����
	AdjList G;//�ڽӱ�
}LGreph,*PtrToGNode;


PtrToGNode creatGreph(int num,int edgenum) {
	PtrToGNode Gr = (PtrToGNode)malloc(sizeof(GNode));
	Gr->Nv = num;
	Gr->NE = edgenum;
	for (int v = 0; v < Gr->Nv; v++) {
		Gr->G[v].FirstEdge = NULL;
	}
	return Gr;//����һ��ָ��ͼ��ָ��
}
void shuru(int v,int w) {//v�Ƕ�������w�Ǳ���
	PtrToGNode Gr = creatGreph(v��w);
	cout << "���������붥���ֵ��" << endl;
		for (int x = 0; x < v; x++) {
			cin >> Gr->G[x].Data;
		}
		cout << "�����������:" << endl;
		for (int u = 0; u < w; u++) {
			pair<int, int>edge;
			cin >> edge.first >> edge.second;
			PtrToAdjVNode p = (PtrToAdjVNode)malloc(sizeof(AdjVNode));
			p->Adjv = edge.second;
			p->next = Gr->G[edge.first].FirstEdge;
			Gr->G[edge.first].FirstEdge = p;
		}
		/*
		for (Vnode &x : Gr->G) {
			cout << "�������һ�����ĳ��ȣ�" << endl;
			int m;//����
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
vector<pair<int, int>>tre;//dfs�������ı�
bool* visited = new bool[maxnum];
vector<char>shuchu;
void DFSTraverse(PtrToGNode Gr) {

	for (int v = 0; v < Gr->Nv; v++)visited[v] = false;
	for (int v = 0; v < Gr->Nv; v++) {
		if (!visited[v])
			DFS(Gr,v);
	}
}
void DFS(PtrToGNode Gr,int v) {
	visited[v] = true;
	shuchu.push_back(Gr->G[v].Data);
	for (int w = FirstAdjvex(Gr, v); w > 0; w = NextAdjvex(Gr, v, w)) {
		if (!visited[w]) { 
			tre.push_back(make_pair(v,w));
			DFS(Gr, w); 
		}
	}
}
int FirstAdjvex(PtrToGNode Gr, int v) {
	if(!Gr->G[v].FirstEdge)
	return 0;
	else return(Gr->G[v].FirstEdge->Adjv);
}
int NextAdjvex(PtrToGNode Gr, int v, int w) {
	PtrToAdjVNode p = Gr->G[v].FirstEdge;
	while (p&&p->Adjv != w)p = p->next;
	if (p->Adjv == w && p->next)return(p->next->Adjv);
	else return(0);
}
vector<pair<int, int>>tre2;//BFS��������
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
			while (!Q.empty) {
				temp = Q.front(); Q.pop();
				for (int w = FirstAdjvex(Gr, temp); w > 0; w = NextAdjvex(Gr, temp, w)) {
					if (!visited[w]) {
						tre2.push_back(make_pair(temp, w));
						visited[w] = true;
						shuchu2.push_back(Gr->G[w].Data);
					}
				}
			}

		}
	}
}


  

