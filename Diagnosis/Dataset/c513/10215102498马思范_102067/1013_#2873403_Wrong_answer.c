#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    char s[40];
    int cou=0;
    scanf("%s",s);
    int len=strlen(s);
    for(int j=0;j<len;j++)
    {
        if(s[j]!='.')
            cou++;
        else break;
    }
    long long int zheng=0;
    for(int i=0;i<cou;i++)
    {
        if(s[i]=='1')
            zheng=zheng+pow(3,cou-i-1);
        else if(s[i]=='2')
            zheng=zheng-pow(3,cou-i-1);
        else if(s[i]=='0')
            zheng=zheng;
    }
    int zi=0;
    int mu=1;
    for(int p=cou+1;p<len;p++)
    {
        zi=zi*3;
        if(s[p]=='1')
            zi=zi+1;
        else if(s[p]=='2')
            zi=zi-1;
        mu=mu*3;
    }
    if(zi!=0&&mu!=1)
        printf("%lld %d %d",zheng,zi,mu);
    else if(zheng==0)
        printf("%d %d",zi,mu);
    else
        printf("%lld",zheng);
    return 0;
}