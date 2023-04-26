#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        char s[505];
        scanf("%s",s);
         printf("case #%d:\n",cas);
        int cnt=1;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]==s[i+1])
            {
                cnt++;
            }
            else
            {
                if(cnt>255)
                {
                    printf("255%c",s[i]);
                    printf("%d%c",cnt-255,s[i]);
                }
                else printf("%d%c",cnt,s[i]);
                cnt=1;
            }
            if(i==strlen(s)-1) break;
        }
        printf("\n");
    }
    return 0;
}
