#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int T,i,j;
    char s[10000];
    scanf("%d",&T);
    for(i=0; i<T; i++)
    {
        scanf("%s",s);
        int k = 1, n = 0;
        int len = strlen(s);
        //printf("%s\n",s);
        for(j=len-1; j>=0; j--)
        {
            if(s[j]=='0'||s[j]=='1')
            {
                n += (s[j]-'0') * k;
                k *= 3;
            }
            if(s[j]=='-')
            {
                n -= k;
                k *= 3;
            }
        }
        printf("case #%d:\n%d\n", i, n);
    }

    return 0;
}
