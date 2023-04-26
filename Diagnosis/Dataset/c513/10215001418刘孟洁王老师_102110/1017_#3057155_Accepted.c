#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long long flag = 1,ans,data[507];
    int i,k;
    char s[507];
    int rome[128];
    rome['I'] = 1;rome['V'] = 5;rome['X'] = 10;
    rome['L'] = 50;rome['C'] = 100;rome['D'] = 500;
    rome['M'] = 1000;
    scanf("%s",s);
    int len = strlen(s);
    for(i = 0,k = 0; i < len; i++)
    {
        switch(s[i])
        {
            case '(':flag *= 1000;break;
            case ')':flag /= 1000;break;//记录乘的倍数；
            default: data[k++]  = rome[s[i]] * flag;break;//记录每个字母的值（包括括号）；
        }
    }
    for(i = 0,ans = 0; i < k-1; i++)
    {
        if(data[i] < data[i+1])ans -= data[i];//后面数大就加上这个数的负数；
        else ans += data[i];//后面数小就加上这个数；
    }
    ans += data[k-1];
    printf("%lld",ans);
    
    return 0;
}
