#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmpup(const void*a,const void*b){
	int *a1=(int *)a;
	int *b1=(int *)b;
	if(*a1!=*b1) return *a1-*b1;
    else return *b1-*a1;
}
int cmpdown(const void*a,const void*b){
	int *a1=(int *)a;
	int *b1=(int *)b;
	if(*a1!=*b1) return *b1-*a1;
    else return *a1-*b1;
}
int main(){
	int T,N;
	long long sum;
	int s1[1000],s2[1000];
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		sum=0;
		scanf("%d",&N);
		for(int j=0;j<N;j++){
			scanf("%d ",&s1[j]);	
		}
		for(int k=0;k<N;k++){
			scanf("%d ",&s2[k]);	
		}
		printf("case #%d:\n",i);
		qsort(s1,N,sizeof(int),cmpup);
        qsort(s2,N,sizeof(int),cmpdown);
		for(int v=0;v<N;v++) sum=sum+s1[v]*s2[v];
		printf("%lld\n",sum);	
}
return 0;
}
