#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int check(char c)
{
    if((c >= 'a' && c <= 'f') || (c == 'x'))
        return 1;
    if(isdigit(c))
        return 1;
    return 0;
}

int check1(char c)
{
    if(c >= 'a' && c <= 'f')
        return 1;
    if(isdigit(c))
        return 1;
    return 0;
}

int main()
{
    char s1[10001] = {0};
    char s2[10001] = {0};
    scanf("%s",s1);
    int len = 0;
    for(int i = 0;i < strlen(s1);i++)
    {
        if(check(s1[i]))
            s2[len++] = s1[i];
    }
    memset(s1,'\0',sizeof(s1));
    int cnt = 0,sig = 0;
    for(int i = 0;i < len;i++)
    {
        if((s2[i] == '0') && (s2[i+1] == 'x'))
        {
            sig = 1;
            for(int j = i+2;j < len;j++)
            {
                if(s2[j] == '0' && s2[j+1] == 'x')
                {
                    long long num = 0;
                    for(int p = 0;p < strlen(s1);p++)
                    {
                        int k;
                        if(isdigit(s1[p]))
                            k = s1[p]-'0';
                        else
                            k = s1[p]-'a'+10;
                        num += (int)pow(16,strlen(s1)-1-p)*k;
                    }
                    printf("%lld\n",num);
                    i = j-1;
                    cnt = 0;
                    memset(s1,'\0',sizeof(s1));
                    break;
                }
                else
                {
                    if(s2[j] != 'x')
                        s1[cnt++] = s2[j];
                }
            }
        }
    }
    if(sig == 0)
    {
        printf("-1\n");
        return 0;
    }
    long long num = 0;
    for(int p = 0;p < strlen(s1);p++)
    {
        int k;
        if(isdigit(s1[p]))
            k = s1[p]-'0';
        else
            k = s1[p]-'a'+10;
        num += (int)pow(16,strlen(s1)-1-p)*k;
    }
    printf("%lld\n",num);
    return 0;
}