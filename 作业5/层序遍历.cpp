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

//二叉树,二叉链表
typedef struct Bitnode
{
    char data;
    struct Bitnode *lchild,*rchild;//引用自己本身必须要指针 
}Bitnode,*Bitree;//指针已经定义好的一个类型   bitree 
char ch;
int sum=0;
//先序次序依次输入二叉树，空格是空树     构造二叉树//c++p202
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

//队列遍历 
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
    printf("input your bitree(preorder,#为输入截止):\n");
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

