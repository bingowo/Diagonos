#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int T,n;
struct node{
	long long val;
	int cnt;
}num[10005];
int solve(long long x){
	int tmp=0;
	unsigned long long val=x;
	while(val){
		if(val&1) tmp++;
		val>>=1;
	}
	return tmp;
} 
int cmp(const void *a,const void *b){
	struct node va=*(struct node*)a,vb=*(struct node*)b;
	if(va.cnt!=vb.cnt) return vb.cnt-va.cnt;
	else if(vb.val>va.val) return -1;
	else return 1;
}
int main(){
	scanf("%d",&T);
	for(int c=0;c<T;c++){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%lld",&num[i].val);
			num[i].cnt=solve(num[i].val);
		} 
		qsort(num,n,sizeof(struct node),cmp);
		printf("case#%d:\n",c);
		for(int i=0;i<n;i++) printf("%lld ",num[i].val);
		puts("");
	}
	return 0;
}