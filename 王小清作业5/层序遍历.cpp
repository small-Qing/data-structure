#include<fstream>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
//#include"stdafx.h"
using namespace std;
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define ERROR 0
#include<bits/stdc++.h>
//#include"stdafx.h"
using namespace std;
//#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define ERROR 0

//������,��������
typedef struct Bitnode
{
    char data;
    struct Bitnode *lchild,*rchild;//�����Լ��������Ҫָ�� 
}Bitnode,*Bitree;//ָ���Ѿ�����õ�һ������   bitree 
char ch;
int sum=0;
//�����������������������ո��ǿ���     ���������//c++p202
void createbitree(Bitree* root)//bitree*    
{
	scanf("%c",&ch);
	if(ch=='\n')return;
    else if(ch=='#'||ch==' '){
        *root=NULL;
		//return NULL;
    }
    else {
		*root=(Bitree)malloc(sizeof(Bitnode));//bitnode->*bittree
		(*root)->data=ch;
    	createbitree(&(*root)->lchild);
    	createbitree(&(*root)->rchild);
	}
	//return root;
}

//���б��� 
void levelorder(Bitree T)
{
    Bitree p,queue[500];
    int head,rear;
    head=rear=0;
    if(T!=NULL){
    	queue[rear++]=T;
		while(head!=rear)
		{
			p=queue[head++];
			printf("%c ",p->data);
			if(p->lchild!=NULL)queue[rear++]=p->lchild;
			if(p->rchild!=NULL)queue[rear++]=p->rchild;
		 } 
	}
    return;
}
//test
int main()
{
    printf("input your bitree(preorder,#Ϊ�����ֹ):\n");
    //scanf("%s",a);
    char k;
    int i=0;
    //int sum=0;
    //printf("a=%s\n",a);
    Bitree root;
    createbitree(&root);
    printf("this bitree-levelorder is:\n");
    levelorder(root);
	//printf("\nbitree-node-sum=%d\n",sum);
    return 0;
}

