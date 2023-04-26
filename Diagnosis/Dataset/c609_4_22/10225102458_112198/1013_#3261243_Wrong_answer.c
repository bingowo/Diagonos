#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int invert(char c)
{
    if('0'<=c && c<='9')return c-'0';
    else return c-'A';
}
int main()
{
    char a[1000000];
    int num[4][2] = {1, 0, -1, 1, 0, -2, 2, 2};
    scanf("0x%s",a);
    int len=strlen(a),a1=0,i=0;
    long long int m=0,n=0,ans=1;
    for(i=len-1;i>=0;i--){
        a1=invert(a[i]);
        for(int j=0;j<4;j++){
            if(a1&1){m+=ans*num[j][0];n+=ans*num[j][1];}
            a1>>=1;
        }
        ans*=(-4);
    }

    if(n==0)printf("%lld\n",m);
    else if(m==0)printf("%lldi\n",n);
    else if(n<0)printf("%lld%lldi\n",m,n);
    else printf("%lld+%lldi\n",m,n);

    return 0;
}
