#include<stdio.h>
#include<malloc.h>
#include<string>
#include<iostream>
using namespace std;
typedef struct Lnode {
	string  name;
	Lnode *next;//定义指向结构的指针
}Lnode, *Linklist;//该结构的指针
//查找
void Initlist(Linklist &L)
{   // 初始化单链表 L
    L = (Linklist)malloc(sizeof(Lnode));
    L->next = NULL;
 
}//Initlist
void Createlist(Linklist &L, string x)
{   // 创建单链表 L
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
		cout<<"error!"<<endl;//!p即i太大超出L长度，最终p指向空地址null,但是可以在最后一个的后面插一个数
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
	}//找到要打印的第一个城市 
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
	printf("第三个城市是：");
	cout<< Getname(L,3)<<endl;
	ListInsert_L(L,3,"chengdu");
	cout<<"第三个城市是：";
	cout<< Getname(L,3)<<endl;
	Showlist(L);
	ListDelete_L(L,4);
	Showlist(L);
	cout<<"距离第三城市距离小于等于2的城市有：";
	showcitys(L,3,2);	 
	return 0;
}





