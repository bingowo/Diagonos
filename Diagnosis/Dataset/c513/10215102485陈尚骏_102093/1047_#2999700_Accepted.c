#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[1000];
        scanf("%s",s);
        char lts[1000];
        char*p=lts;
        for(int j=0,len=strlen(s);j<len;j++)
        {
            int cnt=1;
            while(s[j]==s[j+1])
            {
                cnt++;j++;
            }
            while(cnt>255)
            {
                p+=sprintf(p,"%d%c",255,s[j]);
                cnt-=255;
            }
            p+=sprintf(p,"%d%c",cnt,s[j]);
        }
        printf("case #%d:\n",i);
        printf("%s\n",lts);
    }
    return 0;
}
