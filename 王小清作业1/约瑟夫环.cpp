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
/*************������**************/
typedef struct node{
	int val,cur;
	node *next;
}*link;
/*************���������**************/
struct linklist{
	int len;
	link head;
};

/**************����n��ѭ����������val**************/
void creatround(linklist &l,int n){
	link p,q;	
	q=(link)malloc(sizeof(link));
	if(!q)exit(OVERFLOW);
	int i;
	printf("����������ÿ���˵����룺\n");
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
	q->next=l.head;//ѭ�� 
}

/**************ɾȥ���ر�ɾ���***************/ 
link detectround(link &q,int m){ //�����q��m==1����� 
	link p;
	int i;
	p=(link)malloc(sizeof(link));
	if(!p)exit(OVERFLOW);
	
	for(i=1;i<m;i++)//m<=1��q��Զ��¼�����۵���һ�� 
	{
		p=q;
		q=q->next;
	}
	p->next=q->next; 
	p=q;
	return p;
}

/**********������*************/
int main(){
	linklist l;
	l.len=0;
	//freopen("d.txt","r",stdin);
	int i,m,n;
	printf("������������:\n");
	scanf("%d",&n);//������ �������� 
	printf("�����뱨������:\n");
	scanf("%d",&m);
	creatround(l,n);
	//printf("%d\n",l.len);
	
	link p=(link)malloc(sizeof(link));
	link q=(link)malloc(sizeof(link));
	p=l.head;
	printf("��������̭�˵Ĵ���\n") ; 
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
