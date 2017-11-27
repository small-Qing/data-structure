#include<fstream>
#include<stdio.h>
#include<iostream>
#include<queue>
#include<stdlib.h>
//#include"stdafx.h"
using namespace std;
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define ERROR 0

//图的邻接表存储表示
#define MAX_NUM 20
enum GraphKind{GY,GN}; // {有向图,无向图}
typedef struct ArcNode
{
   int adjvex; // 该弧所指向的顶点或边的另一个顶点的位置 次序
   struct ArcNode *nextarc; // 指向下一条弧或边的指针
   //InfoType *info; // 与弧或边相关信息的指针（可无）
}ArcNode;// 表结点 （弧）
typedef struct
{
   int data; // 顶点信息  （权）
   ArcNode *firstarc; // 第一个表结点的地址,指向第一条依附该顶点的弧或边的指针
}VNode; // 头结点
struct graph
{
   VNode xlist[MAX_NUM];//AdjList vertices;
   int vexnum,arcnum; // 图的当前顶点数和弧（边）数
   //GraphKind kind; // 图的种类标志
};

int locate(graph &g,int val)
{
    int i;
    for(i=0;i<g.vexnum;i++)if(g.xlist[i].data==val)return i;
    return -1;
}
void creat(graph &g){
    printf("顶点的个数以及边数:\n");
    scanf("%d %d",&g.vexnum,&g.arcnum);
    //输入各个图的点
    printf("请输入%d个顶点的值(数字编码替代):\n",g.vexnum);
    for(int i=0;i<g.vexnum;i++){
        scanf("%d",&g.xlist[i].data);
        g.xlist[i].firstarc=NULL;
        //g.xlist[i].firstout=NULL;
    }
    printf("请输入%d条弧的弧头和弧尾(空格为间隔):\n",g.arcnum);
    int va,vb;
    for(int k=0;k<g.arcnum;++k) // 构造表结点链表
   {
     scanf("%d %d",&va,&vb);
     int i=locate(g,va); // 弧尾
     int j=locate(g,vb); // 弧头
     ArcNode* p=(ArcNode*)malloc(sizeof(ArcNode));//弧
     p->adjvex=j;
       //p->info=NULL; // 图
     p->nextarc=g.xlist[i].firstarc; // 插在表头  p.next指向第一个弧
     g.xlist[i].firstarc=p;

     ArcNode* q=(ArcNode*)malloc(sizeof(ArcNode));
     q->adjvex=i;
     q->nextarc=g.xlist[j].firstarc; // 插在表头
     g.xlist[j].firstarc=q;
    }
}

void DestroyGraph(graph &g)
{ // 初始条件: 图G存在。操作结果: 销毁图G
   int i;
   ArcNode *p,*q;
   for(i=0;i<g.vexnum;++i)
   {
     p=g.xlist[i].firstarc;
     while(p)
     {
       q=p->nextarc;
       free(p);
       p=q;
     }
   }
   g.vexnum=0;
   g.arcnum=0;
 };


/* 返回图Gp中pos顶点（序号为pos的顶点）的第一个邻接顶点的序号，如果不存在，则返回-1 */
int first_vertex(graph g,int pos)
{
    if(g.xlist[pos].firstarc)  //如果存在邻接顶点，返回第一个邻接顶点的序号
        return  g.xlist[pos].firstarc->adjvex;
    else              //如果不存在，则返回-1
        return -1;
}

/* cur顶点是pos顶点（cur和pos均为顶点的序号）的其中一个邻接顶点，
返回图Gp中，pos顶点的（相对于cur顶点）下一个邻接顶点的序号,如果不存在，则返回-1 */
int next_vertex(graph g,int pos,int cur)
{
    ArcNode *p = g.xlist[pos].firstarc; //p初始指向顶点的第一个邻接点
    //循环pos节点对应的链表，直到p指向序号为cur的邻接点
    while(p->adjvex!= cur)p = p->nextarc;
    //返回下一个节点的序号
    if(p->nextarc)
        return p->nextarc->adjvex;
    else
        return -1;
}

bool visited[MAX_NUM];
/*
//广度优先遍历
void bfs(graph &g,int start){
	printf("%d(%d)->",start,g.xlist[start].data);
    visit[start] = true;
    queue<int>Q;
    Q.push(start);

    int j=0;
    ArcNode* p=(ArcNode*)malloc(sizeof(ArcNode));
    while (!Q.empty())
    {
        int pos= Q.front();
        Q.pop();
        //循环遍历，访问完pVertex顶点的所有邻接顶点,并将访问后的邻接顶点入队
        for(j=first_vertex(g,pos); j>=0; j=next_vertex(g,pos,j))
        {
            if(!visit[j])
            {
                printf("%d(%d)->",j,g.xlist[j].data);
                visit[j] = true;
                Q.push(j);//(queue,i);
            }
        }
    }
}
void runbfs(graph &g,int start)
{
    //预处理
    for (int i=0;i<g.vexnum;++i)visit[i] = false;
	bfs(g,start);
    for (int i=0;i<g.arcnum;++i)
    {
        if (!visit[i])
        {
            bfs(g,i);
        }
    }
}
*/
void BFSTraverse(graph &g)
{
    for (int i = 0; i < g.vexnum; i++)//初始化访问标志数组
        visited[i] = false;

    queue<int> q;

    for (int i = 0; i < g.vexnum; i++)
    {
        if (!visited[i])//如果没有访问过
        {
            visited[i] = true;
            q.push(i);//访问过的入队列
            printf("%d(%d)->",i,g.xlist[i].data);
            while (!q.empty())//队列不为空时
            {
                int x = q.front();
                q.pop();//先取出队首第一个元素，然后将第一个元素删除
                ArcNode * p = g.xlist[x].firstarc;
                while (p)//访问未被访问过的邻接顶点
                {
                    if (!visited[p->adjvex])
                    {
                        visited[p->adjvex] = true;
                        printf("%d(%d)->",p->adjvex,g.xlist[p->adjvex].data);
                        q.push(p->adjvex);
                    }

                    p = p->nextarc;
                }
            }
        }
    }
}
int main(){
	//创建有向图
    //freopen("1.txt","r",stdin);
    graph g;
    creat(g);

    //广度优先遍历图
    cout << "\n广度优先遍历（次序（顶点的值））:" << endl;
    BFSTraverse(g);
    printf("NULL\n\n");


    //销毁有向图
    DestroyGraph(g);
}



