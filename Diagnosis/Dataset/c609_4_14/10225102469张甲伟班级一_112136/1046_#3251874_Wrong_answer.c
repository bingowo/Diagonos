#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int sum[105][100005],len[100005],n;
char s1[100005][105];
typedef struct{
	char s[105];
	int leng;
}In;
In in[100005];
int cmp(const void *e1,const void *e2)
{
	return *(int*)e1-*(int*)e2;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",in[i].s+1);
		int length=strlen(in[i].s+1);
		in[i].leng=length;
	}
//	qsort(in,n,sizeof(in[0]),cmp);
	for(int j=0;j<n;j++)
	{
		for(int i=1;i<=in[j].leng;i++)
		{
			if(in[j].s[i]!=in[j].s[i-1])
				s1[j][++len[j]]=in[j].s[i];
			sum[len[j]][j]++;
		}
		s1[j][len[j]+1]='\0';
	}
	for(int i=0;i<n;i++)
		{
			if(strcmp(s1[i]+1,s1[0]+1)!=0)
			{
				printf("-1");
				return 0;
			}
		}
	int ans=0;
	for(int j=1;j<=len[1];j++)
	{
		qsort(sum[j],len[1],sizeof(sum[j][0]),cmp);
		for(int i=0;i<n;i++)
			ans+=abs(sum[j][i]-sum[j][(n)/2]);
	}
	printf("%d",ans);
	return 0;
}