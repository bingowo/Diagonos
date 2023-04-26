#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n,j;
        scanf("%d",&n);
        unsigned long long re=1;
        for(j=0;j<n;j++)
        {
            re*=2;
        }
        printf("case #%d:\n%llu\n",i,re);
    }
}
