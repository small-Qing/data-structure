#include<bits/stdc++.h>
//#include"stdafx.h"
using namespace std;
//#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define ERROR 0
//二叉树,二叉链表
typedef struct Bitnode//2阶指针
{
    char data;
    struct Bitnode *lchild,*rchild;//引用自己本身必须要指针 
}Bitnode,*Bitree;//指针已经定义好的一个类型   bitree 
char ch;
int sum=0;
//先序次序依次输入二叉树，空格是空树     构造二叉树//c++p202
void createbitree(Bitree* root)//bitree*    
{
	scanf("%c",&ch);
	if(ch=='\n')return;
    else if(ch=='#'||ch==' '){
        *root=NULL;
		//return NULL;
    }
    else {
		*root=(Bitree)malloc(sizeof(Bitnode));//bitnode->*bittree
		(*root)->data=ch;
    	//printf("input=%c\n",ch);
    	//i++;
    	createbitree(&(*root)->lchild);
    	createbitree(&(*root)->rchild);
	}
	//return root;
}

//先序遍历,输出递归
void preordertraverse(Bitree T,int &sum)
{
    if(T==NULL)return;
    else if(T->lchild==NULL&&T->rchild==NULL)sum++;
	printf("%c ",T->data); 
    preordertraverse(T->lchild,sum);
    //sum++;
    preordertraverse(T->rchild,sum);
    return;
}

//中序遍历
void inordertraverse(Bitree root)
{
	//空树
	if (root==NULL)return;
	//树非空
	Bitree  p = root;
	stack<Bitree> s;
	while (!s.empty()||p)
	{
		//一直遍历到左子树最下边，边遍历边保存根节点到栈中
		while (p)
		{
			s.push(p);
			p = p->lchild;
		}
		//当p为空时，说明已经到达左子树最下边，这时需要出栈了
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			printf("%c ",p->data);
			//进入右子树，开始新的一轮左子树遍历(这是递归的自我实现)
			p = p->rchild;
		}
	}
}
//后序遍历
void PostOrderBiTree(Bitree T)
{
    if (T== NULL)
    {
        return;
    }
    else
    {
        PostOrderBiTree(T->lchild);
        PostOrderBiTree(T->rchild);
        printf("%c ",T->data);
    }
}
//计算层数 
int TreeDeep(Bitree T)
{
    int deep = 0;
    if (T != NULL)
    {
        int leftdeep = TreeDeep(T->lchild);
        int rightdeep = TreeDeep(T->rchild);
        deep = leftdeep >= rightdeep?leftdeep+1:rightdeep+1;
    }
    return deep;
}
//test
int main()
{
    printf("input your bitree(preorder,#为输入截止):\n");
    //scanf("%s",a);
    char k;
    int i=0;
    int sum=0;
    //printf("a=%s\n",a);
    Bitree root;
    createbitree(&root);
    printf("\nthis is preorder:\n");
    preordertraverse(root,sum);
    printf("\nthis is inorder:\n");
    inordertraverse(root);
    printf("\nthis is postorder:\n");
    PostOrderBiTree(root);
	printf("\nbitree-node-sum=%d\n",sum);
    return 0;
}






/*void Leaf1(BiTree T)//后序遍历统计叶子节点数目  
{  
    if(T!=NULL)  
    {  
        Leaf1(T->Lchild);  
        Leaf1(T->Rchild);  
        if(T->Lchild==NULL&&T->Rchild==NULL)  
            ans++;  
    }  
}  
  
int Leaf2(BiTree T)//分治法统计叶子节点数目  
{  
    int count;  
    if(T==NULL)  
        count=0;  
    else if(T->Lchild==NULL&&T->Rchild==NULL)  
        count=1;  
    else  
        count=Leaf2(T->Lchild)+Leaf2(T->Rchild);  
    return count;  
}  */ 

