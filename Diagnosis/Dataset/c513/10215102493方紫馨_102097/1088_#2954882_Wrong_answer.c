#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	int m,n;
	long long int ret=1,A[21];
	A[0] = 1;A[1] = 1;
	for(int i=2;i<21;i++){
		A[i] = A[i-1]*i;		
	}
	for(int i=0;i<T;i++){
		scanf("%d %d",&m,&n);
		if(n>m/2)
			n=m-n;
		for(int j=0;j<n;j++,m--){
			ret = ret * m;			
		}
		printf("case #%d:\n",i);
		printf("%lld\n",ret/A[n]);
	}
	
	
	return 0;
} 