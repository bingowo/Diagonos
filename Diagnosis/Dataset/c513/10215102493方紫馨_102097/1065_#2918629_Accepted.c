#include<stdio.h>
int main()
{
	int a,n,m,x,t,ret;
	scanf("%d%d%d%d",&a,&n,&m,&x);
	int fib[21],pa[21],pt[21];
	fib[0]=1;fib[1]=1;
	for(int i=2;i<21;i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	pa[0]=1,pa[1]=1,pa[2]=2,pa[3]=2;
	pt[0]=0,pt[1]=0,pt[2]=0,pt[3]=1;
	for(int i=4;i<21;i++){
		pa[i]=pa[i-1]+fib[i-4];
		pt[i]=pt[i-1]+fib[i-3];
	}
	//m=pa[i]*a+pt[i]*t;
	t=(m-pa[n-2]*a)/pt[n-2];
	ret=pa[x-1]*a+pt[x-1]*t;
	printf("%d",ret);
	return 0; 
}
 