#ifndef MIDSTU_H
#define MIDSTU_H
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
using namespace std;
//自己添信息 
struct info{
	string sss;
	int id;
	char cha;
};
struct dulnode{
	info val;
	dulnode *next;
	dulnode *pre;
	dulnode(info x):val(x),next(NULL),pre(NULL){}
}; 
class dnodelist {
	public:
		dulnode *head;
		dulnode *tail;
		//构造函数 
		linklist();
		int length();
		void inserthead(info x);
		void insertlist(info x,int pos);
		void remove(info val);
		//void reverse();
		int find(info val);
		void print();
		//析构函数
		~linklist(); 
	protected:
			
	private:
		int len;
};
#endif
