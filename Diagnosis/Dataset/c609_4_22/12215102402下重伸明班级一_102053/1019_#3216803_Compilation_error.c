#include<stdio.h>
int cmp()
int tongji(int x)
{
    int i=0;
    for(;x>0;i++)
    {
        x=x/10;
    }
    return i; 
}
int main()
{
    int a[100000],n,m;
    int i=0;
	while(scanf("%d",&n)==1)
	{
		a[i]=n;
		m=tongji(n);
		i++;
		printf("%d\n",n);
	}
	printf("%d",i);
}
