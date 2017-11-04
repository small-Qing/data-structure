//串的置换 
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
char s[500];
//#define OVERFLOW -2
typedef struct{
	char *ch;
	int length;
}Hstring;
void strsign(Hstring &t,char *chars){
	if(t.ch)free(t.ch);
	int i,k;
	char *c;
	for(i=0,c=chars;*c;++i,++c);
	if(!i){
		t.ch=NULL;
		t.length=0;
	}
	else {
		if(!(t.ch=(char*)malloc(100*sizeof(char))))exit(OVERFLOW);
		for(k=0;k<i;k++)t.ch[k]=chars[k];
		t.length=i; 
	}
	//return true;
}

void replace(Hstring &s,char *T,char *V){//t改v 
	int i=0,j,k;
	char t[100]; 
	//search 并 代替 
	for(i=0;i<s.length;){
		k=0;
		if(T[0]==s.ch[i]){
			bool tryone=1;
			for(j=1;j<strlen(T);j++){
				if(T[j]!=s.ch[i+j]){
					tryone=0;break;
				}	
			}
			if(tryone&&(strlen(V)>=strlen(T))){//a<b
				//int len=;//最新的长度 
				int x=strlen(V)-strlen(T);
				for(j=s.length-1;j>=(i+strlen(T));j--)s.ch[x+j]=s.ch[j];//j==i+strlen(t)
				for(j=i+strlen(T)-1,k=strlen(V)-1;j>i-1,k>=0;j--,k--)s.ch[x+j]=V[k];
			}
			else if(tryone){//a>b
				int x=strlen(V)-strlen(T);
				for(j=i+strlen(T);j<=s.length-1;j++)s.ch[x+j]=s.ch[j];//j==i+strlen(t)
				for(j=i+strlen(T)-1,k=strlen(V)-1;j>i-1&&k>=0;j--,k--)s.ch[x+j]=V[k];
			}
			s.length=s.length+(strlen(V)-strlen(T));
			i+=strlen(V);
		}
		else i++; 
	}	
}
int main()
{
	char a[100],b[100];
	int i=0,k;
	printf("input your string:\n");
	scanf("%s",a);
	//printf("%d\n",strlen(a));
	Hstring t;
	strsign(t,a);//新建 
	//输入要求 
	printf("input your need-to-change_string:\n");
	scanf("%s",a);
	printf("input your need-to-replace_string:\n");
	scanf("%s",b);
	replace(t,a,b);
	//输出 
	printf("this is you new string:\n");
	//replace(t,a,b)
	printf("%s",t.ch);
	
	return 0;
 } 
