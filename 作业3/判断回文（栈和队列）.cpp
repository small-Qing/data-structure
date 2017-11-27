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

/*************定义队列**************/
struct queue{
	char *base,*top;
	int size;
};

/**************创建空栈**************/
void initqueue(queue &l){
	l.base=(char*)malloc(sizeof(char));//只能返回void（指针型） 
	if(!l.base)exit(OVERFLOW); 
	l.top=l.base;
	l.size=100;
}
/*********压入栈**********/
void push(queue &l,char e){
	if(l.top-l.base>=l.size){//栈满 
		l.base=(char*)realloc(l.base,(l.size+100)*sizeof(char));
		if(!l.base)exit(OVERFLOW);
		l.top=l.base+l.size;
		l.size+=100;
	}
	(*l.top)=e;//指针所在的空间被赋值为e 
	l.top+=1;
}

/*******栈为空判断********/
bool empty(queue &l){
	if(l.base==l.top)return true;
	return false;
}

/******去除并取出栈尾******/
void stackpoptop(queue &s,char &a){
	if(s.base==s.top)return;
	a=*(s.top-1);
	s.top--;
} 
/******去除并取出栈头******/
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
