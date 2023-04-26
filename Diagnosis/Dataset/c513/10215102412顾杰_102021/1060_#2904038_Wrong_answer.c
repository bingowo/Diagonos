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
        int a=0;
        while(!(*p>='0'&&*p<='9')&&*p)p++;
        p0=p;
        while(*p>='0'&&*p<='9')p++;
        *p++=0;
        t=atoi(p0);
        while(t){t/=10;a++;}
        if(a>ans)ans=a;
    }
    printf("%d",ans);
    return 0;
}
