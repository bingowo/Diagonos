#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int a[501]={0},b[501]={0},c[501]={0},d[501]={0},n,i,j=0,p=0,q=0,r=0,s=0,ans1[501]={-1},ans2[501]={-1},z=0,w=0;
	for(int i=0;i<501;i++) ans1[i]=-1;
	for(int i=0;i<501;i++) ans2[i]=-1;
	char x[501],y[501];
	scanf("%s",x);
	for(i=0;x[i]!='.'&&x[i]!='\0';i++)
	{
		a[i]=x[i]-48;p++;
	}
	i++;
	for(;x[i]!='\0';i++)
	{
		c[j]=x[i]-48;
		j++;r++;
	}
	i=0;j=0;
	scanf("%s",y);
	for(i=0;y[i]!='.';i++)
	{
		b[i]=y[i]-48;q++;
	}
	i++;
	for(;y[i]!='\0';i++)
	{
		d[j]=y[i]-48;
		j++;s++;
	}
	while(p>=0||q>=0)
	{
		if(p>q)
		{
			ans1[p]=(a[p]+b[q]+z)%10;
			z=(a[p]+b[q]+z)/10;p--;q--;
		}
		else
		{
			ans1[q]=(a[p]+b[q]+z)%10;
			z=(a[p]+b[q]+z)/10;p--;q--;
		}
	}
	for(i=0;ans1[i]!=-1;i++)
	{
		printf("%d",ans1[i]);
	}
	printf(".");
	while(r>=0||s>=0)
	{
		if(r>s)
		{
			ans2[r]=(c[r]+d[s]+w)%10;
			w=(c[r]+d[s]+w)/10;r--;s--;
		}
		else
		{
			ans2[s]=(c[r]+d[s]+w)%10;
			w=(c[r]+d[s]+w)/10;r--;s--;
		}
	}
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		if(ans2[i]!=-1) printf("%d",ans2[i]);
		else printf("0");
	}
}