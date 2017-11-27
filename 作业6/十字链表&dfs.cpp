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
//��
typedef struct arcbox{
    int tailvex,headvex;//head  rear 's  pos
    struct arcbox *hlink,*tlink;//��ͷ/β��ͬ����
}arcbox;
//����
typedef struct vnode
{
  int data;
  arcbox *firstin,*firstout;//��ĵ�һ���뻡
}vexnode;
//ͼ
typedef struct{
    vexnode xlist[maxnode];//ʮ������
    int vexnum,arcnum;
}graph;

void creatDE(graph &g){//����ͼ
    printf("����ĸ����Լ�����:\n");
    scanf("%d %d",&g.vexnum,&g.arcnum);
    //�������ͼ�ĵ�
    printf("������%d�������ֵ(���ֱ������):\n",g.vexnum,maxnode);
    for(int i=0;i<g.vexnum;i++){
        scanf("%d",&g.xlist[i].data);//���Ȩֵ
        g.xlist[i].firstin=NULL;
        g.xlist[i].firstout=NULL;
    }
    int start,post;
    printf("������%d�����Ļ�ͷ�ͻ�β(�ո�Ϊ���):\n",g.arcnum);
    //���뻡
    for(int k=0;k<g.arcnum;k++){
        scanf("%d %d",&start,&post);
        int i=start-1;
        int j=post-1;
        arcbox* p=(arcbox*)malloc(sizeof(arcbox));//p===>��
        arcbox* q=(arcbox*)malloc(sizeof(arcbox));
		p->hlink=NULL;p->tlink=NULL;
        q->hlink=NULL;q->tlink=NULL;
        if((i>=0&&i<13)&&(j>=0&&j<13)){
        	p->tailvex=j;
        	p->headvex=i;

        	q->tailvex=i;
        	q->headvex=j;
        /* ������뻡�ͳ��������ͷ�Ĳ��� */
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
 { /* ��ʼ����: ����ͼG����,v��G��ĳ������ */
   /* �������: ��v����ֵvalue */
   int i;
   i=v-1;//λ�þ���v-1
   if(i<0) /* v����G�Ķ��� */
     return 0;
   g.xlist[i].data=value;//strcpy(g.xlist[i].data,value);
   return 1;
}
//�󶥵�Ķȣ���ʮ�������л���ͦ����ģ���Ϊ�����ڽӱ������ڽӱ�Ľ����
/*int GetVertexDegree( const graph &g,int val )
{
    int m =val-1;  //�õ�������ڶ�����е�����
    if ( -1 == m )
        return -1;
    int TD = 0;
    //�������
    ArcType* pArcOut = G.crossList[m].firstout;
    while ( pArcOut )
    {
        ++TD;
        pArcOut = pArcOut->taillink;
    }

    //���ۼ����
    ArcType* pArcIn = G.crossList[m].firstin;
    while( pArcIn )
    {
        ++TD;
        pArcIn = pArcIn->headlink;
    }
    return TD;
}
*/
//����ͼ
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
    //Ԥ����
    for(int v=0;v<g.vexnum;++v)visit[v]=false;
    for(int v=0;v<g.vexnum;++v)if(!visit[v])dfs(g,v);
}
int main(){
	//��������ͼ
    //freopen("1.txt","r",stdin);
    graph g;
    creatDE(g);

    //������ȱ���ͼ
    cout << "\n������ȱ��������򣨶����ֵ����:" << endl;
    rundfs(g);
    printf("NULL\n\n");

    //��������ͼ
    DestroyGraph(g);
}


