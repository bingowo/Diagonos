#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count(int n)
{
    int num=0;
    while(n)
    {
        if(n%2==1) num++;
        n=n/2;
    }
    return num;
}
int measure(int x, int y)
{
	int z = y;
	while(x%y!=0)
	{
		z = x%y;
		x = y;
		y = z;
	}
	return z;
}
int main()
{
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        unsigned char s[1000];
        gets(s);
        int m=strlen(s);
        int a=0,b=0;
        for(int j=0;j<m;j++)
        {
            int n=s[j];
            a=a+count(n);
            b=b+8-count(n);
        }
        int c=measure(a,b);
        printf("%d/%d\n",a/c,(a+b)/c);
    }
}
