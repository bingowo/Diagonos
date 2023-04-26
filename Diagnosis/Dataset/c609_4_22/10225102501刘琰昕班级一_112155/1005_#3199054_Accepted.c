#include <stdio.h>
#include <stdlib.h>

void TtoBT(char *s)
{
    char *p;p=s;int ans=0;
    while(*p)
    {
        if(*p=='-')ans=ans*3-1;
        else ans=ans*3+*p-'0';
        p++;
    }
    printf("%d",ans);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[100]={0};
        scanf("%s",s);
        printf("case #%d:\n",i);
        TtoBT(s);
        printf("\n");
    }
    return 0;
}
