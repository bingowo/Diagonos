#include <stdio.h>
#include <stdio.h>
#define L 1001
#define MOD 1000000007

int cmp(char a,char b,char c)
{
    if(a != b && a != c && b != c)
        return 3;
    else if(a == b && a == c && b == c)
        return 1;
    else
        return 2;
}

int main()
{
    int i,len,ans;
    char input[L];
    scanf("%s",input);
    len = strlen(input);
    for(i = 0;i < len;i++)
    {
        if(i == 0)
        {
            if(input[i] != input[i + 1])
                ans = 2;
            else
                ans = 1;
        }
        else if(i == len - 1)
        {
            if(input[i] != input[i - 1])
                ans = ((ans % MOD) * (2 % MOD)) % MOD;
            else
                ans = ans;
        }
        else
        {
            ans = ((ans % MOD) * (cmp(input[i - 1],input[i],input[i + 1]) % MOD)) % MOD;
        }
    }
    printf("%d\n",ans);
    return 0;
}