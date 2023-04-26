#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000000007

int main()
{
    char s[1001] = {}; scanf("%s",s);
    int len = strlen(s);
    long long value = (s[0]!=s[1]&&s[1])?2:1;
    if (s[len-1]!=s[len-2]&&len>1) value *= 2;
    for (int i=1;i<len-1;i++)
    {
        int num = 1;
        if (s[i]!=s[i-1]) num++;
        if (s[i]!=s[i+1]) num++;
        if (s[i-1]==s[i+1]&&num>1) num--;
        value = (value%N)*num%N;
    }
    printf("%lld\n",value);
    return 0;
}