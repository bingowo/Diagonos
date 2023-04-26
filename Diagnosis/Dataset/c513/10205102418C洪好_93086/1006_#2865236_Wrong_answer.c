#include<stdio.h>
#include<string.h>
#include<math.h>

int fun(char s[])
{
	int len=strlen(s),x=0,i;
	for(i=0;i<len;i++)
	{
		if(s[i]=='1')
			x+=pow(3,len--);
		else if(s[i]=='0')
			len--;
		else if(s[i]=='-')
			x-=pow(3,len--);
		else
			break;
	}
	return x;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	char c[1000];//=' ';
	for(i=0;i<n;i++)
	{
		scanf("%s",c);
		int x=fun(c);
		printf("case #%d:%d\n",i,x);
	}
	return 0;
} 