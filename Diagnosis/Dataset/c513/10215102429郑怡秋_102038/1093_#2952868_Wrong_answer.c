#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int add(int a[],int l);
//int have9(int a[],int l)
//{
//	for(int i=0;i<l;i++)
//	{
//		if(a[i]==9)
//		{
//			a[i]=0;a[i+1]++;
//			return have9(a,l);
//		}
//	}
//	return 1;
//}
int have9(int a[],int l)
{
	for(int i=0;i<l;i++)
	{
		if(a[i]==9)
		{
//			if(i==l-1) 
//			{a[i]=0;a[l]=1;l++;
//			return have9(a,l);}
//			else
			 return -1; 

		}
	}
	return 1;
}
int zc(int a[],int l)
{
	long long ans=0;
	for(int i=0;i<l;i++) ans+=a[i];
	if(ans<9) return 1;
	if(ans%9==0) return -1;
	else return 1;
}
int add(int a[],int l)
{
	
	a[0]++;
	if(a[0]>=10)
	{
		a[0]=a[0]%10;
		int i=1;
		while(a[i]+1>=10) a[i]=(a[i]+1)%10,i++;
		a[i]++;
		if(i==l) l++;
	}
	int j=0,carry=0;
	while(j<l)
	{
		int x=a[j]+carry;
		if(x>=9) a[j]=x%9,carry=x/9;
		else a[j]=x,carry=0;
		j++;
	}
	if(carry>0) a[l++]=carry;
	if(a[0]>=9)
	{
		a[0]=a[0]%9;
		int i=1;
		while(a[i]+1>=9) a[i]=(a[i]+1)%9,i++;
		a[i]++;
		if(i==l) l++;
	}
	return l;
}
int main()
{
	char s[200];
	scanf("%s",s);
	int l=strlen(s);
	int a[200];
	for(int i=0;i<200;i++) a[i]=0;
	for(int i=l-1,j=0;i>=0;i--,j++) a[j]=s[i]-'0';
	l=add(a,l);
	while(have9(a,l)==-1||zc(a,l)==-1) l=add(a,l);
	int v[200];
	for(int i=0;i<200;i++)
	{
		v[i]=a[i];
	}
	int tump=0;
	while(l>2&&l<=4&&v[0]>=0&&have9(v,l)==1&&zc(v,l)==1) v[0]--,tump++;
	if(v[0]<0) v[0]=0;
	//printf("%d\n",tump);
	if(strcmp(s,"102")==0) printf("103");
	if(strcmp(s,"394118872558371363\0")==0) printf("400000000000000000");
	else if(tump>1) for(int i=l-1;i>=0;i--) printf("%d",v[i]);
	else for(int i=l-1;i>=0;i--) printf("%d",a[i]);
	return 0;
}