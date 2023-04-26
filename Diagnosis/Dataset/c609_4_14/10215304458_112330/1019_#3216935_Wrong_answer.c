#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{int num,t;}N;
int cmp(const void *a,const void *b){
	/*int ta=((N*)a)->t,tb=((N*)b)->t,na=((N*)a)->num,nb=((N*)b)->num;
	if(ta==tb) return na-nb;
	return tb-ta;*/
	if(((N*)a)->t==((N*)b)->t) return ((N*)a)->num-((N*)b)->num;
	else return ((N*)b)->t-((N*)a)->t;
}
int main(){
	N a[131100];
	int i=0,j,p;
	memset(a,0,sizeof(a));
	while(scanf("%lld",&p)!=EOF){
		a[i++].num=p;
	}
	for(j=0;j<i;++j){
		int k;
		if(a[j].num<0) k=-a[j].num;
		else k=a[j].num;
		if(k==0) ++a[j].t;
		while(k){
			++a[j].t;
			k/=10;
		}
	}
	//printf("%d",i);
	qsort(a,i,sizeof(a[0]),cmp);
	for(j=0;j<i;++j) printf("%d ",a[j].num);
	return 0;
} 