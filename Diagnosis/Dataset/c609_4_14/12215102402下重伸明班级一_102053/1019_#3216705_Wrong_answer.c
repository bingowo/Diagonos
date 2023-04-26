#include<stdio.h>
int main()
{
    int a[100000],n;
    int i=0;
	while(scanf("%d",&n)==1)
	{
		a[i]=n;
		i++;
	}
	printf("%d",i);
}
