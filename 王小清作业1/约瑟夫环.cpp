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
/*************定义结点**************/
typedef struct node{
	int val,cur;
	node *next;
}*link;
/*************定义结链表**************/
struct linklist{
	int len;
	link head;
};

/**************创建n的循环链表并输入val**************/
void creatround(linklist &l,int n){
	link p,q;	
	q=(link)malloc(sizeof(link));
	if(!q)exit(OVERFLOW);
	int i;
	printf("请依次输入每个人的密码：\n");
	for(i=0;i<n-1;i++){
		l.len++;
		scanf("%d",&q->val);//cin>>q->val;//
		q->cur=i+1;
		q->next=NULL;
	
		p=(link)malloc(sizeof(link));
		if(!p)exit(OVERFLOW);
		q->next=p;
		if(i==0)l.head=q;
		q=p;
	}
	l.len++;
	scanf("%d",&q->val);//cin>>q->val;//
	q->cur=i+1;
	q->next=l.head;//循环 
}

/**************删去返回被删结点***************/ 
link detectround(link &q,int m){ //传入的q是m==1的情况 
	link p;
	int i;
	p=(link)malloc(sizeof(link));
	if(!p)exit(OVERFLOW);
	
	for(i=1;i<m;i++)//m<=1，q永远记录被讨论的下一个 
	{
		p=q;
		q=q->next;
	}
	p->next=q->next; 
	p=q;
	return p;
}

/**********主函数*************/
int main(){
	linklist l;
	l.len=0;
	//freopen("d.txt","r",stdin);
	int i,m,n;
	printf("请输入总人数:\n");
	scanf("%d",&n);//总人数 报数上限 
	printf("请输入报数上限:\n");
	scanf("%d",&m);
	creatround(l,n);
	//printf("%d\n",l.len);
	
	link p=(link)malloc(sizeof(link));
	link q=(link)malloc(sizeof(link));
	p=l.head;
	printf("以下是淘汰人的次序：\n") ; 
	while(l.len>0){
		q=detectround(p,m);
		printf("%d ",q->cur);
		m=q->val;
		l.len--; 
		p=q->next;
		free(q);
	}
	return 0;
}
