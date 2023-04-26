#include<stdio.h>
int a[1000];
int GCD(int a,int b)
{
	return a%b?GCD(b,a%b):b;
}
int main()
{
	int n,s;scanf("%d %d",&n,&s);
	int i,j,k,tmp;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int min=a[0],min_begin=0,min_end=0;
	for(i=0;i<n;i++)
		if(a[i]<min)min=a[i];
	for(k=0;k<n;k++)
		if(a[k]==min)break;
	min_begin=k;
	for(k=n-1;k>=0;k--)
		if(a[k]==min)break;
	min_end=k;
	for(j=min+1;;j++)
	{
		for(k=min_begin;k>=0;k--)
			if(a[k]>=j)break;
		min_begin=k+1;
		for(k=min_end;k<n;k++)
			if(a[k]>=j)break;
		min_end=k-1;
		tmp=min_end-min_begin+1;
		//printf("%d %d %d\n",s,min_begin,min_end);
		if(s-tmp>0)s-=tmp;
		else if(s-tmp==0)
		{
			printf("%d",j);
			return 0;
		}
		else break;
	}
	int div=GCD(s,tmp);s/=div;tmp/=div;
	if(j!=1)printf("%d+%d/%d",j-1,s,tmp);
	else printf("%d/%d",s,tmp);
	return 0;
	
}