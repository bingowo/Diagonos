#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int k,n;
int f(int n)
{
    if(n<=1) return 0;
    if(n==2) return 1;
    if(k==2) return f(n-1)+f(n-2);
    if(k==3) return f(n-1)+f(n-2)+f(n-3);
    if(k==4) return f(n-1)+f(n-2)+f(n-3)+f(n-4);
    if(k==5) return f(n-1)+f(n-2)+f(n-3)+f(n-4)+f(n-5);
}
int main()
{
	scanf("%d%d",&k,&n);
	printf("%d",f(n));
	return 0;
}
