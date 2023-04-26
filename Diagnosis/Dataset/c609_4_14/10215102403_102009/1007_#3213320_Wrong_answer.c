#include<stdio.h>
#include<stdlib.h>
struct num{
	long long int c;
	int w;
};
int cmp(const void* a, const void* b){
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
		int n;
		scanf("%d",&n);
		struct num a[10000]; int j;
		for(j=0;j<n;j++){
			scanf("%lld ",&a[j].c);
			int sum=0; int p=64;
			long long int k=1;
			while(p>0){
				sum+=a[j].c&k;
				k<<=1; p--;
			} 
			a[j].w=sum;
		}  
		printf("case #%d:\n",i);
		qsort(a,n,sizeof(a[0]),cmp);
		for(j=0;j<n;j++){
			printf("%lld%c",a[j].c,(j<n-1)?' ':'\n');
		}
	}
	return 0;
} 