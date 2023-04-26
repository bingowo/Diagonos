#include <stdio.h>
#include <math.h>
int f1(const void* a,const void* b){
	int c=f2(*(int*)a);
	int d=f2(*(int*)b);
	if(c-d)return d-c;
	else return *(int*)a-*(int*)b;
}
int f2(int a){
	int ret=0;
	while(a){
		a/=10;
		ret++;
	}
	return ret;
}
int main(){
	int num[1000000];
	int i,t;
	for(i=0;scanf("%d",&num[i])!=EOF;i++);
	qsort(num,i,sizeof(int),f1);
	for(t=0;t<i;t++){
		printf("%d ",num[t]);
	}
}