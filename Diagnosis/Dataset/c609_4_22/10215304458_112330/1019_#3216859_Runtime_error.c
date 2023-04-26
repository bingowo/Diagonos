#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{int num,t;}N;
int cmp(const void *a,const void *b){
	int ta=((N*)a)->t,tb=((N*)b)->t,na=((N*)a)->num,nb=((N*)b)->num;
	if(ta==tb) return na-nb;
	return tb-ta;
}
int main(){
	N a[111100];
	int i=0,j;
	memset(a,0,sizeof(a));
	while(scanf("%d",&a[i].num)!=EOF){
		++i;
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
	qsort(a,i,sizeof(a[0]),cmp);
	for(j=0;j<i;++j) printf("%d ",a[j].num);
	return 0;
} 