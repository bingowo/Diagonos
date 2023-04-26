#include<stdio.h>
#include<string.h>
#include<math.h>

int fun(char s[])
{
	int len=strlen(s),x=0,i,j;
	for(i=len,j=0;i>0,j<len;i--,j++)
	{
		printf("%d\n",i);
		if(s[j]=='1')
			x+=pow(3,i);
		else if(s[j]=='0');
			//len--;
		else if(s[j]=='-')
			x-=pow(3,i);
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
		//printf("%d\n",strlen(c));
		printf("case #%d:%d\n",i,x);
	}
	return 0;
} 