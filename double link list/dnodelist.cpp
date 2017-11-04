#include<iostream>
#include<string.h>
#include<windows.h>
#include<vector>
#include<cstdlib>
#include<map>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include"dulnodelist.h" 
#include"stdafx.h"
using namespace std;
//构造函数 
dnodelist::linklist(){
	dulnode *p=new dulnode;
	if(p){
		p->next=NULL;
		head=tail=p;
		head->pre=NULL;
		tail->next=NULL; 
		len=0;
	}
	else return 0;
}
//析构函数
dnodelist::~linklist(){
	dulnode *temp;
	for(int i=0;i<length;i++){
		temp=head;
		head=head->next;
		delete temp;
	}
	delete head;
	delete tail;
	len=0; 
	/*temp=head;
	while(head){
		head=temp->next;
		delete temp;
		temp=head;
	}
	*/
} 

//得到长度
int dnodelist::length(){
	return len;
} 

//释放链表==析构(保留head&&tail) 
void dnodelist::free()
{
	dulnode *p;
	p=head;
	while(p!=tail){
		head=p->next;
		delete p;
		p=head;
	} 
	head->pre=NULL;
	tail->next=NUll;
	len=0;
}

//插入头结点
void dnodelist::inserthead(info val){
	insertlist(val,0);
} 
// 构造一个空的线性链表---->头结点 
void dnodelist::inserthead(info val){
	dulnode p;
	p=malloc(sizeof(dulnode));
	if(!p)return 0;
	else {
		p->next=NULL;
		p->prev=NULL; 
		l->head=l->tail=p;
		l->len=0;	
	}
}

// 将线性链表L重置为空表，并释放原链表的结点空间
void clearnodelist(dulnode &l){
	dulnode *p,q;
	if(l->head!=l->rear){
		p=q=l->head->next;
		l->head->next=NULL;
		while(p!=l->rear){
			p=q->next;
			free(q);
			q=p;
		} 
		free(q);
		l->rear=l->head;
		l->len=0; 
	}
	
}
//插入 
void dnodelist::insertlist(info val,int pos){
	if(pos<0){
		cout<<"pos<0\n";return;
	}
	int index=1;
	dulnode *temp=head;
	dulnode *node=new dulnode(val);//info装入node
	if(pos==0){
		node->next=temp;
		node->pre=NULL;
		head=node;
		len++;
		return; 
	} 
	while(temp!=NULL&&index<pos){
		temp=temp->next;
		index++;
	}
	if(temp==NULL){
		cout<<"insert failed\n";return;
	}
	node->next=temp->next;//这里用*就是，因为*指针不会因为内存地址改变变量不及时，而使这个赋值没有用 
	temp->next->pre=node;
	node->pre=temp;
	temp->next=node;
	len++;
}
//删除某个 
void dnodelist::remove(info val){
	int pos=find(val);
	if(pos==-1){
		cout<<"delete failed\n"；
		return; 
	}
	if(pos==1){
		head=head->next;
		len--;
		return;
	}
	int index=2;
	dulnode *temp=head,*node;
	while(index<pos){
		temp=temp->next;
	}
	node=temp->next;
	temp->next=temp->next->next;
	temp->next->next->pre=temp; 
	delete node;
	len--;
} 

int dnodelist::find(info x){
	dulnode *temp=head;
	int index=1;
	while(temp!=NULL){
		if(temp->val.cha==x.cha&&temp->val.id==x.id){
			return index;
		}
		temp=temp->next;
		index++;
	}
	return -1;
}
/*
void dnodelist::reverse(){
	if(head==NULL&&tail==NULL)return;
	dulnode *cur=head;
	dulnode *nextnode=head->next;
	dolnode *prenode=head->pre;
	dulnode *temp;
	while(nextnode!=NULL){
		cur->next->next->next=cur->next->next;
		cur->next->pre=cur->next->next;
		cur->next->next=cur;
		
		
		nextnode->next=cur;
		cur=nextnode;
		nextnode=temp;
	}
	head->next=NULL;
	head=cur;
}
*/
void print(){
	if(head==NULL){
		cout<<"linklist is empty\n";
		return;
	}
	dulnode *temp=head;
	while(temp!=NULL){
		cout<<temp->val.cha<<","<<temp->val.id<<"\n";
		temp=temp->next;
	} 
	cout<<"\n";
}
