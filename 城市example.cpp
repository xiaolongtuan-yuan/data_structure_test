#include<stdio.h>
#include<malloc.h>
#include<string>
#include<iostream>
#include<cstring>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef struct Lnode {
	char name[10];
	int x;
	int y;
	Lnode *next;//定义指向结构的指针
}Lnode, *Linklist;//该结构的指针
//查找
void Initlist(Linklist &L)
{   // 初始化单链表 L
	L = (Linklist)malloc(sizeof(Lnode));
	L->next = NULL;

}//Initlist
void addcity(Linklist &L)
{   // 创建单链表 L
	Linklist p = L;
	while (p->next)
		p = p->next;
	Linklist temp = (Linklist)malloc(sizeof(Lnode));
	cout << "请依次输入名称和x，y坐标" << endl;
	scanf("%s", &(temp->name));
	cin >> temp->x;
	cin>>temp->y;
	temp->next = NULL;
	p->next = temp;
}//CreateList
void citydelete_L(Linklist &L) {//用p指向与要删的城市，删去p
	char x[10];
	scanf("%s", &x);
	Linklist p = L->next;
	Linklist s = L;
	while (p || !(strcmp(p->name, x))) {
		p = p->next;
		s = s->next;
	}
	s->next = p->next;
	free(p);
}
void showcitys(Linklist &L) {//输出链表中所有城市
	int i = 0;
	Linklist p = L->next;
	while (p) {
		cout << p->name << " ";
		p = p->next;
	}
	cout << endl;
}
void nearcitys(Linklist &L, int x, int y,int dis) {//查找与（x，y）距离小于等于dis的城市
	Linklist p = L->next;
	while (p) {
		int sum = ((p->x - x)*(p->x - x) + (p->y - y)*(p->y - y));
		if (sum <= (dis*dis))
			cout << p->name << " ";
	}
	cout << endl;
}
void findcity(Linklist &L) {//输出城市坐标
	Linklist p = L->next;	
	char city[10];
	cout << "请输入要查找的城市：" << endl;
	scanf("%s", &city);
	while (!(strcmp(p->name,city))) {
		p = p->next;
	}
	cout << "(" << p->x << "," << p->y << ")" << endl;
}
int main() {
	Linklist L;
	Initlist(L);
	int m;
	cout << "写入城市的数量:"<<endl;
	cin >> m;
	for (int i = 0; i < m; i++) {
		addcity(L);
	}//向链表中添加m个城市
	showcitys(L);
	findcity(L);
	cout << "请输入你的坐标，以及查找的距离（整数）:"<<endl;
	int x;
	cin >> x;
	int y;
	cin >> y;
	int dis;
	cin >> dis;
	nearcitys(L, x, y, dis);
	cout << "你要删除哪座城市:" << endl;
	citydelete_L(L);
	return 0;
}





