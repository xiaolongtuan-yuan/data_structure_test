#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//栈的数据类型
typedef char SElemType;

//链栈的数据类型C语言描述

typedef struct Snode
{

	SElemType data;
	struct Snode *next;
}Snode, *LinkStack;

//1.初始化操作
void initLinkStak(LinkStack *LS)
{
	*LS = NULL;
}

//2.判断栈是否空
int LinkStackEmpty(LinkStack LS)
{
	if (LS == NULL) return 1;
	else return 0;
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
void Push(LinkStack *LS, SElemType e)
{
	//生成新的结点插入到原来的第一个节点之前，头插法
	LinkStack p = (LinkStack)malloc(sizeof(Snode));
	p->data = e;
	p->next = *LS;
	*LS = p;
}

int Pop(LinkStack *LS, SElemType *e)
{
	LinkStack p = *LS;
	if (*LS == NULL)return 0;
	*e = p->data;
	*LS = (*LS)->next;
	free(p);
	return 1;
}
int prior(char x) {
	switch (x) {
	case'(':return 1; break;
	case')':return 1; break;
	case'[':return 2; break;
	case']':return 2; break;
	default:return 0;
	}
}
int Judge(char *a) {
	int k = 0, i = 0;
	char t;
	LinkStack s=NULL;
//	initLinkStak(s);
	while (a[k] != ('\0')) {
		if (LinkStackEmpty(s)) {
			if (a[k] == ')' || a[k] == ']') {
				printf("此串括号匹配不合法");
				return 0;
			}
			Push(&s, a[k++]);
		}
		while (a[k] == '(' || a[k] == '[') {
			Push(&s, a[k++]);
		}//有括号全部入栈
		if (prior(s->data) == prior(a[k])) {
			Pop(&s, &t);
			k++;
		}
		else {
			printf("此串括号匹配不合法");
			return 0;
		}
	}
	printf("配对");
	return 0;
}
int main() {
	char a[20];
//	int i=0,j=0;
//	scanf("%d", &i);
//	j = i;
//	while (i--) {
	scanf("%s",a);
//	}
//	while (j--)
//		printf("%c", a[i++]);
	Judge(a);
	return 0;
}
