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
#define mod 2 
/*************定义栈**************/
typedef struct stack{
	int *base,*top;
	int size;
}qstack;
/*在64位机器上，int是4个字节，指针是8个字节，将指针的值赋给int型就汇报错了，64位机器上long是8字节的，因此需要改为long型**/ 
/**************创建空栈**************/
void initstack(qstack &l){
	l.base=(int*)malloc(sizeof(int));//只能返回void（指针型） 
	if(!l.base)exit(OVERFLOW); 
	l.top=l.base;
	l.size=100;
}
/*********压入栈**********/
void push(qstack &l,int e){
	if(l.top-l.base>=l.size){//栈满 
		l.base=(int*)realloc(l.base,(l.size+100)*sizeof(int));
		if(!l.base)exit(OVERFLOW);
		l.top=l.base+l.size;
		l.size+=100;
	}	
	*l.top=e;//指针所在的空间被赋值为e 
	l.top++;
}
/*******栈为空判断********/
bool stackempty(qstack &l){
	if(l.base==l.top)return true;
	return false;
}
/******去除并取出栈顶******/
int pop(qstack &s){
	if(s.base==s.top)return ERROR;
	s.top--;
	int ans=*s.top;
	//free(*s.top);
	return ans;
} 
/*****转换********/ 
void conversion(){
	int n;
	qstack s;
	initstack(s);
	scanf("%d",&n);
	while(n){
		push(s,n%mod);
		//printf("%d\n",*s.base);
		n=n/mod;
	}
	while(!stackempty(s)){
		printf("%d",pop(s)); 
	}
}

/******主函数****/ 
int main(){
	conversion();
	return 0;
} 
