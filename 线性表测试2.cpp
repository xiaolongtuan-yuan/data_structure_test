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
}LNode, *LinkList;//����ṹ
 
void InitList(LinkList &L)
{   // ��ʼ�������� L
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
 
}//InitList
void CreateList(LinkList &L, int e)
{   // ���������� L
    LinkList p = L;
    while(p->next)
        p = p->next;
    LinkList temp = (LinkList)malloc(sizeof(LNode));
    temp->data = e;
    temp->next = NULL;
    p->next = temp;
 
}//CreateList
void DispList(LinkList &L)
{   // ��ӡ������ L
    LinkList p = L->next;
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}//DispList
void ListCombine(LinkList &A,LinkList &B,LinkList &C){
LinkList pa,p,q,t;//pa��ָ��pǰ��һ������ָ�룬�����Ҳ���λ�ã�p��q�ֱ�����ָ��AB�����еĽ�㣬t���ڸ���bҪ����Ľ�� 
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
}//��m>=nʱ������β���Զ�Ϊan+1, ��,am
if(q){//m<=n��Ҫ��B��ʣ��Ľ���ƶ���A��ĩβ;
p->next=q;
}
}
int main()
{
	int m;
	int **b;
	int *a; 
	scanf("%d",&m);
	a=(int*)malloc(sizeof(int)*m*2);//���ڴ�ÿ������ĳ���	
	b=(int**)malloc(sizeof(int*)*m*2);	
//��ά����治ͬ������ 	
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
}//¼����һ������
	for (int i = 0; i < m; i++){
	int g=2*i;
	int h=2*i+1;
    LinkList A, B, C;
    InitList(A);    InitList(B);
    for(int j = 0; j< a[g]; j++){
        CreateList(A, b[g][j]);}
    for(int j = 0; j < a[h]; j++){
        CreateList(B, b[h][j]);}

    // �鲢
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
