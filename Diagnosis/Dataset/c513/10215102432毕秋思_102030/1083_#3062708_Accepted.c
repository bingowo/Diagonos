#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        int n;
        scanf("%d",&n);
        int count=0;
        count=n/5+n/25+n/125+n/625;
        printf("case #%d:\n",t);
        printf("%d\n",count);
    }
    return 0;
}