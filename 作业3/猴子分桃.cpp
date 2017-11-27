#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
using namespace std;
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define ERROR 0
using namespace std;
/******结点********/ 
typedef struct Qnode{
	int id;
	int pear;
	struct Qnode *next;
}*queue;

/*******构造队列********/ 
typedef struct{
	queue front;
	queue rear;
}linkqueue;
/*******构造空队列******/ 
void initqueue(linkqueue &q){
	q.front=q.rear=(queue)malloc(sizeof(Qnode));
	if(!q.front)exit(OVERFLOW);
	q.front->next=NULL;
} 
/********销毁队列******/
void destry(linkqueue &q){
	while(q.front){
		q.rear=q.front->next;
		free(q.front);
		q.front=q.rear;
	}
} 
/*********队列为空判断*****/
bool queueempty(linkqueue &q){
	if(q.front==q.rear)return true;
	else return false;
} 
/********入队列*******/
void enter(linkqueue &q,Qnode e){
	queue p;
	p=(queue)malloc(sizeof(Qnode));
	if(!p)exit(OVERFLOW);
	p->id=e.id;
	p->pear=e.pear;
	q.rear->next=p;
	q.rear=p; 
} 
/********出队列*******/
bool out(linkqueue &q,Qnode &e){
	queue p;
	if(q.front==q.rear)return false;
	p=q.front->next;
	e.id=p->id;
	e.pear=p->pear;
	q.front->next=p->next;
	if(q.rear==p)q.rear=q.front;
	free(p);
	return true;
} 
/**********主函数*********/ 
int main(){
	int n,k,m,i;
	printf("please input n,k,m :\n");
	scanf("%d %d %d",&n,&k,&m);
	linkqueue l;
	initqueue(l);
	Qnode q;
	printf("out sequence:\n");
	for(i=1;i<=n;i++){
		q.id=i;
		q.pear=(i%k==0?k:i%k);
		if(q.pear<m){
			enter(l,q);
		}
		else {
			printf("%d\n",q.id);
		}
	}
	int sum=0; 
	while(!queueempty(l)){
		if(out(l,q)){
			int root=(i)%k==0?k:(i)%k;
			q.pear=q.pear+(root+sum);
			if(q.pear<m){
				enter(l,q);
			}
			else {
			sum+=(q.pear-m);
			printf("%d\n",q.id);
			} 
		}
		i++;
	}
	 return 0;
}
//7 6 5
//5 6 2 3 4 7 1 

