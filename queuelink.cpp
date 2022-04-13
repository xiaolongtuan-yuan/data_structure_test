#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
#define maxsize 10
typedef int ElementType;
struct Node {
	ElementType Data;
	struct QNode *next;
}Node,*linklist;
struct Qnode {
	struct QNode *rear;
	struct QNode *front;
}Queue;
void initialQ(Queue &q){
	
}

