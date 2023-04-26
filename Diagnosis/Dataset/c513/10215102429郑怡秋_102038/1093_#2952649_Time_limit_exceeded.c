#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int have9(int a[],int l)
{
	for(int i=0;i<l;i++)
	{
		if(a[i]==9) return -1;
	}
	return 1;
}
int zc(int a[],int l)
{
	long long ans=0;
	for(int i=0;i<l;i++) ans+=a[i];
	if(ans<9) return 1;
	if(ans%9==0) return 1;
	else return -1;
}
int add(int a[],int l)
{
	a[0]++;
	if(a[0]>=10)
	{
		a[0]=a[0]%10;
		int i=1;
		while(a[i]+1>=10) i++;
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
	for(int i=l-1;i>=0;i--) printf("%d",a[i]);
	return 0;
}