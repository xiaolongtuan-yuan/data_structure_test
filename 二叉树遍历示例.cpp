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

//前序遍历二叉树并打印出来
void preorder(BiTree T)
{
    if(T)
    {
        cout<<T->data<<" ";
        preorder(T->lchild);
        preorder(T->rchild);
    }
}
//中序遍历二叉树并打印出来
void midorder(BiTree T)
{
    if(T)
    {
        midorder(T->lchild);
        cout<<T->data<<" ";
        midorder(T->rchild);
    }
}
//后续遍历二叉树并打印出来
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
    cout<<"二叉树创建完成！"<<endl;
    cout<<"前序遍历二叉树："<<endl;
    preorder(T);
    cout<<endl;
    cout<<"中序遍历二叉树："<<endl;
    midorder(T);
    cout<<endl;
    cout<<"后序遍历二叉树："<<endl;
    postorder(T);
    return 0;
}

