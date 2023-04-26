#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	char s[51];
	scanf("%s",s);
	long long int sum;
	long long int a[51];
	int i=0,len,count=0,j=0;
	len=strlen(s);
	long long k=1;
	for(i=0;i<len;i++)
	{
		
		if(s[i]=='I') a[j++]=1*k;
		else if(s[i]=='V') a[j++]=5*k;
		else if(s[i]=='X') a[j++]=10*k;
		else if(s[i]=='L') a[j++]=50*k;
		else if(s[i]=='C') a[j++]=100*k;
		else if(s[i]=='D') a[j++]=500*k;
		else if(s[i]=='M') a[j++]=1000*k;
		else if(s[i]=='(')
		{
			count+=3;
			k=pow(10,count);
		}
		else if(s[i]==')')
		{
			count-=3;
			k=pow(10,count);
		}
	}
	int e=0;
	//printf("%lld\n",a[4]);
	sum=a[j-1];
	for(e;e<j-1;e++)
	{
		//printf("%lld\n",sum);
		if(a[e]<a[e+1]) sum-=a[e];
		else sum+=a[e]; 
	}
	printf("%lld\n",sum);
	return 0;
}