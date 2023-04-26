#include<stdio.h>
#include<string.h>
unsigned long long int chengfang(int n)
{
	unsigned long long int result=1;
	for(int i=0;i<n;i++)
	{
		result=result*3;
	}
	return result;
}
int main()
{
	int n;
	scanf("%d",&n);
	int p=0;
	char a[1000];
	while(scanf("%c",&a)!=EOF)
	{
		int len=strlen(a);
		unsigned long long int sum=0;
		for(int i=0;i<len;i++)
		{
			if(a[i]=1)sum=sum+chengfang(len-i-1);
			else if(a[i]='-')sum=sum-chengfang(len-i-1);
		}
		printf("case #%d:\n",p);
		printf("%llu",sum);
		p++;
	}
	return 0;
}
