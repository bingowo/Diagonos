#include <stdio.h>
#include <string.h>
#include <ctype.h>

int max(int a,int b)
{
    return (a>b?a:b);
}

int main()
{
    char s[110];
    scanf("%s",s);
    int len=strlen(s);
    int cnt=0,cnt1=0;
    for(int i=0;i<len;i++)
    {
        if(isdigit(s[i])&&s[i]!='0')//当s[i]为数字0-9时，返回非零，否则返回零
        {
            cnt++;
        }
        else
        {
            cnt1=max(cnt,cnt1);
            cnt=0;
        }
    }
    printf("%d",cnt1);
    return 0;
}
