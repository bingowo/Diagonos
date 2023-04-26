#include <stdio.h>
long long int a[40][40]={0};
long long int h(int m,int n)
{
	if(n==m) return 1;
	else if(n==1) return m;
	else if(n==0) return 1;
	if(a[m][n]==0){
		a[m][n]=h(m-1,n)+h(m-1,n-1);
		return a[m][n];
	}
	else return a[m][n];
}

int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++) 
	{
		int m,n;
		scanf("%d %d",&m,&n);
		if(n>m/2) n=m-n;
		
		long long int sum;
		sum=h(m,n);
		printf("case #%d:\n",i);
		printf("%lld\n",sum);
		
	}
	return 0;
}