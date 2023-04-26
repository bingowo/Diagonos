#include<stdio.h>
#include<stdlib.h>
typedef struct{long long num,t;}N;
int cmp(const void *a,const void *b){
	long long ta=((N*)a)->t,tb=((N*)b)->t,na=((N*)a)->num,nb=((N*)b)->num;
	if(ta==tb) return na-nb;
	return tb-ta;
}
int main(){
	N a[100100];
	long long i=0,j,k;
	while(scanf("%lld",&a[i].num)!=EOF){
		a[i].t=0;
		if(a[i].num<0) k=-a[i].num;
		else k=a[i].num;
		if(k==0) ++a[i].t;
		while(k){
			++a[i].t;
			k/=10;
		}
		//printf("%d %d\n",a[i].num,a[i].t);
		++i;
	}
	//printf("%d\n",i);
	//for(j=0;j<i;++j) printf("%d %d\n",a[j].num,a[j].t);
	qsort(a,i,sizeof(a[0]),cmp);
	for(j=0;j<i;++j) printf("%lld ",a[j].num);
	return 0;
} 