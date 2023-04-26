#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int sum[105][100005],len[100005],n;
char s1[100005][105];
struct node{
	char s[105];
	int cnt[105];
}in[100005];
int cmp(const void *e1,const void *e2)
{
	node *a=(node*)e1,*b=(node*)e2;	
	return a->cnt-b->cnt;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%s",in[i].s+1);
	for(int j=0;j<n;j++)
	{
		int length=strlen(in[j].s+1);
		for(int i=1;i<=length;i++)
		{
			if(in[j].s[i]!=in[j].s[i-1])
				s1[j][++len[j]]=in[j].s[i];
			in[j].cnt[len[j]]++;
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
		qsort(in,len[1],sizeof(in[0]),cmp);
		for(int i=0;i<n;i++)
			ans+=abs(in[j].cnt[i]-in[j].cnt[(n)/2]);
	}
	printf("%d",ans);
	return 0;
}