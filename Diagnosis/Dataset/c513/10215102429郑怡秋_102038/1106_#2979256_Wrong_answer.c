#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void mul(int b[],int n)
{
	int j=10000;
	while(b[j]==0) j--;
	for(int i=0;i<=j;i++) b[i]*=n;
	int carry=0;
	for(int i=0;i<=j;i++)
	{
		int k=b[i]+carry;
		if(k>=10) b[i]=k%10,carry=k/10;
		else b[i]=k,carry=0;
	}
	if(carry>0) b[j+1]=carry;
	
}
int main()
{
	char a[1001];
	scanf("%s",a);
	int b[10001];
	for(int i=0;i<10001;i++) b[i]=0;
	int l=strlen(a);
	if(l==1) printf("1");
	else if(l==2)
	{
		if(a[0]==a[1]) printf("1");
		else printf("4");
	}
	else if(l>2)
	for(int i=0;i<l;i++)
	{
		if(i==0)
		{
			if(a[0]!=a[1]) b[0]=2;
			else if(a[0]==a[1]) b[0]=1;
		}
		else if(i==l-1) 
		{
			if(a[l-1]!=a[l-2]) mul(b,2);
		}
		else 
		{
			if(a[i]==a[i-1]&&a[i]!=a[i+1]) mul(b,2);
			else if(a[i]!=a[i-1]&&a[i]==a[i+1]) mul(b,2);
			else if(a[i]!=a[i-1]&&a[i]!=a[i+1])
			{
				if(a[i-1]==a[i+1]) mul(b,2);
				else if(a[i-1]!=a[i+1]) mul(b,3);
			}
		}
	}
	int i=0,j=10000;
	while(b[i]==0) i++;
	while(b[j]==0) j--;
	for(int k=j;k>=i;k--) printf("%d",b[k]);
	printf("\n");
	return 0; 
}