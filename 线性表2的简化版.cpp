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
void ListCombine(LinkList &A,LinkList &B,LinkList &C){
LinkList pa,p,q,t;//pa是指向p前面一个结点的指针，用于找插入位置，p和q分别用于指向AB进行中的结点，t用于复制b要插入的结点 
p=A->next;
q=B->next;
pa=p->next;
C=A;
while(pa&&q){
t=q;
q=q->next;
t->next=p->next;
p->next=t;
p=pa;
pa=pa->next;
}//当m>=n时，数列尾部自动为an+1, …,am
if(q){//m<=n，要把B链剩余的结点移动到A链末尾;
p->next=q;
}
}
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
    // 归并
    ListCombine(A, B, C);
    DispList(C);
    printf("\n");
	}
    return 0;
}
