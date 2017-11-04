#include<fstream>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
//#include"stdafx.h"
using namespace std;
//#define NULL 0
//#define ERROR 0
/*************定义结点**************/
typedef struct node{
	char val;
	node *next;
}lnode,*linklist; 

/**************创建A-Z的单向链表****************/
bool creatlist(linklist &l,int n){
	linklist p,q;	
	char a='A';
	//l是head 
	//l=(linklist)malloc(sizeof(lnode));
	q=(linklist)malloc(sizeof(lnode));
	if(!q)return 0;
	l->next=q;
	q->val=a;
	for(int i=1;i<n;i++){
		q->next=NULL;
		p=(linklist)malloc(sizeof(lnode));
		if(!p)return 0;
		p->val=(char)(a+i);
		q->next=p;
		q=p;
	}
	return 1;
}
/**************判断可不可以插入该字符***************/ 
bool insert(linklist &l,int i,char c){
	if(i>27)return 0;
	 
	linklist p,q;
	q=(linklist)malloc(sizeof(lnode));
	if(!q)return 0;
	q->val=c;
	p=(linklist)malloc(sizeof(lnode));
	if(!p)return 0;
	p=l->next;
	i--; 
	while(i>1){
		p=p->next;
		i--;
	}	
	q->next=p->next;
	p->next=q;
	return 1;
}
/**********主函数*************/
int main(){
	linklist l,q;
	l=(linklist)malloc(sizeof(lnode));
	if(!l)return 0;
	
	int i;
	char p;
	creatlist(l,26);
	int flag=0;
	while(!flag){
		printf("请输入任一大写字母：\n"); 
		p=getchar();
		getchar();
		if(p>'Z'||p<'A'){
			printf("你的输入的字母不符合要求！\n\n\n");
		} 
		else flag=1;
	}
	
	while(flag){
		printf("请输入大写字母需要插入的次序（0-26）：\n"); 
		scanf("%d",&i);
		if(i>27||i<0){
			printf("你的输入的次序不符合要求！\n\n\n");
		}
		else flag=0; 
	}
	
	
	printf("以下是最终字母表：\n"); 
	if(insert(l,i,p)){
		q=l->next;
		while(q!=NULL){
			printf("%c ",q->val);
			q=q->next;
		}
	}
	else printf("ERROR\n");
	return 0;
}
