//假设稀疏矩阵A,B均以三元组顺序表作为存储结构，写出矩阵相加的算法，C存放结果 
#include<bits/stdc++.h>
using namespace std;
#define maxsize 100
typedef struct olnode{
	int i,j;//r,c
	int key;
	//struct olnode *right,*down;
}triple;
typedef struct{
	triple data[maxsize+1];
	int mu,nu,tu;
}tsmatrix;

void print(tsmatrix &a){
	for(int i=1;i<=a.mu;i++){
		for(int j=1;j<=a.nu;j++){
			//int flag=0;
			for(int p=0;p<a.mu*a.nu;p++)
			{
				if(a.data[p].i==i&&a.data[p].j==j){
				printf("%d ",a.data[p].key);
				//flag=1;
				break;
				}	
			}
			//if(!flag)printf("0 ");
			if(j==a.nu)printf("\n");
			//else printf()
		}
	}
}
void add(tsmatrix &a,tsmatrix &b,tsmatrix &m){
		m.mu=b.mu;
		m.nu=b.nu;
		int sum=m.mu*m.nu;
		int p=0;
		for(int i=1;i<=m.mu;i++){
			for(int j=1;j<=m.nu;j++){
				m.data[p].i=i;
				m.data[p].j=j;
				m.data[p].key=0;
				int k;
				for(k=0;k<sum;k++){
					if(a.data[k].i==i&&a.data[k].j==j){
						m.data[p].key+=a.data[k].key;
						break;
					}
				}
				for(k=0;k<sum;k++){
					if(b.data[k].i==i&&b.data[k].j==j){
						m.data[p].key+=b.data[k].key;
						break;
					}
				}
				p++;
			}
		}
		m.tu=p;
	
	
}
int main(){
	tsmatrix a;
	tsmatrix b;
	tsmatrix m;	
	int c=1,r=1,x,p=0,i,j;
	//freopen("1.txt","r",stdin);
	printf("input you matrix a`s r and c:\n");
	scanf("%d %d",&r,&c);
	a.mu=r;
	a.nu=c;
	a.tu=0;
	p=0;
	printf("\n\ninput you matrix a:\n");
	for(i=1;i<=r;i++){
		for(j=1;j<=c;j++){
			scanf("%d",&x);
			a.data[p].i=i;
			a.data[p].j=j;
			a.data[p].key=x;
			p++;
			if(x>0)a.tu++;	
		}
	}
	//printf("a.r=%d a.c=%d a.tol=%d\n",a.mu,a.nu,a.tu);
	//print(a);
	
	printf("\n\ninput you matrix b`s r and c:\n");
	scanf("%d %d",&r,&c);
	b.mu=r;
	b.nu=c;
	b.tu=0;
	p=0;
	printf("\n\ninput you matrix b:\n");
	for(i=1;i<=r;i++){
		for(j=1;j<=c;j++){
			scanf("%d",&x);
			b.data[p].i=i;
			b.data[p].j=j;
			b.data[p].key=x;
			p++;
			if(x>0)	b.tu++;
		}
	}
	//printf("b.r=%d b.c=%d b.tol=%d\n",b.mu,b.nu,b.tu);
	//print(b);
	if(b.mu==a.mu&&b.nu==a.nu){
		add(a,b,m);
		printf("\n\n\nthis you add_mastrix m:\n");
		print(m);
	}else printf("add failed!!!!");
	return 0;	
} 
