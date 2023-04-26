#include <stdio.h>
#include <string.h>

int main()
{
    int max_len=0;
    char *p,*p0;
    char s[51]={0};
    scanf("%s",s);
    p = p0 = s;
    while(*p0)
    {
        while(*(p+1)!=*p && *p) p++;
        max_len = max_len > p-p0? max_len:p-p0;
        p0 = p;
    }
    printf("%d",max_len);
    return 0;
}
