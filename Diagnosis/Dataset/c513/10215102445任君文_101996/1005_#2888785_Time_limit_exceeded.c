#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
double p(double x, int y)
{
	int i;
	double res = 1;
	for (i = 0; i < y; i++)
	{
		res = res * x;
	}
	return res;
}
long pi(int x, int y)
{
	int i;
	int res = 1;
	for (i = 0; i < y; i++)
	{
		res = res * x;
	}
	return res;
}
int cheng(double a,int b)
{
    int c=(int)(a*b);
    return c;
}
int main()
{
    int temp=0;
	int T, i, m, n[10] = { 0 },pp=0;
	double res[10] = { 0 },q=0.125;
	char c;
	scanf("%d", &T);
	c = getchar();
	for (i = 0; i < T; i++)
	{
		c = getchar();
		c = getchar();
		m = 1;
		while ((c = getchar()) != '\n')
		{
			temp = c - '0';
			res[i] = res[i] + temp * p(q, m);
			m++;
		}
		n[i]=(m-1)*3;
	}
	for(i=0;i<T;i++)
	{
	    pp=pi(10,n[i]);
        temp=cheng(res[i],pp);
	    while(temp%10==0)
	    {
	        n[i]=n[i]-1;
	       	pp=pi(10,n[i]);
            temp=cheng(res[i],pp);
	        
	    }
	}
	for(i=0;i<T;i++)
	{
		printf("case #%d:\n", i);
		printf("%.*lf\n",n[i], res[i]);
	}
	return 0;
}