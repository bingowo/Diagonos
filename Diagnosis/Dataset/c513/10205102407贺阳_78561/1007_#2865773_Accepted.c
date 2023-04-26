#include<stdio.h>
int main()
{
	int i=0,T;
	scanf("%d\n",&T);
	for(i;i<T;i++)
	{
		int n;
		scanf("%d",&n);
		int s[32];
		int j=0,c=0;
		for(j;j<32;j++)
		{
			s[j]=n%2;
			n=n/2;
			c++;
			if(n==0)
			break;
		}
		j=0;
		int t[32];
		for(j;j<c;j++)
		{
			t[j]=s[c-1-j];
		}
		j=0;
		int a=1,b=1;
		for(j;j<c-1;j++)
		{
			if(s[j]!=s[j+1]) 
			{
				a++;
				if(a>b) b=a;
			}
			else  a=1;
		}
		printf("case #%d:\n",i);
		printf("%d\n",b);
	
		
	}
	

}