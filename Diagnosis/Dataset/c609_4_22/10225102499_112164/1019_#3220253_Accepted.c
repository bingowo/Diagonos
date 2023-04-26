#include<stdio.h>
#include<stdlib.h>

int weishu(int x){
	int n=0;
	if(x<0)x=-x;
	if(x==0)n=1;
	while(x){
		x/=10;
		n++;
	}
	return n;
}

int cmp(const void* a,const void* b){
	int x=*(int*)a,y=*(int*)b;
	if(weishu(x)>weishu(y))
		return 1;
	else if(weishu(x)<weishu(y))
		return -1;
	else{
		if(x<=y)return 1;
		if(x>y)return -1;
	}
} 

int main(){
	int n;
	int a[1000000]={0};
	for(n=0;(scanf("%d",&a[n])!=EOF);n++);
	qsort(a,n,sizeof(int),cmp);
	for(n=n-1;n>0;n--){
		printf("%d ",a[n]);
	}
	printf("%d",a[0]);
	return 0;
}