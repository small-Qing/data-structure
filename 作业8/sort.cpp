#include<bits/stdc++.h>
using namespace std;
#define masize 25
struct sqlist{
	int key[masize];
	int length;
};
//直接 
void insertsort(sqlist &l,sqlist &b){
	int i,j;
	b.length=l.length;
	for(i=1;i<=b.length;i++)b.key[i]=l.key[i];
	for(i=2;i<=b.length;i++){
		if(b.key[i]<b.key[i-1]){
			b.key[0]=b.key[i];
			j=i-1;
			while(b.key[j]>b.key[0]){
				b.key[j+1]=b.key[j];
				j--;
			}
			b.key[j+1]=b.key[0];
		}
	}
}
//折半 
void binsort(sqlist &l,sqlist &b){
	int i,j,mid,low,high;
	b.length=l.length;
	for(i=1;i<=b.length;i++)b.key[i]=l.key[i];
	for(i=2;i<=b.length;i++){
		b.key[0]=b.key[i];
		low=1;
		high=i-1;
		while(low<=high){
			mid=(low+high)>>1;
			if(b.key[0]<b.key[mid])high=mid-1;
			else low=mid+1;
		}//找到一个比bi小的数b[high] ,high+1及以后都必须往后移 
		for(j=i-1;j>high;j--)b.key[j+1]=b.key[j];
		b.key[high+1]=b.key[0]; 
	}
}
void print(sqlist a){
	for(int i=1;i<a.length;i++)cout<<a.key[i]<<"-";
	cout<<a.key[a.length]<<".";
}
//快速
int part(sqlist &b,int low,int high){
	int i,j,mid=b.key[low];
	while(low<high){
		while(low<high&&b.key[high]>=mid)high--;//这时key[high]<mid 
		b.key[low]=b.key[high];
		while(low<high&&b.key[low]<=mid)low++;//这时key[low]>mid 
		b.key[high]=b.key[low]; 
	}
	b.key[low]=mid;
	return low;
} 
void qsort(sqlist &l,int low,int high){
	int mid;
	if(low<high){
		mid=part(l,low,high);
		qsort(l,low,mid-1);
		qsort(l,mid+1,high);
	} 
}
//简单选择排序
void selectsort(sqlist &l){
	for(int i=1;i<=l.length;i++){
		for(int j=i+1;j<=l.length;j++)
		if(l.key[j]<l.key[i]){
			int temp=l.key[i];
			l.key[i]=l.key[j];
			l.key[j]=temp;
		}
	}
} 
//堆排序
//筛选 
void  heapadjust(sqlist &l,int s,int m){
	int rc=l.key[s];
	for(int i=s*2;i<=m;i*=2){//左子结点-》左孙结点 
		if(i<m&&l.key[i]<l.key[i+1])i++;//范围内且左子小于右子====》j指向右子（更大）
		if(rc>=l.key[i])break;//root>=右子（不操作）
		l.key[s]=l.key[i];//root==>右子 
		s=i; 
	}
	l.key[s]=rc;//原来的右子变成root 
} 
void heapsort(sqlist &l){
	for(int i=l.length>>1;i>0;i--){
		heapadjust(l,i,l.length);//总的建成1-length大顶堆 
	}
	for(int i=l.length;i>1;i--){
		int temp=l.key[1];
		l.key[1]=l.key[i];
		l.key[i]=temp;
		heapadjust(l,1,i-1);
	}
}
int main(){
	struct sqlist a,b;
	int n;
	printf("input your sqlist size:");
	scanf("%d",&a.length);
	printf("\ninput your sqlist:\n");
	for(int i=1;i<=a.length;i++){
		scanf("%d",&a.key[i]);
		//b.key[i]=a.key[i];
	}
	printf("\n1:直接排序\n2:折半排序\n3:快速排序\n4:选择排序\n5:堆排序\ninput your choose-sort:");
	scanf("%d",&n);
	if(n==1){
		insertsort(a,b);
		print(b);
	}
	else if(n==2){
		binsort(a,b);
		print(b);
	} 
	else if(n==3){
		b.length=a.length;
		for(int i=1;i<=b.length;i++)b.key[i]=a.key[i];
		qsort(b,1,b.length);
		print(b);
	}
	else if(n==4){
		b.length=a.length;
		for(int i=1;i<=b.length;i++)b.key[i]=a.key[i];
		selectsort(b);
		print(b);
	}
	else if(n==5){
		b.length=a.length;
		for(int i=1;i<=b.length;i++)b.key[i]=a.key[i];
		heapsort(b);
		print(b);
	}
	return 0;
} 
