#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//ջ����������
typedef char SElemType ;

//��ջ����������C��������

typedef struct stack
{

	SElemType data;
	struct snode *next;
}Snode,*LinkStack;

//1.��ʼ������
void initLinkStak(LinkStack *LS)
{
	*LS=NULL; 
}

//2.�ж�ջ�Ƿ��
int LinkStackEmpty(LinkStack LS)
{
	if(LS==NULL) return 1;
	else return 0;
}

//3.�õ�ջ��
int LinkStackGetTop(LinkStack LS,SElemType *e)
{
	if(LS==NULL) return 0;
	*e=LS->data;return 1;
}

//4.��ջ�ĳ���
int LinkListLength(LinkStack LS)
{
	LinkStack p=LS;
	int n=0;
	while(p){n++;p=p->next;}
	return n;
}

//5.��ջ
void Push(LinkStack *LS,SElemType e)
{
	//�����µĽ����뵽ԭ���ĵ�һ���ڵ�֮ǰ��ͷ�巨
	LinkStack p=(LinkStack)malloc(sizeof(Snode));
	p->data=e;
	p->next=*LS;
	*LS=p;
}

//6.��ջ
void Pop(LinkStack *LS,SElemType *e)
{
	LinkStack p=*LS;
	if(*LS==NULL)return 0;
	*e=p->data;
	*LS=(*LS)->next;
	free(p);
	return 1;
}
//�������ʽת��Ϊ��׺���ʽ
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
	printf("��������ʽ:"); //������ʽ���������() [] {}
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
	//aָ���������ʽ����#Ϊ������ջ���ڴ�������
	//��aָ����������ʽת��Ϊ��suffָ��ĺ�׺���ʽ
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
			case ')':		//����Բ�������ϵ��������ջ�����͵���׺���ʽ
				Pop(&S,&ch);
				while(ch!='(')
				{
					suff[k++]=ch;
					Pop(&S,&ch);
				}
				break;
			default:	//�Ƚϵ�ǰ���ʽ�������a[i]��ջ�������ch
						//���a[i]����ch��a[i]��ջ����֮ջ�ڸ���
						//a[i]�������һ�γ�ջ��������׺���ʽ��ֱ��ջ����������ȼ��ͣ��ٽ�a[i]��ջ
				if(S->data=='#')Push(&S,a[i]);
				else{
					
					if(prior(a[i])==4){
						while(S->data!='#'){
						LinkStackGetTop(S,&ch);
						if(prior(ch)==4)    //�������ϰ�if�ó���while������һ��######��ѭ��
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
						if(prior(ch)>=prior(a[i]))    //�������ϰ�if�ó���while������һ��######��ѭ��
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
						while(S->data!='#'){//δ�� 
				
				else{
					Push(&S,a[i]);break;
				}
				LinkStackGetTop(S,&ch);
					}
				}*/
				/*while(S->data!='#'){
				LinkStackGetTop(S,&ch);
				if(prior(ch)>=prior(a[i]))    //�������ϰ�if�ó���while������һ��######��ѭ��
				{
					suff[k++]=ch;
					Pop(&S,&ch);
				}
				else{
					Push(&S,a[i]);break;
				}*/
			}
	//			if('#'!=a[i])Push(&S,a[i]);//�����!=�ó�=������һ������
		}//switch
		i++;
	}//while
	suff[k]='\0';
}

 
