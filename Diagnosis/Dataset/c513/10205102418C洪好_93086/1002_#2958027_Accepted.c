#include<stdio.h>

int main()
{

	int t;
	scanf("%d",&t);
	int cas,i;
	for(cas=0;cas<t;cas++)
	{
	    char s[61];
	    scanf("%s",s);
	    int a[128];
		for(i=0;i<128;i++)
		{
		    a[i]=-1;
		}
		int r=0;
		char *p=s;
		a[*p]=1;
		while(*++p)
		{
		    if(a[*p]==-1)
		    {
		        a[*p]=r;
		        r=r?r+1:2;
		    }
		}  
		if(r<2)
		  r=2;
		long long n=0;
		p=s;
		while(*p)
		  n=n*r+a[*p++];
		printf("case #%d:\n%lld\n",cas,n);
	}
	return 0;
} 