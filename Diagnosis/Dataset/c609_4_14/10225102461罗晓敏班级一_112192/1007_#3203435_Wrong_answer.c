#include <stdio.h>
#include <stdlib.h>
typedef struct{
	long long int a;
	int number;
}f;
int f1(long long int n){
	int i,g1=0;
	for(i=0;i<64;i++){
		if(n>>i&1ll==1){
			g1++;
		}
	}
	return g1;
}
long long int f2(const void*a,const void*b){
	int c=(*(f*)b).number,d=(*(f*)a).number;
	if(c!=d)return c-d;
	else return (*(f*)a).a-(*(f*)b).a;
}
int main(){
	int t,i;
	scanf("%d",&t);
	int n,j;
	for(i=0;i<t;i++){
		scanf("%d",&n);
		f *num=(f*)malloc(n*sizeof(f));
		for(j=0;j<n;j++){
			scanf("%lldd",&num[j].a);
			num[j].number=f1(num[j].a);
		}
		qsort(num,n,sizeof(f),f2);
		printf("case #%d:\n",i);
		for(j=0;j<n;j++){
			printf("%lld%c",num[j].a,j==n-1?'\n':' ');
		}
		free(num);
	}
} 