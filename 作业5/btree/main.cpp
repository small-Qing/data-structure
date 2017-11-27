
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
//������,��������
typedef struct Bitnode//2��ָ��
{
    char data;
    struct Bitnode *lchild,*rchild;
}Bitnode,Bitree;//ָ��
char a[100];

//�����������������������ո��ǿ���     ���������//c++p202
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

//�������,����ݹ�
void preordertraverse(Bitree* T,int &sum)
{
    if(T==NULL)return;
    preordertraverse(T->lchild,sum);
    printf("%c",T->data);
    sum++;
    preordertraverse(T->rchild,sum);
    return;
}

//�������
void inordertraverse(Bitree* root)
{
	//����
	if (root == NULL)return;
	//���ǿ�
	Bitree* p = root;
	stack<Bitree*> s;
	while (!s.empty() || p)
	{
		//һֱ���������������±ߣ��߱����߱�����ڵ㵽ջ��
		while (p)
		{
			s.push(p);
			p = p->lchild;
		}
		//��pΪ��ʱ��˵���Ѿ��������������±ߣ���ʱ��Ҫ��ջ��
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			cout << setw(4) << p->data;
			//��������������ʼ�µ�һ������������(���ǵݹ������ʵ��)
			p = p->rchild;
		}
	}
}
//�������
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
//�������
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
    printf("input your bitree(preorder,�ո��ǿ���,#Ϊ�����ֹ):\n");
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
