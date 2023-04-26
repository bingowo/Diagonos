#include <stdio.h>
#include <math.h>
int f(const void* a,const void* b){
	int c=*(int*)a;
	int d=*(int*)b;
	if(c<0)c=abs(c);
	if(d<0)d=abs(d);
	int e=(int)log(c);
	int f=(int)log(d);
	if(e-f){
		return f-e;
	}else{
		return c-d;
	}
}
int main(){
	int num[100],i=0,t;
	while(scanf("%d",&num[i++])!=EOF);
	qsort(num,i,sizeof(int),f);
	for(t=0;t<i;t++){
		printf("%d ",num[t]);
	}
}