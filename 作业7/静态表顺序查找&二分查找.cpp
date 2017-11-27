#include<bits/stdc++.h>
using namespace std;
const int maxsum=50;
typedef struct
{
    int elem[maxsum]; // 数据元素存储空间基址，建表时按实际长度分配，0号单元留空
    int length; // 表长度
}SSTable;
//顺序查找
int searchseq(SSTable st,int key)
{
    st.elem[0]=key;
    int i=st.length;
    while(st.elem[i]!=key&&i>0){
        i--;
    }
    return i; 
}
//折半查找
int searchbin(SSTable st,int key,int l,int r)
{
    if(l==r&&key!=st.elem[l])return 0;
    else {
        int mid=(l+r)/2;
        if(key==st.elem[mid])return mid;
        else if(key<st.elem[mid])searchbin(st,key,l,mid-1);
        else searchbin(st,key,mid+1,r);
    }
    //return 0;
}

int main()
{
    freopen("1.txt","r",stdin);
    int a[maxsum];
    SSTable st;
    printf("input your sum of key:");
    int k,n;
    scanf("%d",&k);
    printf("input your bitree:\n");
    for(int i=1;i<=k;i++)scanf("%d",&st.elem[i]);
    st.length=k;
    printf("\n\ninput your requirement:");
    scanf("%d",&n);
    printf("\n\n this is seqsearch find:");
    int x=searchseq(st,n);
    if(x)printf("%d\n",x);
    else printf("there is not your requirement!\n");
    
    printf("\n\n this is binsearch(had sorted) find:");
    sort(st.elem+1,st.elem+k+1);
    int y=searchbin(st,n,1,k);
    if(y)printf("%d\n\n",y);
    else printf("there is not your requirement!\n");
    return 0;
}
