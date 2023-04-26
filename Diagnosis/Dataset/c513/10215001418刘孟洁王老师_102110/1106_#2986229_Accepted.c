#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i;
    char s[1007];
    long long num;
    scanf("%s",s);
    int len = strlen(s);
    num = 1;
    if(len == 1)printf("1");
    else
    {
        for(i = 0; i < len; i++)
      {
        if((i == 0 && s[i] != s[i+1])||(i == len-1 && s[i] != s[i-1]))
        {
            num = num*2%1000000007%1000000007;
        }
        else if((i == 0 && s[i] == s[i+1])||(i == len-1 && s[i] == s[i-1]))continue;
        else if(s[i] != s[i-1]&&s[i] != s[i+1]&&s[i-1] != s[i+1])
        {
            num = num*3%1000000007%1000000007;
        }
        else if((s[i] != s[i-1]&&s[i] == s[i+1])||(s[i] != s[i+1]&&s[i] == s[i-1])||(s[i] != s[i-1]&&s[i] != s[i+1]&&s[i-1] == s[i+1]))
        {
            num = num*2%1000000007%1000000007;
        }
        else continue;
    }
    printf("%lld",num);
    }
    return 0;
}