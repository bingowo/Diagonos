#include<stdio.h>
#include<stdlib.h>
typedef struct{
	long long num;
	long long f;
}p;
int cmp1(const void* a, const void *b){
	if((*(p*)a).f!=(*(p*)b).f) return (*(p*)a).f<(*(p*)b).f? 1:-1;
	else return (*(p*)a).num>(*(p*)b).num;
}
int main(){
	int t,i,j,n;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&n);
		p a[10005];
		for(j=0;j<n;j++){
			scanf("%lld",&a[j].num);
			a[j].f=a[j].num;
			if(a[j].f<0) a[j].f=-a[j].f;
			while(a[j].f>=10){
				a[j].f/=10;
			}
			//printf("%lld\n",a[j].f);
		}
		qsort((void *)a,n,sizeof(a[0]),cmp1);
		printf("case #%d:\n",i);
		for(j=0;j<n;j++){
			printf("%lld ",a[j].num);
		}
		printf("\n");
	}
}