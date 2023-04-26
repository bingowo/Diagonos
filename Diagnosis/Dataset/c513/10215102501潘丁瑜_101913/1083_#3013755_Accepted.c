#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i,n;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        printf("case #%d:\n",i);
        printf("%d\n",n/5+n/25+n/125+n/625);
    }

    return 0;
}
