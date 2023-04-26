#include<stdio.h>
#include<stdlib.h>
int count (int n){
	int co=0;
	while(n){
		if(n&1) co++;
		n=n>>1;
	}
	return co;
}
int cmp(const void*a,const void *b){
	int ta=*(int*)a;
	int tb=*(int*)b;
	int a1=count(ta);
	int b1=count(tb);
	if(a1==b1) return ta<tb?-1:1;
	else return tb-ta;
}
void Sort(int*s,int n){
	qsort(s,n,sizeof(int),cmp);
}

int main(){
	int T,N,i,j;
	int s[1000];
	scanf("%d\n",&T);
	for(i=0;i<T;i++){
		scanf("%d\n",&N);
		 for(j=0;j<N;j++){
		 	scanf("%d ",&s[j]);}
			 Sort(s,N);	
		 printf("case #%d:\n",i);
		 for(j=0;j<N;j++){
		 	printf("%d ",s[j]);
		 }
	}
	return 0;
}