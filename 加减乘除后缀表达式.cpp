#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int Status;
typedef char SElemType;
#define OVERFLOW -1
#define ERROR 0
#define OK 1
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;
Status InitStack(SqStack &S) {
	S.base = (SElemType *)malloc((STACK_INIT_SIZE)* sizeof(SElemType));
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}
Status Push(SqStack &S,SElemType e) {
	if ((S.top - S.base) >= S.stacksize) {
		S.base = (SElemType*)realloc(S.base, S.stacksize + STACKINCREMENT);
		if (!S.base)exit(OVERFLOW);
		S.top = S.base + S.stacksize;
	}
	S.stacksize += STACKINCREMENT;
	*S.top++ = e;
	return OK;
}
Status Pop(SqStack &S, SElemType &e) {
	if (S.base = S.top)return ERROR;
	e = *--S.top;
	return OK;
}
char comp(char x,char y){
	if(x==43&&y==43)return '>';
	if(x==43&&y==45)return '>';
	if(x==43&&y==42)return '<';
	if(x==43&&y==47)return '<';
	if(x==45&&y==43)return '>';
	if(x==45&&y==45)return '>';
	if(x==45&&y==42)return '<';
	if(x==45&&y==47)return '<';
	if(x==42&&y==43)return '>';
	if(x==42&&y==45)return '>';
	if(x==42&&y==42)return '>';
	if(x==42&&y==47)return '>';
	if(x==47&&y==43)return '>';
	if(x==47&&y==45)return '>';
	if(x==47&&y==42)return '>';
	if(x==47&&y==47)return '>';
}
int main() {
	int m;
	scanf("%d",&m);//²âÊÔ×éÊı
	for(int i=0;i<m;i++){
		int len=0 ,k=0;
		SqStack optr;
		InitStack(optr);
		scanf("%d",&len);
		char* s=(char*)malloc((len+1)*sizeof(char));
		char* t=(char*)malloc((len+1)*sizeof(char));
//		for(int i=0;i<len;i++){
			scanf("%s",s);
//		}
		for(int j=0;j<len;j++){
			if(('a'<=s[j]&&s[j]<='z')||('A'<=s[j]&&s[j]<='Z')){
				t[k]=s[j];
				k++;
			}else{
				if(optr.top==optr.base)Push(optr,s[j]);
				else{
					while(!(optr.top==optr.base)){
					char temp=*optr.top;
					char temp1=comp(s[j],temp);
					switch(temp1){
						case'>':Push(optr,s[j]);break;
						case'<':Pop(optr,t[k]);k++;break;
						}
					}
				}
			}
		}
		for(int i=0;i<len;i++){
			printf("%c",t[i]);
		}	
	} 
	return 0;
}













