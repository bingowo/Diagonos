#include <stdio.h>
#include <stdlib.h>

int GCD(int m,int n)
{
	if(n>m)
	{
		int z;
		z = m;
		m = n;
		n = z;
	}
	if(n == 0) return m;
	else if(m % n == 0) return n;
	while(n!=0 && m%n !=0)
	{
		int t = m % n;
		m = n;
		n = t;
	}
	return n;
}

int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
    int m = GCD(x,y);
    int sum = x*4;
    printf("%d",sum);
}