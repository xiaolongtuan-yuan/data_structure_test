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
	Lnode *next;//����ָ��ṹ��ָ��
}Lnode, *Linklist;//�ýṹ��ָ��
//����
void Initlist(Linklist &L)
{   // ��ʼ�������� L
	L = (Linklist)malloc(sizeof(Lnode));
	L->next = NULL;

}//Initlist
void addcity(Linklist &L)
{   // ���������� L
	Linklist p = L;
	while (p->next)
		p = p->next;
	Linklist temp = (Linklist)malloc(sizeof(Lnode));
	cout << "�������������ƺ�x��y����" << endl;
	scanf("%s", &(temp->name));
	cin >> temp->x;
	cin>>temp->y;
	temp->next = NULL;
	p->next = temp;
}//CreateList
void citydelete_L(Linklist &L) {//��pָ����Ҫɾ�ĳ��У�ɾȥp
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
void showcitys(Linklist &L) {//������������г���
	int i = 0;
	Linklist p = L->next;
	while (p) {
		cout << p->name << " ";
		p = p->next;
	}
	cout << endl;
}
void nearcitys(Linklist &L, int x, int y,int dis) {//�����루x��y������С�ڵ���dis�ĳ���
	Linklist p = L->next;
	while (p) {
		int sum = ((p->x - x)*(p->x - x) + (p->y - y)*(p->y - y));
		if (sum <= (dis*dis))
			cout << p->name << " ";
	}
	cout << endl;
}
void findcity(Linklist &L) {//�����������
	Linklist p = L->next;	
	char city[10];
	cout << "������Ҫ���ҵĳ��У�" << endl;
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
	cout << "д����е�����:"<<endl;
	cin >> m;
	for (int i = 0; i < m; i++) {
		addcity(L);
	}//�����������m������
	showcitys(L);
	findcity(L);
	cout << "������������꣬�Լ����ҵľ��루������:"<<endl;
	int x;
	cin >> x;
	int y;
	cin >> y;
	int dis;
	cin >> dis;
	nearcitys(L, x, y, dis);
	cout << "��Ҫɾ����������:" << endl;
	citydelete_L(L);
	return 0;
}





