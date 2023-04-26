#include<stdio.h>
#include<string.h>
int one(int a)
{
    int b=0;
    while(a>0)
    {
        if(a%2==1)
        {
            b++;
        }
        a=a/2;
    }
    return b;
}
int min(int a,int b)
{
	if(a>b)
	{
		return b;
	}
	else
	{
		return a;
	}
}
int change(int a,int b)
{
	int t=1;
    for(int i=2;i<=min(a,b);i++)
    {
        if(a%i==0&&b%i==0)
        {
        	if(t<i)
        	{
        		t=i;
			}
        }
    }
    return t;
}
int main()
{
    int number;
    scanf("%d%c",&number);
    for(int i=0;i<number;i++)
    {
        int t=0;
        char s[241];
        gets(s);
        int l=strlen(s);
        for(int j=0;j<l;j++)
        {
        	t+=one((int)s[j]);
		}
        int r=change(t,8*l);
        printf("%d/%d\n",t/r,(8*l)/r);
    }
    return 0;
}