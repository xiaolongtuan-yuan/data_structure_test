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

    // 归并
    ListCombine(A, B, C);
    DispList(C);
    printf("\n");
	}
	for(int i=0;i<m*2;i++)
	free(b[i]);
	free(a);
	free(b);
 
    return OK;
} 
