#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int sum[100005][105],len[100005],n;
char s[100005][105],s1[100005][105];
int cmp(const void *e1,const void *e2)
{
	return *(int*)e1-*(int*)e2;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%s",s[i]+1);
//	qsort(s,n,sizeof(s[0]),cmp);
	for(int j=0;j<n;j++)
	{
		int length=strlen(s[j]+1);
		for(int i=1;i<=length;i++)
		{
			if(s[j][i]!=s[j][i-1])
				s1[j][++len[j]]=s[j][i];
			sum[len[j]][j]++;
		}
	}
	for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(strcmp(s1[i],s1[j])!=0)
				{
					printf("-1");
					return 0;
				}
			}
		}
	int ans=0;
	for(int i=1;i<n;i++)
		qsort(sum[i],n,sizeof(sum[i][0]),cmp);
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=len[i];j++)
			ans+=abs(sum[j][i]-sum[j][i-1]);
	}
	printf("%d",ans);
	return 0;
}