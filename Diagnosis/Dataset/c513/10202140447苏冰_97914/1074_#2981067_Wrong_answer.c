#include <stdio.h>
#include <string.h>
#define M 210
#define MOD 1000000007
int main()
{
    int T;
    scanf("%d",&T);
    char s[101];
    for(int cas=0;cas<T;cas++)
    {
        scanf("%s",s);
        int f[101][210]={1};
        for(int i=0;i<strlen(s);i++)
        {
            int sum=0;
            for(int j=i;j<strlen(s);j++)
            {
                sum=(sum*10+(s[j]-'0'))%M;
                for(int k=0;k<M;k++)
                {
                    f[j+1][(k+sum)%M]=(f[j+1][(k+sum)%M]+f[i][k])%MOD;
                    if(i)  f[j+1][(k+M-sum)%M]=(f[j+1][(k+M-sum)%M]+f[i][k])%MOD;
                }
            }
        }
        long long ans=0;
        for(int i=0;i<210;i++)
        {
            if(i%2==0 || i%3==0 || i%5==0 || i%7==0 )
                ans=ans+f[strlen(s)][i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
