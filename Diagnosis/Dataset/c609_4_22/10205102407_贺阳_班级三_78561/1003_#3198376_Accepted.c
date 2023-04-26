#include<stdio.h> 
int main()
{
	int T;
	scanf("%d",&T);
	int l=0;
	for(l;l<T;l++)
	{
		long long int n;
		scanf("%lld",&n);
		int s[30],p[30];
		int i=0,b=0;
		long long int a=n;
		while(1)
		{
			s[i]=a%2333;
			b++;
			a=a/2333;
			if(a==0) break;
			i++;
		}
		i=b-1;
		for(i;i>=0;i--)
		{
			p[b-i-1]=s[i];
		}
		i=0;
		for(i;i<b;i++)
		{
			if(i!=b-1) printf("%d ",p[i]);
			else printf("%d\n",p[i]);
		}
	}
		
	
	return 0;
}