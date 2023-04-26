#include <stdio.h>
#include <string.h>
#define MOD 1000000007
int main()
{
    int T,i,j,k,m;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        char s[101];
        scanf("%s",s);
        int a[101][210]={1};
        long long int res = 0;
        for(j = 0;j<strlen(s);j++)
        {
            int sum = 0;
            for(m = j+1;m<strlen(s);m++)
            {
                sum = (sum*10 + s[m]-'0')%210;
                for(k = 0;k<210;k++)
                    {
                        a[m+1][(k+sum)%210] = (a[m+1][(k+sum)%210]+a[j][k])%MOD;
                        if(j) a[m+1][(k-sum+210)%210] = ( a[m+1][(k-sum+210)%210]+a[j][k])%MOD;
                    }

            }
        }
        for(k = 0;k<210;k++)
        {
            if(k%2==0||k%3==0||k%5==0||k%7==0) res += a[j][k];
        }
        printf("%lld\n",res%MOD);

    }
    return 0;
}