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
/*************����ջ**************/
typedef struct stack{
	char *base,*top;
	int size;
}qstack;

/**************������ջ**************/
void initstack(qstack &l){
	l.base=(char*)malloc(sizeof(char));//ֻ�ܷ���void��ָ���ͣ� 
	if(!l.base)exit(OVERFLOW); 
	l.top=l.base;
	l.size=100;
}
/*********ѹ��ջ**********/
void push(qstack &l,char e){
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
bool stackempty(qstack &l){
	if(l.base==l.top)return true;
	return false;
}

/******ȥ����ȡ��ջ��******/
void pop(qstack &s){
	if(s.base==s.top)return;
	s.top--;
	//free(*s.top);
} 

/********ȡ��ջ��*******/
char gettop(qstack &s){
	if(s.base==s.top)return ERROR;
	return *(s.top-1);
}

/*************************�����ݲ���������OP������Ȩ����Ķ���*/
char OP[7]={'+','-','*','/','(',')','#'};
char precede[7][7]={
'>','>','<','<','<','>','>',
'>','>','<','<','<','>','>',
'>','>','>','>','<','>','>',
'>','>','>','>','<','>','>',
'<','<','<','<','<','=',0,
'>','>','>','>',0,'>','>',
'<','<','<','<','<',0,'='};


/*************************�ж������ַ��Ƿ�Ϊ����������������Ϊ������*/
char Precede(char op,char c)
{
	int pos_op;
	int pos_c;
	int i;
	for (i=0;i<7;i++){
		if(op==OP[i]) pos_op=i;
		if(c==OP[i]) pos_c=i;
	}
	return(precede[pos_op][pos_c]);
}
/*************************���ж�Ϊ���������ַ���������Ȩ�����ж�������˳��*/
char Operate(char a,char theta,char b)
{
	switch(theta){
		case '+': return (a-'0')+(b-'0')+'0';
		case '-': return (a-'0')-(b-'0')+'0';
		case '*': return (a-'0')*(b-'0')+'0';
		case '/': return (a-'0')/(b-'0')+'0';
	}
}
/**************�ж��ǲ��������********/ 
bool jud(char c,char *OP){
	int i=0;
	while(i<7){
		if(c==OP[i])return true;
		i++;
	}
	return false;
} 
/*************************�Ա��ʽ���м��㣬���ؼ�����*/
char calculator(qstack &op,qstack &ma,char *c){//����������� 
	initstack(op);push(op,'#');
	initstack(ma);
	int cur=0;//cѹ��ջ�У�����ѭ��������󵽵׵����ս��
	//push(ma,c[cur]); 
	while(!stackempty(op)){	
		printf("%c\n",c[cur]);
		
		if(c[cur]=='\n'){
			c[cur]='#';
		}
		//��������� 
		if(!jud(c[cur],OP)){
			push(ma,c[cur]);
			cur++;//c=getchar();//cin>>c;//scanf("%c",&c);
		}//�������
		else{
			char k=gettop(op);
			switch(Precede(k,c[cur])){
				case'<':
					push(op,c[cur]);
					cur++;//c=getchar();//cin>>c;//scanf("%c",&c);
					break;
				case'=':
					pop(op);
					cur++;//c=getchar();//cin>>c;//scanf("%c",&c);
					break;	
				case'>':
				{
					char a=gettop(ma);
					pop(ma);
					char b=gettop(op);
					pop(op);
					char c=gettop(ma);
					pop(ma);
					char d=Operate(c,b,a);
					printf("a=%d b=%d c=%d d=%d\n",a-'0',b-'0',c-'0', d-'0');	
					push(ma,d);
					//push(op,c[cur]);
					//cur++;
					break;
				}
			}
		} 
		//if(gettop(op)=='#'&&stackempty(ma))break;	 
	}
	return gettop(ma);
}

int main()
{
	char i,c[100];
	qstack op,ma;
	int cur=0;
	//freopen("1.txt","r",stdin);
	/*while(1){
		c[cur]=getchar();
		if(c[cur]=='\n')break;
		cur++;
	}*/
	while((c[cur]=getchar())!='\n'){
		cur++;
	}
	/*
	for(int y=0;y<cur;y++){
		printf("%c ",c[y]);
	}*/
	i=calculator(op,ma,c);
	printf("\nThis expression's result is:    ");
	printf("%d\n\n\n\n",i-'0');
	return 0;
}
