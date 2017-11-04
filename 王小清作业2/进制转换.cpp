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
/*************����ջ**************/
typedef struct stack{
	int *base,*top;
	int size;
}qstack;
/*��64λ�����ϣ�int��4���ֽڣ�ָ����8���ֽڣ���ָ���ֵ����int�;ͻ㱨���ˣ�64λ������long��8�ֽڵģ������Ҫ��Ϊlong��**/ 
/**************������ջ**************/
void initstack(qstack &l){
	l.base=(int*)malloc(sizeof(int));//ֻ�ܷ���void��ָ���ͣ� 
	if(!l.base)exit(OVERFLOW); 
	l.top=l.base;
	l.size=100;
}
/*********ѹ��ջ**********/
void push(qstack &l,int e){
	if(l.top-l.base>=l.size){//ջ�� 
		l.base=(int*)realloc(l.base,(l.size+100)*sizeof(int));
		if(!l.base)exit(OVERFLOW);
		l.top=l.base+l.size;
		l.size+=100;
	}	
	*l.top=e;//ָ�����ڵĿռ䱻��ֵΪe 
	l.top++;
}
/*******ջΪ���ж�********/
bool stackempty(qstack &l){
	if(l.base==l.top)return true;
	return false;
}
/******ȥ����ȡ��ջ��******/
int pop(qstack &s){
	if(s.base==s.top)return ERROR;
	s.top--;
	int ans=*s.top;
	//free(*s.top);
	return ans;
} 
/*****ת��********/ 
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

/******������****/ 
int main(){
	conversion();
	return 0;
} 
