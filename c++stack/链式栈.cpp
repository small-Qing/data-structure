#include<iostream>
#include"linklist.h"
#include"stack.h"
using namespace std;
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define ERROR 0
template <class T>
class linkstack:public stack<T>{
	public:
		linkstack():top(NULL){};
		~linkstack(){makeempty();};
		void push(const T& x);
		bool pop(T& x);
		bool gettop(T& x)const;
		bool isempty()const {return (top==NULL)?true:false;}
		int getsize()const;
		void makeempty();
		friend ostream& operator <<(ostream& os,seqstack<T>& s);
	private:
		linknode<T> *top;
}; 
/****���ɾȥջ��Ԫ��****/ 
template <class T>
linkstack<T>::makeempty(){
	linknode<T> *p;
	while(top!=NULL){
		p=top;
		top=top->link;
		delete p;
	}
};
/*****x������ʽջ��ջ��****/
template<class T>
void linkstack<T>::push(const T& x){
	top=new linknode<T>(x,top);
	assert(top!=NULL);
}
/****ɾ��ջ��������ջ��Ԫ��******/
template<class T>
void linkstack<T>::pop(T& x){ 
	if(isempty()==true)return false;
	linknode<T> *p=top;
	top=top->link;
	x=p->data;
	delete p;
	return true;
}
/***����ջ��**/
template<class T>
void linkstack<T>::gettop( T& x)const{
	if(isempty()==true)return false;
	x=top->data;
	return true;
};
/******/
template<class T>
void linkstack<T>::getsize()const{
	linknode<T> *p=top;
	int k=0;
	while(top!=NULL){
		top=top->link;
		k++;
	}
	return k;
};
/*****���������<<******/
template<class T>
ostream& operator <<(ostream& os,linkstack<T>& s){
	os<<"ջ��Ԫ�ظ���="<<s.getsize()<<endl;
	linknode<T> *p=s.top;
	int i=0;
	while(p!=NULL){
		os<<++i<<":"<<p->data<<endl;
		p=p->link;
	} 
	return os;	
};
