#include<stdio.h>
int main()
{
	int n,t=0;
	scanf("%d",&n);
	t=n/5;
	if(n%25==0)
		t+=n/25;
	if(n%125==0)
		t+=n/125;
	printf("%d",t);
}