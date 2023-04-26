#include <stdio.h>
#include <string.h>
int f(char s[])
{
    int val,pow = 1;
    int len = strlen(s);
    for(int i = len-1; i>-1; i--)
    {
        if(s[i]=='-') val = val-pow;
        if(s[i]=='1') val = val+pow;
        pow*=3;
    }
    return val;
}
int main()
{
    int T; scanf("%d",&T);
    for(int i = 0; i<T; i++)
    {
        char s[30] = {0};
        scanf("%s",s);
        printf("case #%d:\n%d\n",i,f(s));
    }
    return 0;
}