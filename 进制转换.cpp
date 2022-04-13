#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int SElemType;
typedef struct Snode
{
	SElemType data;
	struct Snode *next;
}Snode, *LinkStack;

//1.初始化操作
void initLinkStak(LinkStack &LS)
{
	LS = NULL;
}

//2.判断栈是否空
int LinkStackEmpty(LinkStack LS)
{
	if (LS == NULL) return 1;
	else return 0;
}

//3.得到栈顶
int LinkStackGetTop(LinkStack LS, SElemType &e)
{
	if (LS == NULL) return 0;
	e = LS->data; return 1;
}

//4.求栈的长度
int LinkListLength(LinkStack LS)
{
	LinkStack p = LS;
	int n = 0;
	while (p) { n++; p = p->next; }
	return n;
}

//5.进栈
void Push(LinkStack &LS, SElemType e)
{
	//生成新的结点插入到原来的第一个节点之前，头插法
	LinkStack p = (LinkStack)malloc(sizeof(Snode));
	p->data = e;
	p->next = LS;
	LS = p;
}

//6.出栈
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
