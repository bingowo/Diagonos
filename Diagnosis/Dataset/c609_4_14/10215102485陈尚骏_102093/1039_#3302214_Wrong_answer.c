#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int findsl(char*s0,char*s)
{
    char*p=strstr(s,s0);
    return p==0?-1:p-s;
}

int findsr(char*s0,char*s)
{
    char*p=s;
    char*p1=0;
    while((p1=strstr(p,s0))!=0) p=p1+1;
    return p-s-1;
}

int main()
{
    int T;
    char s[81],s1[81],s2[81];
    scanf("%d",&T);
    for(int i=0;i<T;++i)
    {
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%s",s);
        printf("case #%d\n",i);
        if(findsl(s1,s)==-1||findsl(s2,s)==-1)
        {
            printf("0\n");
            continue;
        }
        if(findsr(s2,s)-findsl(s1,s)-strlen(s1)>findsr(s1,s)-findsl(s2,s)-strlen(s2))
        {
            printf("%d\n",findsr(s2,s)-findsl(s1,s)-strlen(s1));
        }
        else printf("%d\n",findsr(s1,s)-findsl(s2,s)-strlen(s2));
    }
    return 0;
}
