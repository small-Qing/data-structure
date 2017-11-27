#include<fstream>
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<queue>
//#include"stdafx.h"
using namespace std;
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
//#define ERROR 0

#define maxnode 20
//弧
typedef struct arcbox{
    int tailvex,headvex;//head  rear 's  pos
    struct arcbox *hlink,*tlink;//弧头/尾相同的链
}arcbox;
//顶点
typedef struct vnode
{
  int data;
  arcbox *firstin,*firstout;//点的第一条入弧
}vexnode;
//图
typedef struct{
    vexnode xlist[maxnode];//十字链表
    int vexnum,arcnum;
}graph;

void creatDE(graph &g){//有向图
    printf("顶点的个数以及边数:\n");
    scanf("%d %d",&g.vexnum,&g.arcnum);
    //输入各个图的点
    printf("请输入%d个顶点的值(数字编码替代):\n",g.vexnum,maxnode);
    for(int i=0;i<g.vexnum;i++){
        scanf("%d",&g.xlist[i].data);//点的权值
        g.xlist[i].firstin=NULL;
        g.xlist[i].firstout=NULL;
    }
    int start,post;
    printf("请输入%d条弧的弧头和弧尾(空格为间隔):\n",g.arcnum);
    //输入弧
    for(int k=0;k<g.arcnum;k++){
        scanf("%d %d",&start,&post);
        int i=start-1;
        int j=post-1;
        arcbox* p=(arcbox*)malloc(sizeof(arcbox));//p===>弧
        arcbox* q=(arcbox*)malloc(sizeof(arcbox));
		p->hlink=NULL;p->tlink=NULL;
        q->hlink=NULL;q->tlink=NULL;
        if((i>=0&&i<13)&&(j>=0&&j<13)){
        	p->tailvex=j;
        	p->headvex=i;

        	q->tailvex=i;
        	q->headvex=j;
        /* 完成在入弧和出弧链表表头的插入 */
        	p->tlink=g.xlist[i].firstout;
        	g.xlist[i].firstout=p;
        	p->hlink=g.xlist[j].firstin;
        	g.xlist[j].firstin=p;

        	q->tlink=g.xlist[j].firstout;
        	g.xlist[j].firstout=q;
        	q->hlink=g.xlist[i].firstin;
        	g.xlist[i].firstin=q;
		}
        else return;
    }
}
int getvex(graph &g,int v){
    if(v>=g.vexnum||v<0)return -1;
    return g.xlist[v].data;
}
bool PutVex(graph g,int v,int value)
 { /* 初始条件: 有向图G存在,v是G中某个顶点 */
   /* 操作结果: 对v赋新值value */
   int i;
   i=v-1;//位置就是v-1
   if(i<0) /* v不是G的顶点 */
     return 0;
   g.xlist[i].data=value;//strcpy(g.xlist[i].data,value);
   return 1;
}
//求顶点的度，在十字链表中还是挺方便的，因为其是邻接表与逆邻接表的结合体
/*int GetVertexDegree( const graph &g,int val )
{
    int m =val-1;  //得到顶点的在顶点表中的索引
    if ( -1 == m )
        return -1;
    int TD = 0;
    //先求出度
    ArcType* pArcOut = G.crossList[m].firstout;
    while ( pArcOut )
    {
        ++TD;
        pArcOut = pArcOut->taillink;
    }

    //再累加入度
    ArcType* pArcIn = G.crossList[m].firstin;
    while( pArcIn )
    {
        ++TD;
        pArcIn = pArcIn->headlink;
    }
    return TD;
}
*/
//销毁图
void DestroyGraph(graph &g)
{
    for ( int i = 0; i < g.vexnum; ++i )
    {
        arcbox* p=(arcbox*)malloc(sizeof(arcbox));//ArcType* pArc = G.crossList[i].firstout;
        while(p)
        {
            arcbox* q=(arcbox*)malloc(sizeof(arcbox));//ArcType* q = pArc;
            q=p;
            p=p->tlink;
            delete q;
        }
        g.xlist[i].firstout = NULL;
        g.xlist[i].firstin = NULL;
    }
    g.arcnum = 0;
    g.vexnum = 0;
}
bool visit[maxnode];
void dfs(graph &g,int v)
{
    printf("%d(%d)->",v,g.xlist[v].data);
    visit[v]=true;
    arcbox* p=(arcbox*)malloc(sizeof(arcbox));
    p=g.xlist[v].firstout;
    while(p){
        int temp=p->tailvex;
        if(!visit[temp])dfs(g,temp);
        p=p->tlink;
    }
}
void rundfs(graph &g)
{
    //visitfunc=visit();
    //memset(visit,0,sizeof(visit));
    //预处理
    for(int v=0;v<g.vexnum;++v)visit[v]=false;
    for(int v=0;v<g.vexnum;++v)if(!visit[v])dfs(g,v);
}
int main(){
	//创建有向图
    //freopen("1.txt","r",stdin);
    graph g;
    creatDE(g);

    //深度优先遍历图
    cout << "\n深度优先遍历（次序（顶点的值））:" << endl;
    rundfs(g);
    printf("NULL\n\n");

    //销毁有向图
    DestroyGraph(g);
}


