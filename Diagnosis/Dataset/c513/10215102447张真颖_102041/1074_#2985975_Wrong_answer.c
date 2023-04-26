#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 210
#define MOD 1000000007
//一种从一个状态迁移到另一个状态
/*模运算公式:
 (a+b)%M==(a%M+b%M)%M;
 (a*b)%M==(a%M*b%M)%M;
  Neg%M==(Neg+M)%M;
*/

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        long long f[101][210]={1};
        char s[101]={0};
        scanf("%s",s);
        for(int i=0;i<strlen(s);i++)
        {
            int sum=0;
            for(int j=i;j<strlen(s);j++)
            {
                sum=(sum*10+s[j]-'0')%M;
                for(int w=0;w<M;w++)
                {
                    f[j+1][(w+sum)%M]=(f[j+1][(w+sum)%M]+f[i][w])%MOD;
                    if(i) f[j+1][(w+M-sum)%M]=(f[j+1][(w+M-sum)%M]+f[i][w])%MOD;//当不处于第一位时，符号变成减
                }
            }
        }
        int t=strlen(s);
        long long num=0;
        for(int i=0;i<210;i++)
        {
            if(i%2==0||i%3==0||i%5==0||i%7==0) num+=f[t][i];
        }
        printf("%lld\n",num);
    }
    return 0;
}
