#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int m,n,*table;
        scanf("%d %d",&m,&n);
        if(n >= m/2)
            n = m - n;
        memset(table,0,sizeof(int)*(n + 1));
        unsigned long long int ans = 1;
        int i,j;
        for(i = m;i >= m - n + 1;i--)
        {
            for(j = n;j >= 1;j--)
            {
                if(i % j == 0 && table[j])
                {
                    ans = ans* i / j;
                    table[j] = 1;
                }
            }
        }
        printf("case #%d:\n%llu\n",i,ans);
    }
}