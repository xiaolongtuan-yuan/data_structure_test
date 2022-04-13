#include<iostream>
using namespace std;

typedef struct node
{
    struct node *lchild;
    struct node *rchild;
    char data;
}BiTreeNode, *BiTree;
void createBiTree(BiTree &T)
{
    char c;
    cin >> c;
    if('#' == c)
        T = NULL;
    else
    {
        T = new BiTreeNode;
        T->data=c;
        createBiTree(T->lchild);
        createBiTree(T->rchild);
    }
}

//ǰ���������������ӡ����
void preorder(BiTree T)
{
    if(T)
    {
        cout<<T->data<<" ";
        preorder(T->lchild);
        preorder(T->rchild);
    }
}
//�����������������ӡ����
void midorder(BiTree T)
{
    if(T)
    {
        midorder(T->lchild);
        cout<<T->data<<" ";
        midorder(T->rchild);
    }
}
//������������������ӡ����
void postorder(BiTree T)
{
    if(T)
    {
        postorder(T->lchild);
        postorder(T->rchild);
        cout<<T->data<<" ";
    }
}
int main()
{
    BiTree T;
    createBiTree(T);
    cout<<"������������ɣ�"<<endl;
    cout<<"ǰ�������������"<<endl;
    preorder(T);
    cout<<endl;
    cout<<"���������������"<<endl;
    midorder(T);
    cout<<endl;
    cout<<"���������������"<<endl;
    postorder(T);
    return 0;
}

