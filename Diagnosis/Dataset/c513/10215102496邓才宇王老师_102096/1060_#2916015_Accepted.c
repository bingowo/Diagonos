#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[101];
    scanf("%s",s);
    int max=0;
    char *p1=s;
    char *p2=s;
    while(*p1)
    {
        if(*p1>='1'&&*p1<='9')
        {
            p2=p1;
            while(*p2)
            {
                if(*p2>'9') break;
                p2++;
            }
            if(max<p2-p1) max=p2-p1;
            p1=p2;
        }
        p1++;
    }
    printf("%d",max);
}
