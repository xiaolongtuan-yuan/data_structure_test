#include<stdio.h>
#include<iostream>

using namespace std;
typedef struct BitNode {
	char data;
	struct BitNode *Lchild, *Rchild;
}BitNode, *Linktree;
void prein(Linktree &T)
{
    char ch;
    if ((ch = getchar()) == ' ')
        T = NULL;  
    else
	{
        T = new BitNode;//�����µ�����  
        T->data = ch;//��getchar�������������  
        prein(T->Lchild);//�ݹ鴴��������  
        prein(T->Rchild);//�ݹ鴴��������  
    }
}

void preout(Linktree &L) {
	if (L == NULL) return;
	else {
		cout << L->data << " ";
		preout(L->Lchild);
		preout(L->Rchild);
	}
	cout << endl;
	return;
}
void midout(Linktree &L) {
	if (L == NULL) {
		cout << L->data << " ";
		return;
	}
	else {
		midout(L->Lchild);
		cout << L->data << " ";
		midout(L->Rchild);
	}
	cout << endl;
	return;
}
void postout(Linktree &L) {
	if (L == NULL) {
		cout << L->data << " ";
		return;
	}
	else {
		postout(L->Lchild);
		postout(L->Rchild);
		cout << L->data << " ";
	}
	cout << endl;
	return;
}
int main() {
	Linktree T;
	prein(T);
	preout(T);
	midout(T);
	postout(T);
	return 0;
}





