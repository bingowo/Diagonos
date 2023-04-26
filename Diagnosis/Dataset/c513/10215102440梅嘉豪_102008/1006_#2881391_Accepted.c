#include <stdio.h>

int main()
{
    int T,ans;
    char s[100],*p;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        ans=0;
        scanf("%s",s);
        p=s;
        while(*p)
        {
            if(*p=='-') ans=ans*3-1;
            else ans=ans*3+(*p-'0');
            p++;
        }
        printf("case #%d:\n%d\n",i,ans);
    }
    return 0;
}