#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int SElemType;
typedef struct Snode
{
	SElemType data;
	struct Snode *next;
}Snode, *LinkStack;

//1.��ʼ������
void initLinkStak(LinkStack &LS)
{
	LS = NULL;
}

//2.�ж�ջ�Ƿ��
int LinkStackEmpty(LinkStack LS)
{
	if (LS == NULL) return 1;
	else return 0;
}

//3.�õ�ջ��
int LinkStackGetTop(LinkStack LS, SElemType &e)
{
	if (LS == NULL) return 0;
	e = LS->data; return 1;
}

//4.��ջ�ĳ���
int LinkListLength(LinkStack LS)
{
	LinkStack p = LS;
	int n = 0;
	while (p) { n++; p = p->next; }
	return n;
}

//5.��ջ
void Push(LinkStack &LS, SElemType e)
{
	//�����µĽ����뵽ԭ���ĵ�һ���ڵ�֮ǰ��ͷ�巨
	LinkStack p = (LinkStack)malloc(sizeof(Snode));
	p->data = e;
	p->next = LS;
	LS = p;
}

//6.��ջ
int Pop(LinkStack &LS, SElemType &e)
{
	LinkStack p = LS;
	if (LS == NULL)return 0;
	e = p->data;
	LS = LS->next;
	free(p);
	return 1;
}
int main() {
	LinkStack s;
	initLinkStak(s);
	int num = 10, l = 10, n = 0;
	scanf("%d", &num);
	while (num / 8) {
		l = (num / 8);
		n = (num % 8);
		Push(s, n);
		num = l;
	}
	Push(s,num);
	while (!LinkStackEmpty(s)) {
		int x;
		Pop(s, x);
		printf("%d", x);
	}
	return 0;
}
