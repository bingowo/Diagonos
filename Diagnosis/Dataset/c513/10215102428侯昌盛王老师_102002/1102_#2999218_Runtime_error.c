#include <stdio.h>
typedef struct{
	long long int x,y;
}point;
int main()
{
	long long n,i,sum=0;
	int j=0;
	
	char s[5]={'U','L','D','R'};
	scanf("%lld",&n);
	int a[2*n];
	point p;
	p.x=0;p.y=0;
	int k=1;
	for(i=1;sum+i<=n;i++)
	{
		if(sum+i*2<=n) {
			a[j++]=i;
			a[j++]=i;
			sum=sum+i*2;
		}
		else
		{
			a[j++]=i;
			sum=sum+i;
		}
	}
	//printf("%d\n",j);
	if(sum<n) a[j++]=n-sum;
	for(i=0;i<j;i++)
	{
		if(s[i%4]=='U') p.y+=a[i];
		else if(s[i%4]=='L') p.x-=a[i];
		else if(s[i%4]=='D') p.y-=a[i];
		else if(s[i%4]=='R') p.x+=a[i];
		
	}
	printf("(%lld,%lld)\n",p.x,p.y);
	return 0;
}