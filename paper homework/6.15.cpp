 #include<bits/stdc++.h>
 using namespace std;
  
  enum PointerTag // 枚举
 {Link,Thread}; // Link(0):指针,Thread(1):线索
 struct BiThrNode
 {
   TElemType data;
   BiThrNode *lchild,*rchild; // 左右孩子指针
   PointerTag LTag,RTag; // 左右标志
 };
 typedef BiThrNode *BiThrTree;
 
 Status CreateBiThrTree(BiThrTree &T)
 { // 按先序输入二叉线索树中结点的值,构造二叉线索树T
   // 0(整型)/空格(字符型)表示空结点
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
     T->data=h; // 生成根结点(先序)
     CreateBiThrTree(T->lchild); // 递归构造左子树
     if(T->lchild) // 有左孩子
       T->LTag=Link;
     CreateBiThrTree(T->rchild); // 递归构造右子树
     if(T->rchild) // 有右孩子
       T->RTag=Link;
   }
   return OK;
 }
 
 Status InOrderThreading(BiThrTree &Thrt,BiThrTree T)
 { // 中序遍历二叉树T,并将其中序线索化,Thrt指向头结点。算法6.6
   if(!(Thrt=(BiThrTree)malloc(sizeof(BiThrNode))))
     exit(OVERFLOW);
   Thrt->LTag=Link; // 建头结点
   Thrt->RTag=Thread;
   Thrt->rchild=Thrt; // 右指针回指
   if(!T) // 若二叉树空，则左指针回指
     Thrt->lchild=Thrt;
   else
   {
     Thrt->lchild=T;
     pre=Thrt;
     InThreading(T); // 中序遍历进行中序线索化
     pre->rchild=Thrt;
     pre->RTag=Thread; // 最后一个结点线索化
     Thrt->rchild=pre;
   }
   return OK;
 }
 
