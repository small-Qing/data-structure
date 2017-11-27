// 二叉排序树（动态），插入删除
#include<bits/stdc++.h>
using namespace std;
//二叉树的二叉链表存储表示
typedef struct binode{
    int data;
    binode *lchild,*rchild;
}binode,*bitree;

void init(bitree &root){
    root=NULL;
}
/* 
void destroy(bitree &root)
{
    if(root)
    {
        if(root->lchild)destroy(root->lchild);
        if(root->rchild)destroy(root->rchild);
        free(root);
        root=NULL;
    }
}
*/ 
// 在根指针T所指二叉排序树中递归地查找其关键字等于key的数据元素，若查找
// 成功，则指针p指向该数据元素结点，并返回TRUE，否则指针p指向查找路径上
// 访问的最后一个结点并返回FALSE,指针f指向T的双亲，其初始调用值为NULL
void searchleaf(bitree &root,int key,bitree f,bitree &p,bool &flag)
{
    if(!root){
    	p=f;
        flag=false;
        return ;
    }
    else if(key==(root->data)){
        p=root;
		flag=true;
		return;
    }
    else if(key<(root->data))searchleaf(root->lchild,key,root,p,flag);
    else if(key>(root->data))searchleaf(root->rchild,key,root,p,flag);
}
//找到并插入
bool insertleaf(bitree &root,int e)
{
    bitree p=NULL,s,f=NULL;
    bool flag=false;//找到 
    //p=(bitree)malloc(sizeof(binode));
    searchleaf(root,e,f,p,flag);
    //printf("%d--",p->data);
    if(!flag)//没找到
    {
        s=(bitree)malloc(sizeof(binode));
        s->data=e;
        s->lchild=s->rchild=NULL;
        if(!p)root=s;//没有树 
        else if(e<(p->data))p->lchild=s;
        else if(e>(p->data))p->rchild=s;
        return true;
    }
    else return false;// 树中已有关键字相同的结点，不再插入
}
//二分递归查找删除并重接 
void deleteone(bitree &p)
{
    bitree q,s;
    if(!p->rchild) // 右子树空则只需重接它的左子树（待删结点是叶子也走此分支）
   {
     q=p;
     p=p->lchild;
     free(q);
   }
   else if(!p->lchild) // 只需重接它的右子树
   {
     q=p;
     p=p->rchild;
     free(q);
   }
   else // 左右子树均不空
   {
     q=p;
     s=p->lchild;
     while(s->rchild) // 转左，然后向右到尽头（找待删结点的前驱）
     {
       q=s;
       s=s->rchild;
     }
     p->data=s->data; // s指向被删结点的＂前驱＂（将被删结点前驱的值取代被删结点的值）
     if(q!=p)//q是原来的p，p现在是p的前驱
       q->rchild=s->lchild; // 重接*q的右子树   先序，s替代p，左传递给p原来位置
     else
       q->lchild=s->lchild; // 重接*q的左子树     s没走，p只有他的一个左子树
     free(s);//p利用完s的值就可以删去s的结点
   }
}
bool DeleteBST(bitree &T,int &key)
{ // 若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素结点，
   // 并返回TRUE；否则返回FALSE。算法9.7
   if(!T) // 不存在关键字等于key的数据元素
     return false;
   else
   {
     if (key==T->data) // 找到关键字等于key的数据元素
       deleteone(T);
     else if (key<T->data)
       DeleteBST(T->lchild,key);
     else
       DeleteBST(T->rchild,key);
     return true;
   }
}
void orderprint(bitree &root)
{
	if(root==NULL)return;
	orderprint(root->lchild);
	printf("%d->",root->data);
	orderprint(root->rchild);
}
int main(){
	printf("input your node(-1==>null):\n");
	int n;
	bitree root=(bitree)malloc(sizeof(binode));
	init(root);
	while(cin>>n&&n>0){
		//cout<<n<<endl; 
		insertleaf(root,n);
	} 
	printf("\n\nprint you-input tree(order):\n");
	orderprint(root);
	printf("NULL");
	printf("\n\nDo you need to delete some node?(-1==>null):\n");
	while(cin>>n&&n>0){
		DeleteBST(root,n);
	}
	printf("print you-delete tree(order):\n");
	orderprint(root);
	printf("NULL\n");
    return 0;
}
