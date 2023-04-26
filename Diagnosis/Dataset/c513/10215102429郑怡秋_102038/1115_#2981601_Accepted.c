#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int cmp(const void*a,const void*b)
{
	int*p1=(int*)a;int*p2=(int*)b;
	return *p1-*p2;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int p=0;p<T;p++)
	{
		char s[30];
		scanf("%s",s);
		int a[30];
		int x=0;
		for(int i=0;i<30;i++) a[i]=0;
		int l=strlen(s);
		for(int i=0;i<l;i++) a[i+1]=s[i]-'0';//,printf("%d",a[i+1]);
		for(int i=l-1;i>=0;i--) 
		{
			if(a[i]<a[i+1])
			{
				x=i;
				break;
			}
		}
		qsort(a+x+1,l-x,sizeof(a[0]),cmp);
		for(int i=x+1;i<l+1;i++) 
		{
			if(a[x]<a[i]) 
			{
				int tump=a[x];
				a[x]=a[i];
				a[i]=tump;
				break;
			}
		}
		printf("case #%d:\n",p);
		int k=0;
		if(a[0]==0) k=1;
		for(;k<=l;k++) printf("%d",a[k]);
		printf("\n");
	}
	return 0;
}