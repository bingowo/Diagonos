#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{long long num,k;}N;
int cmp(const void *a,const void *b){
	if(((N*)b)->k==((N*)a)->k) return ((N*)a)->num-((N*)b)->num;
	return ((N*)b)->k-((N*)a)->k;
}
int main(){
	long long t,i,j,p,flag,n;
	N q[10010];
	scanf("%lld",&t);
	for(i=0;i<t;++i){
		memset(q,0,sizeof(q));
		scanf("%lld",&n);
		for(j=0;j<n;++j){
			flag=p=0;
			scanf("%lld",&q[j].num);
			if(q[j].num<0){
				flag=1;
				p=-q[j].num-1;
			}
			else p=q[j].num;
			while(p){
				q[j].k+=p%2;
				p/=2;
			}
			if(flag) q[j].k=64-q[j].k; 
		}
		qsort(q,n,sizeof(q[0]),cmp);
		printf("case #%lld:\n",i);
		for(j=0;j<n;++j) printf("%lld ",q[j].num);
		printf("\n");
	}
    return 0;
}