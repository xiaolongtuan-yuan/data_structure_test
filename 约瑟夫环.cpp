#include<stdio.h>
#include<malloc.h>
typedef struct person{
	int number;
	int site;
	person *next;//����ָ��ṹ��ָ��
}person, *Linklist;//�ýṹ��ָ�� 

void init(Linklist &L,int n){//��ʼ������Ϊn��Ȧ
	L=(Linklist)malloc(sizeof(person));
	L->next = NULL;
	Linklist p=L;
	int j=0;
	while (j < n) {
		Linklist temp = (Linklist)malloc(sizeof(person));
		temp->next=NULL;
		p->next=temp;
		p=p->next;
		j++;
	}//�ҵ� β��� 
	p->next=L->next;
}
void creat(Linklist &L,int n){
	Linklist p=L->next;
	printf("����������ÿ��ͬѧ�����룺"); 
	for(int i=0;i<n;i++){
		p->site=(i+1);
		scanf("%d",&p->number);//���θ����н���������� 
		p=p->next;
	}
}
int getnumber(Linklist &L,int m,int* num){
	Linklist p=L->next;
	Linklist pa=L;
	for(int i=1;i<m;i++){
		p=p->next;
		pa=pa->next;
	}//�ҵ���Ҫ���е��� 
	*num = p->number;
	int x=p->site;
	pa->next = p->next;
	free(p);//p������ 
	L=pa;//����һ���˿�ʼ���� 
	return x;
}//m��ÿһ�α��������� 

int main(){
	Linklist L;
	init(L,7);//�������߸��˵�Ȧ�� 
	creat(L,7);
	printf("�����һ�α���������m(m<=30)��");
	int m,x;
	do{
		scanf("%d",&m);
	}while(m>30);
	//��ʼ������
	x=getnumber(L,m,&m);
	printf("���е�����Ϊ��%d\n",x);
	for(int i=0;i<6;i++){
		x=getnumber(L,m,&m);
		printf("���е�����Ϊ��%d\n",x);
	}
	return 0;
}

