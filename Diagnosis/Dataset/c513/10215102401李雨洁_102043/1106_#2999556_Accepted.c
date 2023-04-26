#include <stdio.h>
#include <string.h>
#define MOD 1000000007;

int main()
{
    char s[1000];
    scanf("%s",s);
    long long end;
    int len = strlen(s);
    if(len == 1)
        end  = 1;
    else if(len == 2)
        end = (s[0] == s[1]) ? 1 : 4;
    else
    {
        end = 1;
        if(s[0] != s[1]) end = 2;
        for(int i = 1; i < len - 1; i++)
        {
            long long c = 1;
            if(s[i] != s[i - 1]) c++;
            if(s[i] != s[i + 1] && s[i - 1] != s[i + 1]) c++;
            end = (end * c) % MOD;
        }
        if(s[len - 1] != s[len - 2])
            end = (end * 2) % MOD;
    }
    printf("%d\n",end);
}
