#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[1001]={0};
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>'Z') s[i]-=32;
        if(s[i]>=s[0])
        {
            char c=s[i];
            for(int j=i;j>0;j--)
                s[j]=s[j-1];
            s[0]=c;
        }
    }
    printf("%s",s);
    return 0;
}