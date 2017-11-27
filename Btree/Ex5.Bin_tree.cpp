#include<bits/stdc++.h>
/**   ABC##DE#G##F###   **/
using namespace std;
template<class T>
struct TreeNode
{
    TreeNode* Father;
    TreeNode* LeftChild;
    TreeNode* RightChild;
    T val;
};
template<class T>
struct BinTree
{
    TreeNode<T>* head;
    queue<TreeNode<T>*> rec;
    int leaves;
    void clq()
    {
        while(!rec.empty())
        {
            rec.pop();
        }
    }
    void create()
    {
        head=NULL;
        leaves=0;
    }
    void lftins(TreeNode<T>* h)
    {
        T y;
        cin>>y;
        if(y=='#')
        {
            h->LeftChild=NULL;
            return;
        }
        TreeNode<T>* ans=new TreeNode<T>;
        ans->val=y;
        h->LeftChild=ans;
        lftins(ans);
        rtins(ans);
    }
    void rtins(TreeNode<T>* h)
    {
        T y;
        cin>>y;
        if(y=='#')
        {
            h->RightChild=NULL;
            return;
        }
         TreeNode<T>* ans=new TreeNode<T>;
        ans->val=y;
        h->RightChild=ans;
        lftins(ans);
        rtins(ans);
    }
    void lins(TreeNode<T>* k)
    {
        if(head==NULL)
        {
            T y;
            cin>>y;
            TreeNode<T>*  ans=new TreeNode<T>;
            ans->val=y;
            head=ans;
            k=ans;
        }

        lftins(k);
        rtins(k);
    }
    void Ins(T ans)
    {
        TreeNode<T>* pre=head;
        TreeNode<T>* pos=new TreeNode<T>;
        pos->Father=NULL;
        pos->LeftChild=NULL;
        pos->RightChild=NULL;
        pos->val=ans;
        if(head==NULL)
        {
            head=pos;
        }
        else
        {
            while(1)
            {
                if(ans==pre->val)
                {
                    return;
                }
                else if(ans<pre->val)
                {
                    if(pre->LeftChild==NULL)
                    {
                        pos->Father=pre;
                        pre->LeftChild=pos;
                        return;

                    }
                    else pre=pre->LeftChild;
                }
                else
                {
                    if(pre->RightChild==NULL)
                    {
                        pos->Father=pre;
                        pre->RightChild=pos;
                        return;
                    }
                    else pre=pre->RightChild;
                }

            }
        }
    }
    void left_vis()
    {
        clq();
        rec.push(head);
        while(rec.empty()==0)
        {
            if(rec.front()->LeftChild!=NULL) rec.push(rec.front()->LeftChild);
            if(rec.front()->RightChild!=NULL) rec.push(rec.front()->RightChild);
            cout<<rec.front()->val<<' ';
            rec.pop();
        }
    }
    void right_vis()
    {
        clq();
        rec.push(head);
        while(rec.empty()==0)
        {
            if(rec.front()->RightChild!=NULL) rec.push(rec.front()->RightChild);
            if(rec.front()->LeftChild!=NULL) rec.push(rec.front()->LeftChild);
            cout<<rec.front()->val<<' ';
            rec.pop();
        }
    }
    void Preordered_vis(TreeNode<T>* tem)
    {
        if(tem==NULL) return;
        cout<<tem->val<<' ';
        Preordered_vis(tem->LeftChild);
        // cout<<tem->val;
        Preordered_vis(tem->RightChild);
        //cout<<tem->val;
    }
    void Midordered_vis(TreeNode<T>* tem)
    {
        if(tem==NULL) return;
        //cout<<tem->val;
        Midordered_vis(tem->LeftChild);
        cout<<tem->val<<' ';
        Midordered_vis(tem->RightChild);
        //cout<<tem->val;
    }
    void Postordered_vis(TreeNode<T>* tem)
    {
        if(tem==NULL) return;
        //cout<<tem->val;
        Postordered_vis(tem->LeftChild);
        // cout<<tem->val;
        Postordered_vis(tem->RightChild);
        cout<<tem->val<<' ';
    }
    int CountLeaves(TreeNode<T>* tem)
    {
        static int NUM=0;
        if(tem==NULL) return 0;
        if(tem->LeftChild==NULL&&tem->RightChild==NULL)
        {
            leaves++;
            return ++NUM;
        }
        if(tem->LeftChild!=NULL)
            CountLeaves(tem->LeftChild);
        if(tem->RightChild!=NULL)
            CountLeaves(tem->RightChild);
        return NUM;
    }
    bool Search(T chc)
    {
        TreeNode<T>* pos=head;
        if(head==NULL)
        {
            cerr<<"Empty Tree!\n";
            return false;
        }
        while(pos!=NULL)
        {
            if(pos->val==chc) return true;
            else if(pos->val>chc) pos=pos->LeftChild;
            else pos=pos->RightChild;
        }
        return false;
    }
    int Leaves()
    {
        return leaves;
    }
};
template<class T>
istream& operator >> (istream& ip, BinTree<T>& ans)
{
    cout<<"INPUT size of this Bin-Search Tree\n";
    int siz;
    ip>>siz;
    cout<<"Input Your sequence:\n";
    while(siz--)
    {
        T t_val;
        ip>>t_val;
        ans.Ins(t_val);
    }
    return ip;
}
int main()
{
    BinTree<char> p;
    p.create();
    //cin>>p;
    p.lins(p.head);
    cout<<"Preordered Visit Sequence\n";
    p.Preordered_vis(p.head);
    cout<<endl;
    cout<<"Midordered Visit Sequence\n";
    p.Midordered_vis(p.head);
    cout<<endl;
    cout<<"Postordered Visit Sequence\n";
    p.Postordered_vis(p.head);
    cout<<endl;
    cout<<"Left Visit Sequence\n";
    p.left_vis();
    cout<<endl;
    cout<<"Right Visit Sequence\n";
    p.right_vis();
    cout<<"\nNumber of Leaves\n";
    cout<<p.CountLeaves(p.head)<<endl;
    /* cout<<"Search For What? \n";
     int sig;
     cin>>sig;
     cout<<(  p.Search(sig)==true ? "Found!" : "NOT FOUND" );*/
    return 0;
}
