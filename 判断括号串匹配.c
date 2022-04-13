#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//ջ����������
typedef char SElemType;

//��ջ����������C��������

typedef struct Snode
{

	SElemType data;
	struct Snode *next;
}Snode, *LinkStack;

//1.��ʼ������
void initLinkStak(LinkStack *LS)
{
	*LS = NULL;
}

//2.�ж�ջ�Ƿ��
int LinkStackEmpty(LinkStack LS)
{
	if (LS == NULL) return 1;
	else return 0;
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
void Push(LinkStack *LS, SElemType e)
{
	//�����µĽ����뵽ԭ���ĵ�һ���ڵ�֮ǰ��ͷ�巨
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
				printf("�˴�����ƥ�䲻�Ϸ�");
				return 0;
			}
			Push(&s, a[k++]);
		}
		while (a[k] == '(' || a[k] == '[') {
			Push(&s, a[k++]);
		}//������ȫ����ջ
		if (prior(s->data) == prior(a[k])) {
			Pop(&s, &t);
			k++;
		}
		else {
			printf("�˴�����ƥ�䲻�Ϸ�");
			return 0;
		}
	}
	printf("���");
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
