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

#define maxnode 20;
//��
typedef struct arcbox{
    int tailvex,headvex;//head  rear 's  pos
    struct arcbox *hlink,tlink;//��ͷ/β��ͬ����
    //infotype *info;
}arcbox;
//����
typedef struct vnode
{
  int data;
  arcbox *firstin,*firstout;
}vexnode;
//ͼ
typedef struct{
    vexnode xlist[maxnode];
    int vexnum,arcnum;
}graph;
int locatevex(graph p,int v1){
    for(int i=0;i<p.vexnum;p++){

    }
}


void creatDE(graph &g){
    scanf("%d %d %d",&g.vexnum,&g.arcnum,&info);
    //�������ͼ�ĵ�
    for(int i=0;i<g.vexnum;i++){
        scanf("%d",&g.xlist[i].data);
        g.xlist[i].firstin=NULL;
        g.xlist[i].firstout=NULL;
    }
    int start,post;
    //���뻡
    for(int k=0;k<g.arcnum;k++){
        scanf("%d %d",&start,&post);
        i=start-1;//loactevex(g,start);
        j=post-1;//loactevex(g,post);

        p=(arcbox*)malloc(sizeof(arcbox));
        //�Ի���ֵ����
        g.xlist[j].firstin=i;
        g.xlist[i].firstout=j;
        //����
        g.xlist[j].firstout=i;
        g.xlist[i].firstin=j;
        //*p={i,j,g.xlist[j].firstin,g.xlist[i].firstout,NULL};
        //g.xlist[j].firstin=g.xlist[i].firstout=p;
        p.tailvex=j;
        p.headvex=i;

        //if(info)input(*p->info);
    }
}


void BFS(graph g,status(*visit)(int v)){
	for(int v=0;v<g.vexnum;v++)visit[v]=false;
	initqueue(q);
	for(int v=0;v<g.vexnum;v++)
	{
		if(!visit(v)){
			visit[v]=true;
			visit(v);
			enqueue(q,v);
			while(!queueempty(q)){
				dequeue(q,u);
				for(int j=firstadjvex(g,u);w>=0;w=nextadjvex(g,u,w)){
					if(!visit[w]){
						visit[w]=true;
						visit(w);
						enqueue(q,w);
					}
				}
			}
		}	
	} 
} 
