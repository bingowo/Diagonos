#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int cmp(const void*a,const void *b){
	int a1=*(int*)a,b1=*(int*)b;
	if(a1==b1) return 0;
	else return b1>a1?1:-1;
	
}
int main(){
	int N,sum=0;
	scanf("%d\n",&N);
	int *p=(int *)malloc(sizeof(int)*(N+1));
	for(int i=0;i<N;i++) scanf("%d ",(p+i));
	qsort(p,N,sizeof(int),cmp);
	int j=0;
	for(;j<N-2;j=j+2)
		{sum+=abs(p[j]-p[j+1]);}
		sum+=abs(p[j]-p[j+1]);
	printf("%d",sum);
	return 0;
}