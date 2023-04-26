#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int sum[100005][105],len[100005],n;
char s1[100005][105];
typedef struct{
	char s[105];
	int leng;
}In;
In in[100005];
int cmp(const void *e1,const void *e2)
{
	In *a=(In*)e1,*b=(In*)e2;
	return a->leng-b->leng;
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
	qsort(in,n,sizeof(in[0]),cmp);
	for(int j=0;j<n;j++)
	{
		for(int i=1;i<=in[j].leng;i++)
		{
			if(in[j].s[i]!=in[j].s[i-1])
				s1[j][++len[j]]=in[j].s[i];
			sum[j][len[j]]++;
		}
		s1[j][len[j]+1]='\0';
	}
	for(int i=0;i<n;i++)
		{
// 			printf("%s\n",s1[i]);
			if(strcmp(s1[i],s1[0])!=0)
			{
				printf("-1");
				return 0;
			}
		}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=len[i];j++)
			ans+=abs(sum[i][j]-sum[(n-1)/2][j]);
	}
	printf("%d",ans);
	return 0;
}