#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n%d\n",i,n/5+n/25+n/125+n/625);
    }
}
