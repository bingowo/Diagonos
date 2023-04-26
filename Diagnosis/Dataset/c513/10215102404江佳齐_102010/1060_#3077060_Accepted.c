#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main()
{
    char s[110];
    scanf("%s",s);
    int max=0;
    int cnt=0;
    int flag=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(isdigit(s[i]))
        {
           if(s[i]=='0' && flag==0) continue;
           cnt++;
           flag=1;
           if(cnt>max) max=cnt;
        }
        else
        {
            if(cnt>max) max=cnt;
            cnt=0;
            flag=0;
        }
    }
    printf("%d\n",max);
    return 0;
}
