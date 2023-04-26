#include<stdio.h>
#include<stdlib.h>
int wei(int n){
	int cnt=0;
	if(n<0)
		n=-n;
	while(n!=0){
		cnt++;
		n=n/10;
	}
	return cnt;
}

int cmp(const void* a,const void* b){
	if(wei(*(int*)a)!=wei(*(int*)b))
		return wei(*(int*)b)-wei(*(int*)a);
	else
		return *(int*)a-*(int*)b;
}

int main()
{
	int s[1000000]={0};
	int idx=0;
	while(scanf("%d",&s[idx])!=-1)
		idx++;
	qsort(s,idx,sizeof(s[0]),cmp);
	for(int i=0;i<idx;i++){
		printf("%d ",s[i]);
	}
	return 0;
 } 