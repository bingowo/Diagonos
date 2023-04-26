#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[220];
    scanf("%s",s);
    char r[220];
    strcpy(r,s);
    int i,j;
    if(s[1])
    {
        for(i=0,j=0;s[i+1];i++,j++)
        {
            if(s[i]<s[i+1])
            {
                j++;
                r[j]=s[i];
                r[j+1]=0;
                strcat(r,s+i+1);
            }
            else continue;
        }
    }
    else printf("%s",s);
    printf("%s",r);
    return 0;
}