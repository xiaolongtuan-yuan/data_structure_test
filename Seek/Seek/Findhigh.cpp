#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>//����,���ǵ�Ҫʹ�ò������������������ö���ʵ��ÿһ�������
using namespace std;
typedef struct BitNode {
	//int high = 1;
	int data;
	struct BitNode *Lchild, *Rchild;
}BitNode, *Linktree;

void putin(Linktree &T, queue<int> &Q2) {
	queue<Linktree>Q1;
	if (Q2.front() == 0) {
		T = NULL;
		return;
	}

	else {
		T = new BitNode;
		T->data = Q2.front();
		Q2.pop();
		T->Lchild = NULL;
		T->Rchild = NULL;
		Q1.push(T);
	
	}//�������ڵ�
	while (!Q1.empty()) {
		Linktree temp = Q1.front();
		Q1.pop();
		if (Q2.front() == 0) {
			temp->Lchild = NULL;
			Q2.pop();
		}
		else {
			temp->Lchild = new BitNode;
			temp->Lchild->data = Q2.front();
			Q2.pop();
			temp->Lchild->Lchild = NULL;
			temp->Lchild->Rchild = NULL;

			Q1.push(temp->Lchild);
			if (Q2.front() == 0) {
				temp->Rchild = NULL;
				Q2.pop();
			}
			else {
				temp->Rchild = new BitNode;
				temp->Rchild->data = Q2.front();
				Q2.pop();
				temp->Rchild->Lchild = NULL;
				temp->Rchild->Rchild = NULL;
				Q1.push(temp->Rchild);

			}
		}
		return;
	}
}	//ͨ������Ĳ���������������������

int Seekhigh(Linktree T, int key,int &i) {
	if (!T) {
		return -1;//����ʧ�ܷ���-1
	}
	else if (T->data == key) {
		return i;//���ز���
	}
	else if (key < T->data) {
		i++;//ÿ��ƥ���ʱ�������һ
		return Seekhigh(T->Lchild, key,i);
	}
	else {
		i++;
		return Seekhigh(T->Rchild, key,i);
	}
}

int Seek(Linktree T, int key) {
	int i = 1;//���ڼ�¼ƥ�����
	return Seekhigh(T, key, i);//Ҫʹ�õݹ����������ƥ����������
}

int main() {
	int k = 0;
	cin >> k;
	for (int j = 0; j < k; j++) {
		int e;
		queue<int>Q;
		int key;
		cin >> key;
		while (cin >> e && e != (-1)) {
			Q.push(e);
		}
		Linktree T;
		putin(T, Q);
		cout << Seek(T, key) << endl;;
	}
	return 0;
}