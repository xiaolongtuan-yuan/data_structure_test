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
}LNode, *LinkList;
 
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
    p = p->next;
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
		else {//p比q小，则将q的结点插入大A中
			s = q;
			q = q->next;
			s->next = qa->next;
			qa->next = s;
			qa = qa->next;
		}
		if(!p){
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
	int m;
	int **b;
	int *a; 
	scanf("%d",&m);
	a=(int*)malloc(sizeof(int)*m*2);//用于存每个数组的长度	
	b=(int**)malloc(sizeof(int*)*m*2);	
//二维数组存不同的数组 	
	for(int k=0;k<m;k++){
		int g=2*k;
		int h=2*k+1;
		scanf("%d",&a[g]);
		scanf("%d",&a[h]);
		b[g]=(int*)malloc(sizeof(int)*a[g]);
		b[h]=(int*)malloc(sizeof(int)*a[h]);
		for(int j=0;j<a[g];j++){
			scanf("%d",&b[g][j]);
	}
		for(int j=0;j<a[h];j++){
			scanf("%d",&b[h][j]);
	}
}//录入了一组数据
	for (int i = 0; i < m; i++){
	int g=2*i;
	int h=2*i+1;
    LinkList A, B, C;
    InitList(A);    InitList(B);
    for(int j = 0; j< a[g]; j++){
        CreateList(A, b[g][j]);}
    for(int j = 0; j < a[h]; j++){
        CreateList(B, b[h][j]);}

    // 逆置
    ListOppose(A);
    ListOppose(B);
    // 归并
    ListMerge(A, B, C);
    DispList(C);
    printf("\n");
	}
	for(int i=0;i<m*2;i++)
	free(b[i]);
	free(a);
	free(b);
 
    return OK;
}
