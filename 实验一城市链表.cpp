#include<stdio.h>
#include<malloc.h>
#include<string>
#include<iostream>
using namespace std;
typedef struct Lnode {
	string  name;
	Lnode *next;//����ָ��ṹ��ָ��
}Lnode, *Linklist;//�ýṹ��ָ��
//����
void Initlist(Linklist &L)
{   // ��ʼ�������� L
    L = (Linklist)malloc(sizeof(Lnode));
    L->next = NULL;
 
}//Initlist
void Createlist(Linklist &L, string x)
{   // ���������� L
    Linklist p = L;
    while(p->next)
        p = p->next;
    Linklist temp = (Linklist)malloc(sizeof(Lnode));
    temp->name = x;
    temp->next = NULL;
    p->next = temp;
 }//CreateList
string Getname(Linklist L, int i) {
	Linklist p=L;
	int j=0;
	while (p&&j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i)
		cout<<"error!"<<endl;
	return p->name;
}
void ListInsert_L(Linklist &L, int i,string e) {
	Linklist p = L,s;
	int j=0;
	while (p&&j < i-1) {
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)
		cout<<"error!"<<endl;//!p��i̫�󳬳�L���ȣ�����pָ��յ�ַnull,���ǿ��������һ���ĺ����һ����
	s = (Lnode *)malloc(sizeof(Lnode));
	s->name = e;
	s->next = p->next;
	p->next = s;
}
void ListDelete_L(Linklist &L, int i) {
	Linklist p = L,s;
	int j=0;
	while (p&&j < i - 1) {
		p = p->next;
		j++;
	}
	if (!(p->next)|| j > i - 1)
		cout<<"error!"<<endl;
	s = p->next;
	p->next = s->next;
	free(s);
}
void Showlist(Linklist L) {
	int i = 0;
	Linklist p = L;
	while (!p) {
		cout<<p->name<<" ";
		p = p->next;
	}
	cout<<endl;
}
void showcitys(Linklist L,int x,int y){
	Linklist p=L,s;
	int i=0,j=0;
	if(x<=y)
	while (p&&j < x+y) {
		cout<<p->name<<" ";
		j++;
	}
	else{
		while (p&& j<(x-y)) {
		p = p->next;
		j++;
	}//�ҵ�Ҫ��ӡ�ĵ�һ������ 
	while(p&&i < 2*y){
		cout<<p->name<<" ";
	}
	}
	cout<<endl;
}
int foundsite(Linklist L,string s){
	Linklist p=L;
	int i=0;
	while(p||p->name==s){
		p=p->next;
		i++;
	}
	return i;
}
int main() {
	Linklist L;
	Initlist(L);
	Createlist(L,"beijin");
	Createlist(L,"wuhan");
	Createlist(L,"nanjin");
	Createlist(L,"shanghai");
	Createlist(L,"xiamen");
	Createlist(L,"hangzhou");
	printf("�����������ǣ�");
	cout<< Getname(L,3)<<endl;
	ListInsert_L(L,3,"chengdu");
	cout<<"�����������ǣ�";
	cout<< Getname(L,3)<<endl;
	Showlist(L);
	ListDelete_L(L,4);
	Showlist(L);
	cout<<"����������о���С�ڵ���2�ĳ����У�";
	showcitys(L,3,2);	 
	return 0;
}





