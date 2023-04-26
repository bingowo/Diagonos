#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
typedef struct{
	int num;
	int cnt;
} p;
int cmp1(const void *x,const void *y){
	int t1=(*(p *)x).cnt,t2=(*(p *)y).cnt;
	if(t1!=t2)	return t2-t1;
	else return (*(p *)x).num-(*(p *)y).num;
}
int c(int x){
	int ans=0;
	for(int i=0;i<=63;i++){
		if(x & 1==1) ans++;
		x=x>>1; 
	}
	return ans;
}
int main(){
	int i,j,n,t;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		p a[10005];
		scanf("%d",&t);
		for(j=0;j<t;j++){
			scanf("%d",&a[j].num);
			a[j].cnt=c(a[j].num);
		}
		qsort((void *)a,t,sizeof(p),cmp1);
		printf("case #%d:\n",i);
		for(j=0;j<t;j++){
		  printf("%d ",a[j].num);
		}
		printf("\n");
	}
}