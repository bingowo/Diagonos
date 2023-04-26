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
        table = (int*)malloc(sizeof(int)*(n + 1));
        memset(table,0,sizeof(int)*(n + 1));
        unsigned long long int ans = 1;
        int j,k;
        for(j = m;j >= m - n + 1;j--)
        {
            for(k = n;k >= 1;k--)
            {
                if(j % k == 0 && table[k] == 0)
                {
                    ans = ans* j / k;
                    table[k] = 1;
                    break;
                }
            }
        }
        free(table);
        printf("case #%d:\n%llu\n",i,ans);
    }
}