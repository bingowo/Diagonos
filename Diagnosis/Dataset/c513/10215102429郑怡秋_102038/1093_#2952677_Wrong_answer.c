#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int add(int a[],int l)
{
	a[0]++;
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
//	while(have9(a,l)==-1||zc(a,l)==-1) l=add(a,l);
	for(int i=l-1;i>=0;i--) printf("%d",a[i]);
	return 0;
}