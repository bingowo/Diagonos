#include<stdio.h>
#include<math.h>
#include<string.h>
int gcd(long long int m,long long int n)
{
	if(n==0)
		return m;
	return gcd(n,m%n);
}
int main()
{
	long long int x=0,y=1,j=0,sum=0;
	sum=0;
	char b[10000];
	scanf("%s",b);
	int c=strlen(b);
	while(j<c&&b[j]!='.')
	{	if(b[j]=='2')
		{
			b[j]='/';
		}
		j++;
	}
	for(int i=0;i<j;i++)
	{
		sum=sum+(b[i]-48)*pow(3,j-i-1);
	}
	if(b[j]=='.')
	{
		j++;
		while(b[j]!='\0')
		{
			if(b[j]=='2')
			{
				b[j]='/';
			}
			y=y*3;
			x=x*3+(b[j]-48);
			j++;
		}
		if(x<0&&sum>0) {sum--;x=y+x;}
		if(x>0&&sum<0) {sum++;x=y-x;}
		x=x/gcd(abs(x),y);
		y=y/gcd(abs(x),y);
	}
	if(x==0&&sum!=0) printf("%lld",sum);
	else {
		if(x!=0&&sum==0) printf("%lld %lld",x,y);
		else {
			if(x==0&&sum==0) printf("0");
			else printf("%lld %lld %lld",sum,x,y);
			}
		}
	
	

	
	return 0;
	
	
 } 