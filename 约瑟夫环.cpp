#include<stdio.h>
#include<malloc.h>
typedef struct person{
	int number;
	int site;
	person *next;//定义指向结构的指针
}person, *Linklist;//该结构的指针 

void init(Linklist &L,int n){//初始化人数为n的圈
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
	}//找到 尾结点 
	p->next=L->next;
}
void creat(Linklist &L,int n){
	Linklist p=L->next;
	printf("请依次输入每个同学的密码："); 
	for(int i=0;i<n;i++){
		p->site=(i+1);
		scanf("%d",&p->number);//依次给所有结点输入密码 
		p=p->next;
	}
}
int getnumber(Linklist &L,int m,int* num){
	Linklist p=L->next;
	Linklist pa=L;
	for(int i=1;i<m;i++){
		p=p->next;
		pa=pa->next;
	}//找到了要出列的人 
	*num = p->number;
	int x=p->site;
	pa->next = p->next;
	free(p);//p出出列 
	L=pa;//从下一个人开始报数 
	return x;
}//m是每一次报数的上限 

int main(){
	Linklist L;
	init(L,7);//创建好七个人的圈子 
	creat(L,7);
	printf("输入第一次报数的上限m(m<=30)：");
	int m,x;
	do{
		scanf("%d",&m);
	}while(m>30);
	//开始求密码
	x=getnumber(L,m,&m);
	printf("出列的密码为：%d\n",x);
	for(int i=0;i<6;i++){
		x=getnumber(L,m,&m);
		printf("出列的密码为：%d\n",x);
	}
	return 0;
}

