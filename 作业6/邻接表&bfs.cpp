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

//ͼ���ڽӱ�洢��ʾ
#define MAX_NUM 20
enum GraphKind{GY,GN}; // {����ͼ,����ͼ}
typedef struct ArcNode
{
   int adjvex; // �û���ָ��Ķ����ߵ���һ�������λ�� ����
   struct ArcNode *nextarc; // ָ����һ������ߵ�ָ��
   //InfoType *info; // �뻡��������Ϣ��ָ�루���ޣ�
}ArcNode;// ���� ������
typedef struct
{
   int data; // ������Ϣ  ��Ȩ��
   ArcNode *firstarc; // ��һ������ĵ�ַ,ָ���һ�������ö���Ļ���ߵ�ָ��
}VNode; // ͷ���
struct graph
{
   VNode xlist[MAX_NUM];//AdjList vertices;
   int vexnum,arcnum; // ͼ�ĵ�ǰ�������ͻ����ߣ���
   //GraphKind kind; // ͼ�������־
};

int locate(graph &g,int val)
{
    int i;
    for(i=0;i<g.vexnum;i++)if(g.xlist[i].data==val)return i;
    return -1;
}
void creat(graph &g){
    printf("����ĸ����Լ�����:\n");
    scanf("%d %d",&g.vexnum,&g.arcnum);
    //�������ͼ�ĵ�
    printf("������%d�������ֵ(���ֱ������):\n",g.vexnum);
    for(int i=0;i<g.vexnum;i++){
        scanf("%d",&g.xlist[i].data);
        g.xlist[i].firstarc=NULL;
        //g.xlist[i].firstout=NULL;
    }
    printf("������%d�����Ļ�ͷ�ͻ�β(�ո�Ϊ���):\n",g.arcnum);
    int va,vb;
    for(int k=0;k<g.arcnum;++k) // �����������
   {
     scanf("%d %d",&va,&vb);
     int i=locate(g,va); // ��β
     int j=locate(g,vb); // ��ͷ
     ArcNode* p=(ArcNode*)malloc(sizeof(ArcNode));//��
     p->adjvex=j;
       //p->info=NULL; // ͼ
     p->nextarc=g.xlist[i].firstarc; // ���ڱ�ͷ  p.nextָ���һ����
     g.xlist[i].firstarc=p;

     ArcNode* q=(ArcNode*)malloc(sizeof(ArcNode));
     q->adjvex=i;
     q->nextarc=g.xlist[j].firstarc; // ���ڱ�ͷ
     g.xlist[j].firstarc=q;
    }
}

void DestroyGraph(graph &g)
{ // ��ʼ����: ͼG���ڡ��������: ����ͼG
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


/* ����ͼGp��pos���㣨���Ϊpos�Ķ��㣩�ĵ�һ���ڽӶ������ţ���������ڣ��򷵻�-1 */
int first_vertex(graph g,int pos)
{
    if(g.xlist[pos].firstarc)  //��������ڽӶ��㣬���ص�һ���ڽӶ�������
        return  g.xlist[pos].firstarc->adjvex;
    else              //��������ڣ��򷵻�-1
        return -1;
}

/* cur������pos���㣨cur��pos��Ϊ�������ţ�������һ���ڽӶ��㣬
����ͼGp�У�pos����ģ������cur���㣩��һ���ڽӶ�������,��������ڣ��򷵻�-1 */
int next_vertex(graph g,int pos,int cur)
{
    ArcNode *p = g.xlist[pos].firstarc; //p��ʼָ�򶥵�ĵ�һ���ڽӵ�
    //ѭ��pos�ڵ��Ӧ������ֱ��pָ�����Ϊcur���ڽӵ�
    while(p->adjvex!= cur)p = p->nextarc;
    //������һ���ڵ�����
    if(p->nextarc)
        return p->nextarc->adjvex;
    else
        return -1;
}

bool visited[MAX_NUM];
/*
//������ȱ���
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
        //ѭ��������������pVertex����������ڽӶ���,�������ʺ���ڽӶ������
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
    //Ԥ����
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
    for (int i = 0; i < g.vexnum; i++)//��ʼ�����ʱ�־����
        visited[i] = false;

    queue<int> q;

    for (int i = 0; i < g.vexnum; i++)
    {
        if (!visited[i])//���û�з��ʹ�
        {
            visited[i] = true;
            q.push(i);//���ʹ��������
            printf("%d(%d)->",i,g.xlist[i].data);
            while (!q.empty())//���в�Ϊ��ʱ
            {
                int x = q.front();
                q.pop();//��ȡ�����׵�һ��Ԫ�أ�Ȼ�󽫵�һ��Ԫ��ɾ��
                ArcNode * p = g.xlist[x].firstarc;
                while (p)//����δ�����ʹ����ڽӶ���
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
	//��������ͼ
    //freopen("1.txt","r",stdin);
    graph g;
    creat(g);

    //������ȱ���ͼ
    cout << "\n������ȱ��������򣨶����ֵ����:" << endl;
    BFSTraverse(g);
    printf("NULL\n\n");


    //��������ͼ
    DestroyGraph(g);
}



