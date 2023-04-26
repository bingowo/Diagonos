#include<stdio.h>

int change(int n,int r)
{

	int a[100],n1,i=0,flag=0;
	if(n<0)
	{
		n1=-n;
		flag=1;
	}
	else
		n1=n;
	do
	{
		a[i]=n1%r;
		n1=n1/r;
		i++;	
	}while(n1!=0);
	if(flag==1)
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
	int t,n,r,j=0;
	scanf("%d",&t);
	while(t>0)
	{
		scanf("%d%d",&n,&r);
		t--;
		j++;
		change(n,r);
		printf("\n");
	}
}