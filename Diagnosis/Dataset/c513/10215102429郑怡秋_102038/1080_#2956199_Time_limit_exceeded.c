#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void Divide(char s[],int n)
{
	int remainder=0;
	int l=strlen(s);
	for(int i=0;i<l;i++)
	{
		int x=remainder*10+s[i]-'0';
		s[i]=x/n+'0';
		remainder=x%2;
	}
}
int mul(int a[],int l,int n)
{
	int carry=0;
	for(int i=0;i<l;i++) a[i]*=2;//printf("l:%d\n",l);
	for(int i=0;i<l;i++)
	{
		int x=a[i]+carry;
		a[i]=x%10;
		carry=x/10;
	}
	if(carry>0)  a[l++]=carry;
	return l;
	
}
void add(int a[],int b[])
{
	int carry=0;
	for(int i=0;i<100;i++)
	{
		int n=a[i]+b[i]+carry;
		a[i]=n%10;
		carry=n/10;
	}
//	if(carry!=0) a[l++]=carry;
//	return carry;
}
int main()
{
	int x;
	scanf("%d",&x);
	for(int q=0;q<x;q++)
	{
		char s[150];
		scanf("%s",s);
		int len=strlen(s);
		int a[1000][100];
		for(int i=0;i<1000;i++) for(int j=0;j<100;j++) a[i][j]=0;
		int index=0;
		while(1)
		{
			int k=0;
			for(int i=len-1;i>=0;i--)
			{
				if(s[i]!='0') {k=1;break;}	
			}//printf("%s\n",s);
			if(k==0) break;
			a[index++][0]=(s[len-1]-'0')&1; //printf("%d\n",a[index-1][0]);
			Divide(s,2);
		}
		if(index>=335) index=335;
		int index1=0;int l=1;
		while(a[index1][0]==0&&index1<index-1) index1++;//printf("%d\n",index1);
		for(int i=index-2;i>=index1;i--)
		{	
			for(int j=i;j>=index1;j--)
			{
				l=mul(a[j],l,2);
//				for(int k=0;k<3;k++) printf("%d",a[j][k]);
//				printf("\n");
			}
		}
		for(int i=index-2;i>=index1;i--)
		{
			add(a[index-1],a[i]);
		}
		//for(int i=0;i<10;i++) printf("%d\n",a[index-1][i]);
		if(index<1) index=1; 
		int ll=99;
		while(a[index-1][ll]==0&&ll>0) ll;
		printf("case #%d:\n",q);
		if(ll>90) printf("1");
		for(int i=ll;i>=0;i--) printf("%d",a[index-1][i]);
		printf("\n");
	}
	return 0;
}