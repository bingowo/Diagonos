#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    char s[101];
    gets(s);
    int len=strlen(s);
    int num=0;
    for(int i=0;i<len;i++)
    {
        int longest;
        if(s[i]<='9'&&s[i]>'0')
        {
            longest=1;
            while(s[i+longest]<='9'&&s[i+longest]>'0')
                longest++;
        }
        i=i+longest;
        if(longest>num) num=longest;
    }
    printf("%d",num);
    return 0;
}
