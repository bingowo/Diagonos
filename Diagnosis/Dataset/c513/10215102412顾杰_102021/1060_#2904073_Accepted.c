#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int ans=0,t;
    char s[101],*p=s,*p0;
    scanf("%s",s);
    while(*p)
    {
        while(!(*p>='0'&&*p<='9')&&*p)p++;
        p0=p;
        while(*p>='0'&&*p<='9')p++;
        while(*p0=='0')p0++;
        if(p-p0>ans)ans=p-p0;
    }
    printf("%d",ans);
    return 0;
}
