#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		char s[100];
		scanf("%s",s);
		int len=strlen(s);
		int a[100]={-1};
		int t=0,k=2;
		long long int ans;
		a[s[0]]=1;
		if(len>=2&&s[0]!=s[1])a[s[1]]=0;
		for(int j=2;j<len,k<len;j++)//赋值 
		{
			if(a[s[j]]==-1){
				a[s[j]]=k;
			}
			k++;
		}
		int b=len-1;
		for(t=0;t<strlen(s);t++){//计算 
			ans=ans+a[s[t]]*pow(len,b);
			b--;
		}
		//printf("%d%d%d%d\n",a[s[0]],a[s[1]],a[s[2]],a[s[3]]); 
		printf("case #%d:\n",i);
		printf("%lld",ans);
	}
 } 