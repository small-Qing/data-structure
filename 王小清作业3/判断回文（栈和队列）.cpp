#include<fstream>
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
//#include"stdafx.h"
using namespace std;
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define ERROR 0

/*************�������**************/
struct queue{
	char *base,*top;
	int size;
};

/**************������ջ**************/
void initqueue(queue &l){
	l.base=(char*)malloc(sizeof(char));//ֻ�ܷ���void��ָ���ͣ� 
	if(!l.base)exit(OVERFLOW); 
	l.top=l.base;
	l.size=100;
}
/*********ѹ��ջ**********/
void push(queue &l,char e){
	if(l.top-l.base>=l.size){//ջ�� 
		l.base=(char*)realloc(l.base,(l.size+100)*sizeof(char));
		if(!l.base)exit(OVERFLOW);
		l.top=l.base+l.size;
		l.size+=100;
	}
	(*l.top)=e;//ָ�����ڵĿռ䱻��ֵΪe 
	l.top+=1;
}

/*******ջΪ���ж�********/
bool empty(queue &l){
	if(l.base==l.top)return true;
	return false;
}

/******ȥ����ȡ��ջβ******/
void stackpoptop(queue &s,char &a){
	if(s.base==s.top)return;
	a=*(s.top-1);
	s.top--;
} 
/******ȥ����ȡ��ջͷ******/
void queuepoptop(queue &s,char &a){
	if(s.base==s.top)return;
	a=*(s.base);
	s.base++;
}

int main()
{
	string s;
	queue que,sta;
	initqueue(que);
	initqueue(sta);
	int cur=0;
	//freopen("1.txt","r",stdin);
	for(int l=0;l<10;l++){
		printf("please input a string:\n");
		getline(cin,s);
		for(int i=0;i<s.size();i++){
			push(sta,s[i]);
		}
		bool flag=1;
		for(int i=0;i<s.size();i++){
			char b;
			stackpoptop(sta,b);
			if(s[i]!=b){
				printf("This is not a palindrome ! \n\n\n\n");
				flag=0;
				break;
			}
		}
		if(flag)printf("HHHHHHH!!!    This is a palindrome ! \n\n\n\n"); 
	}
	return 0;
}
