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
void ListMerge(LinkList &A, LinkList &B, LinkList &C)
{   // �ϲ��������������� A, B ��һ�������������� C
    LinkList p, q, s, qa;
	p = A->next;
	q = B->next;
	qa = A;//qa�����Ҳ���λ��
	C = A;
	while (p&&q)
		if (p->data > q->data) {//p��q����pָ����һ�����
			p = p->next;
			qa = qa->next;
		}
		else {//p��qС������������q�Ľ������A��,��p��λ�ò��ö� 
			s = q;
			q = q->next;
			s->next = qa->next;
			qa->next = s;
			qa = qa->next;
		}
		if(!p){//�����A���ȿգ���ʣ��B��ȫ���ӵ�A��β��
		while(q){
		s=q;
		q= q->next;
		s->next=qa->next;
		qa->next=s;
		qa = qa->next;
		}
	}
    free(B);    // �ͷ� B �����ͷ���
 
}//ListMerge
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
    // ����
    ListOppose(A);
    ListOppose(B);
    // �鲢
    ListMerge(A, B, C);
    DispList(C);
    printf("\n");
	}
    return 0;
}
