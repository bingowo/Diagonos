#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LL long long
int D,n;
struct node{
	int k,s;
}A[1005];
int cmp(const void* a,const void* b){
	node x=*(node *)a,y=*(node *)b;
	return x.k-y.k;
}
double T[1005];
int main() {
	scanf("%d%d",&D,&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&A[i].k,&A[i].s);
	qsort(A+1,n,sizeof(struct node),cmp);
	T[n+1]=-1e9;
	for(int i=n;i;i--){
		T[i]=1.0*(D-A[i].k)/A[i].s;
		if(T[i+1]>T[i]) T[i]=T[i+1];
	}
	printf("%.6f",1.0*D/T[1]);
	return 0;
}