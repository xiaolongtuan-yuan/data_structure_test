#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//栈的数据类型
typedef char SElemType;

//链栈的数据类型C语言描述

typedef struct stack
{

	SElemType data;
	struct snode *next;
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

//3.得到栈顶
int LinkStackGetTop(LinkStack LS, SElemType *e)
{
	if (LS == NULL) return 0;
	*e = LS->data; return 1;
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

//6.出栈
void Pop(LinkStack *LS, SElemType *e)
{
	LinkStack p = *LS;
	if (*LS == NULL)return 0;
	*e = p->data;
	*LS = (*LS)->next;
	free(p);
	return 1;
}
//算术表达式转换为后缀表达式
void Transformaion(char a[], char suff[]);
void main()
{
	int m = 0, q = 0;
	scanf("%d", &m);
	for (q = 0; q < m; q++) {
		int num, i;
		scanf("%d", &num);
		char data[102], resu[102];
		scanf("%s", &data);
		Transformaion(data, resu);
		puts(resu);
	}
}

int prior(char a)
{
	if (a == '*' || a == '/')return 4;
	else if (a == '+' || a == '-')return 3;
	else if (a == '(')return 2;
	else if (a == '#')return 1;
	else return 0;
}

void Transformaion(char a[], char suff[])
{
	//a指向算术表达式，以#为结束，栈用于存放运算符
	//将a指向的算术表达式转换为由suff指向的后缀表达式
	int i = 0, k = 0, n; char ch;
	LinkStack S;
	initLinkStak(&S); Push(&S, '#');
	n = strlen(a); a[n] = '#'; a[n + 1] = '\0';
	while (a[i] != '\0')
	{
		if (a[i] >= 'a' && a[i] <= 'z' || a[i] >= 'A' && a[i] <= 'Z')suff[k++] = a[i];
		else
			switch (a[i])
			{
			case '(':Push(&S, a[i]); break;
			case ')':		//将左圆括号以上的运算符出栈并发送到后缀表达式
				Pop(&S, &ch);
				while (ch != '(')
				{
					suff[k++] = ch;
					Pop(&S, &ch);
				}
				break;
			default:
				if (S->data == '#')Push(&S, a[i]);//如果栈中无符号则入栈
				else {

					if (prior(a[i]) == 4) {//如果输入字符为乘号或除号
						while (S->data != '#') {
							LinkStackGetTop(S, &ch);
							if (prior(ch) == 4) //栈顶也为乘号或除号则出栈
							{
								suff[k++] = ch;
								Pop(&S, &ch);
							}
							else break;
						}Push(&S, a[i]);//该符号一定入栈
					}
					if (prior(a[i]) == 3) {//若输入符号为加减
						while (S->data != '#') {
							LinkStackGetTop(S, &ch);
							if (prior(ch) >= prior(a[i]))//若栈顶为乘除则出栈
							{
								suff[k++] = ch;
								Pop(&S, &ch);
							}
							else break;
						}Push(&S, a[i]);//该符号入栈
					}
					else if (prior(a[i]) == 1) {//若输入结束
						while (S->data != '#') {//栈中还有符号则依次出栈
							Pop(&S, &suff[k++]);
						}
						break;
					}
				}
			}
		i++;
	}
	suff[k] = '\0';
}


