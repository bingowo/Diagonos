#include<stdio.h> 
int main()
{
	int T;
	scanf("%d",&T);
	int l=0;
	for(l;l<T;l++)
	{
		int n;
		scanf("%d",&n);
		printf("case #%d:\n",l);
		int a[32],s[32];
		int c=n,b=0;
		while(1)
		{
			a[b]=c%2;
			b++;
			c=c/2;
			if(c==0) break;
			
		}
		int i=b-1;
		for(i;i>=0;i--)
		{
			s[b-i-1]=a[i];
		}
		int max=0,v=1;
		i=0;
		for(i;i<b-1;i++)
		{
			if(s[i+1]!=s[i]) v++;
			else v=1;
			if(v>max) max=v;
		}
		printf("%d\n",max);
	}
	return 0;
}