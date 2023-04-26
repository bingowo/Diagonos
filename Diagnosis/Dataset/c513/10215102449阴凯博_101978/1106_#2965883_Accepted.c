#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Magic 1000000007

long long f(char* s)
{
    if (strlen(s)==1) return 1;
    if (strlen(s)==2)
    {
        if (s[0]==s[1]) return 1;
        else return 4;
    }
    long long r=1;
    if (s[0]!=s[1])
        r=2;
    for (int i=1;i<strlen(s)-1;i++)
    {
        long long c=1;
        if (s[i]!=s[i-1])
            c++;
        if (s[i]!=s[i+1] && s[i-1]!=s[i+1])
            c++;
        r=(r%Magic*c%Magic)%Magic;
    }
    if (s[strlen(s)-1]!=s[strlen(s)-2]) r=(r%Magic*2%Magic)%Magic;
    return r;
}

int main()
{
    char s[1020]={0};
    scanf("%s",s);
    printf("%lld\n",f(s));
    return 0;
}
