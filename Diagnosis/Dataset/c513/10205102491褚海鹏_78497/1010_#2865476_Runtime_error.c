#include<stdio.h>
#include<string.h>
void twice(int n)
{
	int c[11]={0};
	int i=0;
	while(n>0)
	{
		c[i]=n%2;
		n=n/2;
		i++ ;
	}
	for(int j=0;j<10-i;j++)printf("0");
	for(i--;i>=0;i--)printf("%d",c[i]);
}
int main()
{
	char a[]={0};
	scanf("%s",a);
	int len=strlen(a);
	printf("0001");
	twice(len);
	int data=0;
	if(len%3==0)
	{
		for(int x=0;x<len-2;x=x+3)
		{
			data=a[x]*100+a[x+1]*10+a[x+2];
			twice(data);
		}
	}
	else if(len%3==1)
	{
		for(int x=0;x<len-3;x=x+3)
		{
			data=a[x]*100+a[x+1]*10+a[x+2];
		    twice(data);
		}
		twice(a[len-1]);
		
	}
	else
	{
		for(int x=0;x<len-4;x=x+3)
		{
			data=a[x]*100+a[x+1]*10+a[x+2];
			twice(data);
		}
		twice(a[len-2]*10+a[len-1]);
	}
	return 0;
}