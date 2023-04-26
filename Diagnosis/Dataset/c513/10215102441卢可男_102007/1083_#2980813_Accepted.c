#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,n;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d",&n);
        printf("case #%d:\n%d\n",i,n/5+n/25+n/125+n/625);

    }

    return 0;
}
