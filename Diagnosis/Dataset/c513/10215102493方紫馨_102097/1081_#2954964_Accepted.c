#include<stdio.h>
#define N 1000
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		int a,n;
		char ret[N+1]={0};
		scanf("%d%d",&a,&n);
		ret[N] = 1;
		for(int k=0;k<n;k++){
			int r=0;
			for(int j=N;j>=0;j--){
				r = ret[j]*a+r;
				ret[j] = r%10;
				r/=10;
			}	
		}
		int j=0;
		for(;ret[j]==0;j++);
		printf("case #%d:\n",i);
		for(;j<=N;j++){
			printf("%d",ret[j]);
		}
		printf("\n");
	}
	
	
	
	return 0;
}