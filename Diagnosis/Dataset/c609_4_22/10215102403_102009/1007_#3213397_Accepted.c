#include<stdio.h>
#include<stdlib.h>
struct num{
	long long int c;
	int w;
};
int cmp(const void *a, const void *b){
	struct num a1,a2;
	a1=*((struct num*)a); a2=*((struct num*)b);
	if(a1.w!=a2.w) return a2.w-a1.w;
	else if(a1.c>a2.c) return 1;
	else return -1;
}
int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		printf("case #%d:\n",i);
		int n;
		scanf("%d",&n);
		struct num a[10000]; int j;
		for(j=0;j<n;j++){
			scanf("%lld ",&a[j].c);
			a[j].w=0; int p=64;
			long long k=1;
			while(p>0){
				if(a[j].c&k) a[j].w++;
				k<<=1; p--;
			} 
		}  
		qsort(a,n,sizeof(a[0]),cmp);
		for(j=0;j<n;j++)
			printf("%lld%c",a[j].c,(j<n-1)?' ':'\n');
	}
	return 0;
} 