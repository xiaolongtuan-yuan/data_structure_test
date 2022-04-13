#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//栈的数据类型
typedef char SElemType ;

//链栈的数据类型C语言描述

typedef struct stack
{

	SElemType data;
	struct snode *next;
}Snode,*LinkStack;

//1.初始化操作
void initLinkStak(LinkStack *LS)
{
	*LS=NULL; 
}

//2.判断栈是否空
int LinkStackEmpty(LinkStack LS)
{
	if(LS==NULL) return 1;
	else return 0;
}

//3.得到栈顶
int LinkStackGetTop(LinkStack LS,SElemType *e)
{
	if(LS==NULL) return 0;
	*e=LS->data;return 1;
}

//4.求栈的长度
int LinkListLength(LinkStack LS)
{
	LinkStack p=LS;
	int n=0;
	while(p){n++;p=p->next;}
	return n;
}

//5.进栈
void Push(LinkStack *LS,SElemType e)
{
	//生成新的结点插入到原来的第一个节点之前，头插法
	LinkStack p=(LinkStack)malloc(sizeof(Snode));
	p->data=e;
	p->next=*LS;
	*LS=p;
}

//6.出栈
void Pop(LinkStack *LS,SElemType *e)
{
	LinkStack p=*LS;
	if(*LS==NULL)return 0;
	*e=p->data;
	*LS=(*LS)->next;
	free(p);
	return 1;
}
//算术表达式转换为后缀表达式
void Transformaion(char a[],char suff[]);  
void main()
{
	int m=0,q=0;
	scanf("%d",&m);
	for(q=0;q<m;q++){
	int num;
	scanf("%d",&num);
	char* data = (char*)malloc((num+2) * sizeof(char));
	char* resu = (char*)malloc((num+2) * sizeof(char));
	printf("请输入表达式:"); //输入表达式，允许出现() [] {}
	gets(data);
	Transformaion(data,resu);
	puts(resu);
	}
}

int prior(char a)
{
	if(a=='*'||a=='/')return 4;
	else if(a=='+'||a=='-')return 3;
	else if(a=='(')return 2;
	else if(a=='#')return 1;
	else return 0;
}

void Transformaion(char a[],char suff[])
{
	//a指向算术表达式，以#为结束，栈用于存放运算符
	//将a指向的算术表达式转换为由suff指向的后缀表达式
	int i=0,k=0,n;char ch;
	LinkStack S;
	initLinkStak(&S);Push(&S,'#');
	n=strlen(a);a[n]='#';a[n+1]='\0';
	while(a[i]!='\0')
	{
		if(a[i]>='a' && a[i]<='z'||a[i]>='A' && a[i]<='Z')suff[k++]=a[i];
		else
			switch(a[i])
		{
			case '(':Push(&S,a[i]);break;
			case ')':		//将左圆括号以上的运算符出栈并发送到后缀表达式
				Pop(&S,&ch);
				while(ch!='(')
				{
					suff[k++]=ch;
					Pop(&S,&ch);
				}
				break;
			default:	//比较当前表达式的运算符a[i]和栈顶运算符ch
						//如果a[i]高于ch，a[i]进栈，反之栈内高于
						//a[i]的运算符一次出栈，发往后缀表达式，直到栈顶运算符优先级低，再将a[i]进栈
				if(S->data=='#')Push(&S,a[i]);
				else{
					
					if(prior(a[i])==4){
						while(S->data!='#'){
						LinkStackGetTop(S,&ch);
						if(prior(ch)==4)    //这里书上把if用成了while导致了一个######死循环
						{
							suff[k++]=ch;
							Pop(&S,&ch);
						}
						else break;
					}Push(&S,a[i]);
					}
					if(prior(a[i])==3){
						while(S->data!='#'){
						LinkStackGetTop(S,&ch);
						if(prior(ch)>=prior(a[i]))    //这里书上把if用成了while导致了一个######死循环
						{
							suff[k++]=ch;
							Pop(&S,&ch);
						}
						else break;
					}Push(&S,a[i]);
					}
					else if(prior(a[i])==1){
						while(S->data!='#'){
							Pop(&S,&suff[k++]);
						}
						break;
					} 
				/*else{
						while(S->data!='#'){//未空 
				
				else{
					Push(&S,a[i]);break;
				}
				LinkStackGetTop(S,&ch);
					}
				}*/
				/*while(S->data!='#'){
				LinkStackGetTop(S,&ch);
				if(prior(ch)>=prior(a[i]))    //这里书上把if用成了while导致了一个######死循环
				{
					suff[k++]=ch;
					Pop(&S,&ch);
				}
				else{
					Push(&S,a[i]);break;
				}*/
			}
	//			if('#'!=a[i])Push(&S,a[i]);//这里把!=用成=导致了一个错误
		}//switch
		i++;
	}//while
	suff[k]='\0';
}

 
