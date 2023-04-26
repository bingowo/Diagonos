#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
double f()
{
	char a[20];
	double x,y;
	scanf("%s",a);
	switch(a[0])
	{
		case'+': {x=f();y=f();return x+y;}
		case'-': {x=f();y=f();return x-y;}
		case'*': {x=f();y=f();return x*y;}
		case'/': {x=f();y=f();return x/y;}
		default: {return atof(a);}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("case #%d:\n%.6f\n",i,f());
	}
	
	
	
	return 0;
	
 } 