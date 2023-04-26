#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[1007],ans[1007];
    int i,k,l;
    scanf("%s",s);
    int len = strlen(s);
    ans[0] = toupper(s[0]);
    for(i = 1,k = 1; i < len; i++)
    {
        if(toupper(s[i]) >= ans[0])
            {
                for(l = k-1; l >= 0; l--)ans[l+1] = ans[l];
                ans[0] = toupper(s[i]);
                k++;
        }
        else {ans[k] = toupper(s[i]);k++;}
    }
    ans[k] = '\0';
    printf("%s",ans);
    return 0;
}