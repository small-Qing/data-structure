#include<iostream>;
#include"astring.h"
using namespace std;
Astring::Astring(int sz){
    maxsize=sz;
    ch=new char[maxsize+1];
    if(ch==NULL){cerr<<"ALLOCATION ERROR!\n";exit(1);}
    curlength=0;
    ch[0]='\0';
};
Astring::Astring(const char *init)
{
    int len=strlen(init);
    maxsize=(len>defaultsize)?len:defaultsize;
    ch=new char[maxsize];
    if(ch==NULL){cerr<<"ALLOCATION ERROR\n";exit(1);}
    curlength=len;
    strcpy(ch,init);
};
Astring::Astring(const Astring& ob)
{
    maxsize=ob.maxsize;
    ch=new char[maxsize+1];
    if(ch==NULL){cerr<<"ALLOCATION ERROR\n";exit(1);}
    curlength=ob.curlength;
    strcpy(ch,ob.ch);
};
//substr
Astring Astring::operator()(int pos,int len)
{
    Astring temp;
    if(pos<0||pos+len-1>=maxsize||len<0)
    {
        temp.curlength=0;temp.ch[0]='\0';
    }
    else {
        if(pos+len-1>-curlength)len=curlength-pos;
        temp.curlength=len;
        for(int i=0,j=pos;i<len;i++,j++)temp.ch[i]=ch[j];
        temp.ch[len]='\0';
    }
    return temp;
};

Astring& Astring::operator=(const Astring& ob)
{
    if(&ob!=this){
        delete []ch;
        ch=new char[ob.maxsize];
        if(ch==NULL){cerr<<"ALLOCATION ERROR\n";exit(1);}
        curlength=ob.curlength;
        strcpy(ch,ob.ch);
    }
    else cout<<"字符串自身赋值出错\n";
    return *this;
};
Astring& Astring::operator+=(const Astring& ob)
{
    char *temp=ch;
    int n=curlength+ob.curlength;
    int m=(maxsize>=n)?maxsize:n;
    ch=new char[m];
    if(ch==NULL){cerr<<"ALLOCATION ERROR\n";exit(1);}
    maxsize=m;
    curlength=n;
    strcpy(ch,temp);
    strcat(ch,ob.ch);
    delete []temp;
    return *this;
};
char Astring::operator[](int i){
    if(i<0||i>=curlength){
        cerr<<"下标超界\n";exit(1);
    }
    return ch[i];
};
int Astring::findd(Astring& pat,int k)const//从ch[k]开始找pat匹配的串 只能找一次
{
    int i,j;
    for(i=k;i<=curlength-pat.curlength;i++)
    {
        for(j=0;j<pat.curlength;j++)if(ch[i+j]!=pat.ch[j])break;
        if(j==pat.curlength)return i;
    }
    return -1;
}

//KMP
void Astring::getnext(int next[])
{
    int j=0,k=-1,lengthp=curlength;
    next[0]=-1;
    while(j<lengthp){
        if(k==-1||ch[j]==ch[k]){
            j++;k++;
            next[j]=k;
        }
        else k=next[k];
    }
};
int Astring::fastfind(Astring& pat,int k,int next[])const{
    int posp=0,post=k;
    int lengthp=pat.curlength;//target string
    int lengtht=curlength;
    while(posp<lengthp&&post<lengtht)
    if(posp==-1||pat.ch[posp]==ch[post]){
        posp++;post++;
    }else posp=next[posp];
    if(posp<lengthp)return -1;
    else return post-lengthp;
};
