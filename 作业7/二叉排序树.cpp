// ��������������̬��������ɾ��
#include<bits/stdc++.h>
using namespace std;
//�������Ķ�������洢��ʾ
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
// �ڸ�ָ��T��ָ�����������еݹ�ز�����ؼ��ֵ���key������Ԫ�أ�������
// �ɹ�����ָ��pָ�������Ԫ�ؽ�㣬������TRUE������ָ��pָ�����·����
// ���ʵ����һ����㲢����FALSE,ָ��fָ��T��˫�ף����ʼ����ֵΪNULL
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
//�ҵ�������
bool insertleaf(bitree &root,int e)
{
    bitree p=NULL,s,f=NULL;
    bool flag=false;//�ҵ� 
    //p=(bitree)malloc(sizeof(binode));
    searchleaf(root,e,f,p,flag);
    //printf("%d--",p->data);
    if(!flag)//û�ҵ�
    {
        s=(bitree)malloc(sizeof(binode));
        s->data=e;
        s->lchild=s->rchild=NULL;
        if(!p)root=s;//û���� 
        else if(e<(p->data))p->lchild=s;
        else if(e>(p->data))p->rchild=s;
        return true;
    }
    else return false;// �������йؼ�����ͬ�Ľ�㣬���ٲ���
}
//���ֵݹ����ɾ�����ؽ� 
void deleteone(bitree &p)
{
    bitree q,s;
    if(!p->rchild) // ����������ֻ���ؽ���������������ɾ�����Ҷ��Ҳ�ߴ˷�֧��
   {
     q=p;
     p=p->lchild;
     free(q);
   }
   else if(!p->lchild) // ֻ���ؽ�����������
   {
     q=p;
     p=p->rchild;
     free(q);
   }
   else // ��������������
   {
     q=p;
     s=p->lchild;
     while(s->rchild) // ת��Ȼ�����ҵ���ͷ���Ҵ�ɾ����ǰ����
     {
       q=s;
       s=s->rchild;
     }
     p->data=s->data; // sָ��ɾ���ģ�ǰ����������ɾ���ǰ����ֵȡ����ɾ����ֵ��
     if(q!=p)//q��ԭ����p��p������p��ǰ��
       q->rchild=s->lchild; // �ؽ�*q��������   ����s���p���󴫵ݸ�pԭ��λ��
     else
       q->lchild=s->lchild; // �ؽ�*q��������     sû�ߣ�pֻ������һ��������
     free(s);//p������s��ֵ�Ϳ���ɾȥs�Ľ��
   }
}
bool DeleteBST(bitree &T,int &key)
{ // ������������T�д��ڹؼ��ֵ���key������Ԫ��ʱ����ɾ��������Ԫ�ؽ�㣬
   // ������TRUE�����򷵻�FALSE���㷨9.7
   if(!T) // �����ڹؼ��ֵ���key������Ԫ��
     return false;
   else
   {
     if (key==T->data) // �ҵ��ؼ��ֵ���key������Ԫ��
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
