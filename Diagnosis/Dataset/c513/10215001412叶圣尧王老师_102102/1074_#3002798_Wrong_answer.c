#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define mod 210
#define max 1000000007
int subint(char *s,int k1,int k2)
{
    int i,j;int out=0;
    for(i=k1;i<=k2;i++)
    {
        out=out*10+s[i]-'0';
        out%=mod;
    }return out;
}
int main()
{
    int T;scanf("%d",&T);
    int i,j,t;
    for(t=0;t<T;t++)
    {
        char ch[101];scanf("%s",ch);
        int f[100][mod]={0};
        for(i=0;i<strlen(ch);i++)
        {
            f[i][subint(ch,0,i)]++;
            f[i][subint(ch,0,i)]%=max;
            for(j=0;j<i;j++)
            {
                int tmp=subint(ch,j+1,i);
                for(int k=0;k<mod;k++)
                {
                    f[i][(k+mod+tmp)%mod]+=f[j][k];
                    f[i][(k+mod+tmp)%mod]%=max;
                    f[i][(k+mod-tmp)%mod]-=f[j][k];
                    f[i][(k+mod-tmp)%mod]%=max;
                }
            }
        }
        int ans=0;
        for(i=0;i<mod;i++)
        {
            if(!(i%2)||!(i%3)||!(i%5)||!(i%7))
            {
                ans+=f[strlen(ch)-1][i];
                ans%=max;
            }
        }
        printf("%d",ans);
    }
}