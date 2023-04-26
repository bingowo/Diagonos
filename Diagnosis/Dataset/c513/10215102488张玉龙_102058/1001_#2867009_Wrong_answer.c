#include<stdio.h>

void change(int n,int r)
{
	int a[100];
	int i=0;
	if(n<0)
	{
		int n1=-n;
		do
		{
			a[i]=n1%r;
			n1=n1/r;
			i++;	
		}while(n1!=0);
	}
	else
	{
		do
		{
			a[i]=n%r;
			n=n/r;
			i++;
		}while(n!=0);
	}
	if(n<0)
		printf("-");
	for(i--;i>=0;i--)
	{
		if(a[i]>=10)
			printf("%c",a[i]-10+'A');
		else
			printf("%d",a[i]);
	}
}

int main()
{
	int t,n[100],r[100];
	int j=0;
	scanf("%d",&t);
	while(t>0)
	{
		scanf("%d%d",&n[j],&r[j]);
		t--;
		j++;
	}
	for(j--;j>=0;j--)
		{
		change(n[j],r[j]);
		if(j>0)
			printf("\n");
		}
	return 0;
}