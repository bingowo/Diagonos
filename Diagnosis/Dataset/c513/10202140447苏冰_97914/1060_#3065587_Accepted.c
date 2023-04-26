#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main()
{
    char s[101];
    scanf("%s",s);
    int max=0;
    int ans=0;
    int flag=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(isdigit(s[i]))
        {
           if(s[i]=='0' && flag==0) continue;
           ans++;
           flag=1;
           if(ans>max) max=ans;
        }
        else
        {
            if(ans>max) max=ans;
            ans=0;
            flag=0;
        }
    }
    printf("%d\n",max);
    return 0;
}
