#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int cnt(char s[])
{
    int len=strlen(s);
    int res=0,bal=0;
    for(int i=0;i<len;++i)
    {
        bal+=(s[i]=='('?1:-1);
        if(s[i]==')'&&s[i-1]=='(') res+=1<<bal;
    }
    return res;
}

int main()
{
    char s[51];
    scanf("%s",s);
    printf("%d\n",cnt(s));
    return 0;
}
