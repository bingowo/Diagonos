#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LL long long
LL gcd(LL a,LL b)
{
    return b?gcd(b,a%b):a;
}

int main() {
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        char s[20];
        scanf("%s",s);
        int len= strlen(s);
        LL interger=0,decimal=0,cyclic=0,den=1,q=0;
        int i,cnt=0;
        //分离出整数部分
        for(i=0;i<len;i++)
        {
            if(s[i]=='.')
                break;
            else
                interger=interger*10+s[i]-'0';
        }
        //不循环小数部分
        for(i++;i<len;i++)
        {
            if(s[i]=='[')
                break;
            else
            {
                decimal=decimal*10+s[i]-'0';//分子
                den*=10;//分母
            }
        }
        //循环小数部分
        for(i++;i<len;i++)
        {
            if(s[i]==']')
                break;
            else
            {
                cyclic=cyclic*10+s[i]-'0';
                q=q*10+9;
                cnt++;
            }
        }
        //有循环节,0.12[1]=(121-12)/900(分母中9的个数=循环节中数的个数，0的个数=小数部分非循环节中数的个数）
        if(q!=0)
        {
            LL p=1;
            while (cnt--)
                p*=10;
            decimal=decimal*p+cyclic-decimal;//0.12[1]: 12*10+1-12
            den*=q;
        }

        LL m=gcd(decimal,den);//小数部分分子分母的最大公约数
        decimal/=m;
        den/=m;
        decimal=interger*den+decimal;
        printf("case #%d:\n%lld/%lld\n",t,decimal,den);
    }
    return 0;
}
