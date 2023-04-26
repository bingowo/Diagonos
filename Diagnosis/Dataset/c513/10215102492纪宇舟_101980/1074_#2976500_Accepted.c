#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
#define M 210
const int mod=1e9+7;
int f[101][210];
int main()
{
	char s[101];
	int T;scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		int L=strlen(s);
		memset(f,0,sizeof(f));
		f[0][0]=1;
		for(int i=0;i<L;i++)
		{
			int sum=0;
			for(int j=i;j<L;j++)
			{
				sum=(sum*10+s[j]-'0')%M;
				for(int w=0;w<M;w++)
				{
					f[j+1][(w+sum)%M]=(f[j+1][(w+sum)%M]+f[i][w])%mod;
					if(i)f[j+1][(w-sum+M)%M]=(f[j+1][(w-sum+M)%M]+f[i][w])%mod;
				}
			}
		}
		int ans=0;
		for(int w=0;w<210;w++)if(w%2==0||w%3==0||w%5==0||w%7==0)ans=(ans+f[L][w])%mod;
		printf("%d\n",ans);
	}
	return 0;
}