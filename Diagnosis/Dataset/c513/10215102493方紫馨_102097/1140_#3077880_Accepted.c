#include<stdio.h>
#include<stdlib.h>

int cmp(const void* p1,const void* p2){
	int a = *((int*)p1);
	int b = *((int*)p2);
	return a-b;
}

int main()
{
	int n,a=0,num[10000];
	scanf("%d",&n);
	for(int k=0;k<n;k++){
		int m;
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			scanf("%d",&num[a++]);			
		}
	}
	qsort(num,a,sizeof(num[0]),cmp);
	int cnt=1;
	for(int i=1;i<a;i++){
		if(num[i]==num[i-1]){
			cnt++;
		}else{
			if(cnt==n){
				printf("%d ",num[i-1]);
			}
			cnt=1;
		}	
	}
	if(cnt==n)
		printf("%d ",num[a-1]);
	return 0;
}