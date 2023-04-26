#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int sum[105][100005],len[100005],n;
char s1[100005][105];
typedef struct {
	char s[105];
	int cnt[105];
}node;
node in[100005];
int cmp(const void *e1,const void *e2)
{
	int a=*(int*)e1,b=*(int*)e2;	
	return a-b;
}
int search_mid(int arr[],int n)
{
	qsort(arr,n,sizeof(arr[0]),cmp);
	return arr[n/2];
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
		int temp[n];
		for(int i=0;i<n;i++)
			temp[i]=in[i].cnt[j];
		int mid=search_mid(temp,n);
		for(int i=0;i<n;i++)
			ans+=abs(in[i].cnt[j]-mid);
	}
	printf("%d",ans);
	return 0;
}