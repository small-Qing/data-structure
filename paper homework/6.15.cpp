 #include<bits/stdc++.h>
 using namespace std;
  
  enum PointerTag // ö��
 {Link,Thread}; // Link(0):ָ��,Thread(1):����
 struct BiThrNode
 {
   TElemType data;
   BiThrNode *lchild,*rchild; // ���Һ���ָ��
   PointerTag LTag,RTag; // ���ұ�־
 };
 typedef BiThrNode *BiThrTree;
 
 Status CreateBiThrTree(BiThrTree &T)
 { // ��������������������н���ֵ,�������������T
   // 0(����)/�ո�(�ַ���)��ʾ�ս��
   TElemType h;
 #if CHAR
   scanf("%c",&h);
 #else
   scanf("%d",&h);
 #endif
   if(h==Nil)
     T=NULL;
   else
   {
     T=(BiThrTree)malloc(sizeof(BiThrNode));
     if(!T)
       exit(OVERFLOW);
     T->data=h; // ���ɸ����(����)
     CreateBiThrTree(T->lchild); // �ݹ鹹��������
     if(T->lchild) // ������
       T->LTag=Link;
     CreateBiThrTree(T->rchild); // �ݹ鹹��������
     if(T->rchild) // ���Һ���
       T->RTag=Link;
   }
   return OK;
 }
 
 Status InOrderThreading(BiThrTree &Thrt,BiThrTree T)
 { // �������������T,����������������,Thrtָ��ͷ��㡣�㷨6.6
   if(!(Thrt=(BiThrTree)malloc(sizeof(BiThrNode))))
     exit(OVERFLOW);
   Thrt->LTag=Link; // ��ͷ���
   Thrt->RTag=Thread;
   Thrt->rchild=Thrt; // ��ָ���ָ
   if(!T) // ���������գ�����ָ���ָ
     Thrt->lchild=Thrt;
   else
   {
     Thrt->lchild=T;
     pre=Thrt;
     InThreading(T); // ���������������������
     pre->rchild=Thrt;
     pre->RTag=Thread; // ���һ�����������
     Thrt->rchild=pre;
   }
   return OK;
 }
 
