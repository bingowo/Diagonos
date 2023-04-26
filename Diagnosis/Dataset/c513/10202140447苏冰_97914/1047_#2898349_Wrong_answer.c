#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[510];
int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int cas=0;cas<T;cas++)
    {
        scanf("%s",s);
        printf("case #%d:\n",cas);
        int cnt=0;
        char*p1=s;char*p2=s;
        while(*p1!='\0')
        {
            if(*p1==*p2)
            {
                p1++;
                cnt++;
                if(*p1=='\0')
                {
                    printf("%d%c",cnt,*(p1-1));
                }
                if(cnt==255)
                {
                    printf("%d%c",cnt,*p1);
                    cnt=0;
                }
            }
            else
            {
                p2=p1;
                printf("%d%c",cnt,*(p2-1));
                cnt=0;
            }
        }
        printf("\n");
    }
    return 0;
}

