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
void ListOppose(LinkList &L)
{   // ������ͷ�ڵ�ĵ���������
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
{   // �ϲ��������������� A, B ��һ�������������� C
    LinkList p, q, s, qa;//p��q�ֱ���ָ��A��B 
	p = A->next;
	q = B->next;
	qa = A;//qa�����Ҳ���λ��
	C = A;
	while (p&&q)
		if (p->data > q->data) {//p��q����pָ����һ�����
			p = p->next;
			qa = qa->next;
		}
		else {//p��qС����q�Ľ������A��
			s = q;
			q = q->next;
			s->next = qa->next;
			qa->next = s;
			qa = qa->next;
		}
//	if(!p){
//		s=q;
//		q= q->next;
//		s->next=NULL;
//		qa->next=s;
//	}
    free(B);   // �ͷ� B �����ͷ���
}//ListMerge
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

    // ����
    	ListOppose(A);
    	ListOppose(B);
	DispList(A);
	DispList(B);
    // �鲢
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
