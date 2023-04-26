#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[51];
    int ans=1,tmp=1;
    gets(str);
    for(int i=1;i<strlen(str);i++)
    {
        if(str[i]!=str[i-1])
        {
            tmp++;
            if(i==strlen(str)-1)
            {
                if(tmp>ans) ans=tmp;
            }
        }
        else
        {
            if(tmp>ans)
                ans=tmp;
            tmp=1;
        }
    }
    printf("%d\n",ans);
    system("pause");
    return 0;
}