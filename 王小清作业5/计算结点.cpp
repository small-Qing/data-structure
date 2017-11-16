#include<bits/stdc++.h>
//#include"stdafx.h"
using namespace std;
//#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define ERROR 0
//������,��������
typedef struct Bitnode//2��ָ��
{
    char data;
    struct Bitnode *lchild,*rchild;//�����Լ��������Ҫָ�� 
}Bitnode,*Bitree;//ָ���Ѿ�����õ�һ������   bitree 
char ch;
int sum=0;
//�����������������������ո��ǿ���     ���������//c++p202
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

//�������,����ݹ�
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

//�������
void inordertraverse(Bitree root)
{
	//����
	if (root==NULL)return;
	//���ǿ�
	Bitree  p = root;
	stack<Bitree> s;
	while (!s.empty()||p)
	{
		//һֱ���������������±ߣ��߱����߱�����ڵ㵽ջ��
		while (p)
		{
			s.push(p);
			p = p->lchild;
		}
		//��pΪ��ʱ��˵���Ѿ��������������±ߣ���ʱ��Ҫ��ջ��
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			printf("%c ",p->data);
			//��������������ʼ�µ�һ������������(���ǵݹ������ʵ��)
			p = p->rchild;
		}
	}
}
//�������
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
//������� 
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
    printf("input your bitree(preorder,#Ϊ�����ֹ):\n");
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






/*void Leaf1(BiTree T)//�������ͳ��Ҷ�ӽڵ���Ŀ  
{  
    if(T!=NULL)  
    {  
        Leaf1(T->Lchild);  
        Leaf1(T->Rchild);  
        if(T->Lchild==NULL&&T->Rchild==NULL)  
            ans++;  
    }  
}  
  
int Leaf2(BiTree T)//���η�ͳ��Ҷ�ӽڵ���Ŀ  
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

