#include<stdio.h>
#include<stdlib.h>
#define N 100
void hex(int num,int p);

int main()
{
    int i,x,n,R;
    scanf("%d",&x);
    for(i=0;i<x;i++)
	{	
	    scanf("%d%d",&n,&R);
	    hex(n,R);
	    printf("\n");
	}
    return 0;
    
}
void hex(int num,int p)
{
	int a[N];
	int i = 0;
	do {
		a[++i] = num % p;
		num = num / p;
	}while (num != 0);
	for(;i>0;i--)
	{
		if(a[i] < 10)
		   printf("%d",a[i]);
		else
		{
		a[i] = a[i] % 10 + 'A';
		printf("%c",a[i]);
	    }
	}
}
