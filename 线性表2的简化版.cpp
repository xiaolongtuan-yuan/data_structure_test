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
void ListOppose(LinkList &L)
{   // ������ͷ�ڵ�ĵ���������
    LinkList q, p, s;
    p = L;
    p = p->next;//�������������������ϰѵڶ�������ĵ�һ�����ݷŵ���һ���������ǰ��
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
	int m,a,b;//m������a��һ�����ݶ��룬b�ڶ������ݶ���
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
    // �鲢
    ListCombine(A, B, C);
    DispList(C);
    printf("\n");
	}
    return 0;
}
