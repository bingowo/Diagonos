#include <stdio.h>
#include <string.h>
int yf(int m,int n)
{
	for (int i=m;i>=1;i--)
	{ 
		if (m%i ==0 && n%i==0)
		   return i;
	}
}

int cal(char q)
{
	int cnt=0;
	if (q<0)
	{
		cnt++;
		q=q^128;
	}
	while (q)
	{
		if (q%2)
		{
			cnt++;
		}
		q/=2;
	}
	return cnt;
}

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	for (int j=0;j<n;j++)
	{
		char a[128]={'\0'};
		char ch;
		int i=0;
		while ((ch=getchar())!='\n')
		{
			a[i++]=ch;
		}
		int len=strlen(a);
		int sum=0;
		for (int i=0;i<len;i++)
		{
			sum+=cal(a[i]);
		}
		int total=len*8;
		int ans=yf(sum,total);
		sum/=ans;
		total/=ans;
		printf("%d/%d\n",sum,total);
	}
	return 0;

}

