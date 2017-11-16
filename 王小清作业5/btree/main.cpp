
#include<fstream>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
//#include"linkstack.h"
#include<bits/stdc++.h>
//#include"stdafx.h"
using namespace std;
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define ERROR 0
//二叉树,二叉链表
typedef struct Bitnode//2阶指针
{
    char data;
    struct Bitnode *lchild,*rchild;
}Bitnode,Bitree;//指针
char a[100];

//先序次序依次输入二叉树，空格是空树     构造二叉树//c++p202
void createbitree(Bitree **root,int &i)
{
    if(a[i]=='#'||a[i]==' '){
        (*root)->data=NULL;return;
    }
    (*root)=(Bitree*)malloc(sizeof(Bitnode));
    (*root)->data=a[i];
    i++;
    createbitree(&(*root)->lchild,i);
    createbitree(&(*root)->rchild,i);
    return;
}

//先序遍历,输出递归
void preordertraverse(Bitree* T,int &sum)
{
    if(T==NULL)return;
    preordertraverse(T->lchild,sum);
    printf("%c",T->data);
    sum++;
    preordertraverse(T->rchild,sum);
    return;
}

//中序遍历
void inordertraverse(Bitree* root)
{
	//空树
	if (root == NULL)return;
	//树非空
	Bitree* p = root;
	stack<Bitree*> s;
	while (!s.empty() || p)
	{
		//一直遍历到左子树最下边，边遍历边保存根节点到栈中
		while (p)
		{
			s.push(p);
			p = p->lchild;
		}
		//当p为空时，说明已经到达左子树最下边，这时需要出栈了
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			cout << setw(4) << p->data;
			//进入右子树，开始新的一轮左子树遍历(这是递归的自我实现)
			p = p->rchild;
		}
	}
}
//后序遍历
void PostOrderBiTree(Bitree* T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        PostOrderBiTree(T->lchild);
        PostOrderBiTree(T->rchild);
        printf("%d ",T->data);
    }
}
//层序遍历
/*int TreeDeep(BiTNode *T)
{
    int deep = 0;
    if (T != NULL)
    {
        int leftdeep = TreeDeep(T->lChild);
        int rightdeep = TreeDeep(T->rChild);
        deep = leftdeep >= rightdeep?leftdeep+1:rightdeep+1;
    }

    return deep;
}*/
//test
int main()
{
    printf("input your bitree(preorder,空格是空树,#为输入截止):\n");
    scanf("%s",a);
    char k;
    int i=0;
    int sum=0;
    printf("a=%s\n",a);
    Bitree **root;
    createbitree(root,i);
    //preordertraverse(root,sum);
    printf("node sum=%d\n",sum);
    //inordertraverse(root);

    return 0;
}
