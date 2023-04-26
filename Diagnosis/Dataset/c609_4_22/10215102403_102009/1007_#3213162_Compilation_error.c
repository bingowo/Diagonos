#include<stdio.h>
#include<stdlib.h>
struct num{
	long long int c;
	int w;
};
int cmp(const void* a, const void* b){
	num a1,a2;
	a1=*((num*)a); a2=*((num*)b);
	if(a1.w-a2.w) return a2.w-a1.w;
	else return a1.c-a2.c;
}
int main(){
	int t;
	scanf("%d\n",&t);
	for(int i=0;i<t;i++){
		int n;
		scanf("%d\n",&n);
		num a[n+1]; int j;
		for(j=0;j<n;j++){
			scanf("%lld ",a[j].c);
			int sum=0;
			while(a[j].c){
				sum+=a[j].c&1;
				a[j].c>>=1;
			} 
			a[j].w=sum;
		}  scanf("\n"); 
		qsort(a,n,sizeof(num),cmp);
		printf("case #%d:\n",i);
		for(j=0;j<n;j++){
			printf("%lld ",a[j].c);
		}
		printf("\n");
	}
	return 0;
} 