#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10000

char trans(a[N])
{
    int sum=0;
    for(int i=0;a[N];i++)
    {
         if(a[i]=='-')sum=sum*3+(-1);
         else sum=sum*3+a[i];
    }
    return sum;
}

int main()
{
    char s[N];
    int T;
    for(int i=0;i<T;i++)
    {
        int ans;
        printf("case #%d:\n",i);
        scanf("%s",s);
        ans=trans(s[N]);
        printf("%d",ans);
    }
    return 0;
}