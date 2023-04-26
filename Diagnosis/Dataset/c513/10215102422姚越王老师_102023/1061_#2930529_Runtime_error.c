#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 10000
typedef struct{char str[17];int n;} PAIR;
PAIR a[N];
int record[128];
int cmp(const void* a,const void* b)
{
	PAIR ax=*(PAIR*)a,bx=*(PAIR*)b;
	if(ax.n<bx.n)return -1;
	else if(ax.n>bx.n)return 1;
	else return strcmp(ax.str,bx.str);
}
int pow(int a,int b)
{
	int ans=1;
	for(int i=0;i<b;i++)
		ans*=a;
	return ans;
}
int get_num(const char *str)
{
	int cnt=0,i,j,k,flag,len=strlen(str);
	char p[17],c;
	p[cnt++]=str[0];
	for(i=0;str[i];i++)
	{
		c=str[i];
		flag=1;
		for(j=0;j<cnt;j++)
			if(p[j]==c)flag=0;
		if(flag)p[cnt++]=c;
	}
	for(i=0;i<cnt;i++)
	{
		if(i==0)record[p[i]]=1;
		else if(i==1)record[p[i]]=0;
		else record[p[i]]=i;
	}
	int a[17];
	for(i=0;str[i];i++)
		a[i]=record[str[i]];
	int ans=0;
	for(i=len-1;i>=0;i--)
		ans+=a[i]*pow(cnt,len-1-i);
	return ans;
}
int main()
{
	int n;scanf("%d",&n);
	int i,j,k;
	for(i=0;i<n;i++)
	{
		scanf("%s",a[i].str);
		a[i].n=get_num(a[i].str);
		//printf("%d\n",a[i].n);
	}
	qsort(a,n,sizeof(a[0]),cmp);
	for(i=0;i<n;i++)
		printf("%s\n",a[i]);
	return 0;
}