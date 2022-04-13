#include<stdio.h>
#include<stdlib.h>
 
#define OK 1
#define ERROR 0
 
typedef int ElemType;
typedef int Status;
 
typedef struct LNode
{
    ElemType data;
    LNode *next;
}LNode, *LinkList;//链表结构
 
void InitList(LinkList &L)
{   // 初始化单链表 L
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
 
}//InitList
void CreateList(LinkList &L, int e)
{   // 创建单链表 L
    LinkList p = L;
    while(p->next)
        p = p->next;
    LinkList temp = (LinkList)malloc(sizeof(LNode));
    temp->data = e;
    temp->next = NULL;
    p->next = temp;
 
}//CreateList
void DispList(LinkList &L)
{   // 打印单链表 L
    LinkList p = L->next;
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}//DispList
void ListOppose(LinkList &L)
{   // 将带表头节点的单链表逆置
    LinkList q, p, s;
    p = L;
    p = p->next;//将链表拆成两个链表，不断把第二个链表的第一个数据放到第一个链表的最前面
    L->next = NULL;
    while(p)
    {
        q = p;
        p = p->next;
        q->next = L->next;
        L->next = q;
    }
}//ListOppose
void ListMerge(LinkList &A, LinkList &B, LinkList &C)
{   // 合并两个递增单链表 A, B 成一个递增有序单链表 C
    LinkList p, q, s, qa;
	p = A->next;
	q = B->next;
	qa = A;//qa用于找插入位置
	C = A;
	while (p&&q)
		if (p->data > q->data) {//p比q大，则将p指向下一个结点
			p = p->next;
			qa = qa->next;
		}
		else {//p比q小或相等情况，则将q的结点插入大A中,且p的位置不用动 
			s = q;
			q = q->next;
			s->next = qa->next;
			qa->next = s;
			qa = qa->next;
		}
		if(!p){//如果是A链先空，则将剩余B链全部接到A链尾部
		while(q){
		s=q;
		q= q->next;
		s->next=qa->next;
		qa->next=s;
		qa = qa->next;
		}
	}
    free(B);    // 释放 B 链表的头结点
 
}//ListMerge
int main()
{
	int m,a,b;//m组数，a第一组数据读入，b第二组数据读入
	scanf("%d",&m); 
	int x,y; 
	for (int i = 0; i < m; i++){
		scanf("%d%d",&x,&y);
    	LinkList A, B, C;
    	InitList(A);    InitList(B);
    	for(int j = 0; j< x; j++){
    		scanf("%d",&a);
       		CreateList(A, a);}  
    	for(int j = 0; j < y; j++){
    		scanf("%d",&b);
        	CreateList(B, b);}
    // 逆置
    ListOppose(A);
    ListOppose(B);
    // 归并
    ListMerge(A, B, C);
    DispList(C);
    printf("\n");
	}
    return 0;
}
