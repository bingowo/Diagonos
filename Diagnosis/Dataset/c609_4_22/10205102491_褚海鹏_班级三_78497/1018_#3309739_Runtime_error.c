#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
} 
int main()
{
	int num[100]={0};
	int n;
	scanf("%d",&n);
	int i=0,s=0;
	int m;
	while(scanf("%d",&m)!=EOF){
		num[i]=m;
		i++;
	}
	qsort(num,n,sizeof(int),cmp); 
	for(int i=0;i<n;i=i+2){
		s=s+num[i+1]-num[i];
	}
	printf("%d",s);
	return 0;
}