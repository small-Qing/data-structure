#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
#define defaultsize 256;
#define maxsize 256;
/*typedef char seqstring[maxsize];

//string define  states
typedef struct{
    char ch[maxsize];
    int curlength;
}seqstring;*/

//string define 动态适应扩展空间需要
typedef char *seqstring;
typedef struct{
    char *ch;
    int curlength;
    int maxsize;
}seqstring;
//memset
void initstring(seqstring s){
    s.ch=new char[defaultsize];
    if(s.ch==NULL)exit(1);
    s.ch[0]='\0';
    s.maxsize=defaultsize;
    s.curlength=0;
}
//解决空间溢出问题
#include<stdlib.h>
void overflowprocess(){
    char *newaddress=new char[2*maxsize];
    if(newaddress==NULL){
        cerr<<"memory allocation eroor"<<endl;
        exit(1);
    }
    int n=maxsize=2*maxsize;
    char *srcptr=ch;
    char *destptr newaddress;
    while(n--)*destptr++=*srcptr++;
    delete[]ch;
    ch=newaddress;
}

