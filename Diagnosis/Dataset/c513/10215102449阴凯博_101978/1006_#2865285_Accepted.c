#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10000

long long pwr(int n)
{
    long long result=1;
    for (int i=0;i<n;i++)
    {
        result=result*3;
    }
    return result;
}

long long trans(char* s)
{
    int i;
    long long result=0;
    for (i=0;i<strlen(s);i++)
    {
        if (s[i]=='1') result=result+pwr(strlen(s)-i-1);
        if (s[i]=='0') ;
        if (s[i]=='-') result=result-pwr(strlen(s)-i-1);

    }
    return result;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char s[N]={0};
        scanf("%s",s);
        long long result=trans(s);
        printf("%lld\n",result);

    }
    return 0;
}
