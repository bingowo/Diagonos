#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<malloc.h>
int trans[101];
int tol[100001][101];
char chr[101];
int cmp(const void* a,const void* b)
{
	int x=*(int*)a;int y=*(int*)b;
	if(x<y)return -1;return 1;
}
int main()
{
	char s[105];long long ans=0;
	int n,ct=0,num=0;scanf("%d",&n);
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		num++;
		if(i==len-1||s[i]!=s[i+1])
		{
			chr[++ct]=s[i];
			tol[1][ct]=num;
			num=0;
		}
	}
	for(int i=2;i<=n;i++)
	{
		scanf("%s",s);
		len=strlen(s);
		int pos=0;num=0;
		for(int j=0;j<len;j++)
		{
			num++;
			if(j==len-1||s[j]!=s[j+1])
			{
				++pos;
				if(pos>ct||chr[pos]!=s[j])
				{
					ans=1;//printf("%c %c",chr[pos],);//break;
				}
				tol[i][pos]=num;
				num=0;
			}
		}
		if(pos!=ct)
		{
			ans=1;break;
		}
	}
	if(ans){printf("-1");return 0;}
	for(int i=1;i<=ct;i++)
	{
		for(int j=1;j<=n;j++)
		trans[j]=tol[j][i];
		qsort(trans+1,n,sizeof(int),cmp);
		int anst=0;
		for(int k=1;k<trans[n];k++){
			int sum=0;
			for(int j=1;j<=n;j++){
				sum+=abs(trans[j]-k);
			}
			if(sum<anst || k==1) anst=sum;
		}
		ans+=anst;
		/*if(n%2!=0)
		{
			for(int j=1;j<=n;j++)ans+=abs(trans[j]-trans[(n+1)/2]);
		}
		else
		{
			int sum1=0,sum2=0,mid=n/2;
			for(int j=1;j<=n;j++)sum1+=abs(trans[j]-trans[mid]);
			for(int j=1;j<=n;j++)sum2+=abs(trans[j]-trans[mid+1]);
			if(sum1<=sum2)ans+=sum1;
			else ans+=sum2;
		}*/
	}
	printf("%lld",ans);
	return 0;
}