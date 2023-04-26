#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int n,m,table[100] = {0};
        scanf("%d %d",&n,&m);
        printf("case #%d:\n0.",i);
        for(int j = 1;n != 0;j++)
        {
            if(table[n] != 0)
            {
                printf("\n%d-%d",table[n],j - 1);
                break;
            }
            else
                table[n] = j;
            printf("%d",n * 10 / m);
            n = n * 10 % m;
        }
        putchar('\n');
    }
    return 0;
}