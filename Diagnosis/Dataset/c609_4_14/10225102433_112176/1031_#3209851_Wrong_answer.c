#include <stdlib.h>
#include <stdio.h>

int cmp(const void *a,const void *b)
{
    return (*(int*)a) - (*(int*)b);
}

int main()
{
    int n;scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        printf("case #%d:\n",i);
        int x,y;
        scanf("%d %d",&x,&y);
        int len = x*(x+1)/2;
        int *ve = (int*) malloc(len*sizeof(int));
        int *ak = (int*) malloc(x*sizeof(int));
        for(int j = 0;j < x;j++)
        {
            scanf("%d",&ak[j]);
        }
        int cnt = 0;
        for(int j = 0;j < x;j++)
        {
            for(int h = j;h < x;h++)
            {
                int sum = 0;
                for(int u = j;u <= h;u++)
                {
                    sum += ak[u];
                }
                ve[cnt++] = sum;
            }
        }
        qsort(ve,len,sizeof(int),cmp);
        for(int j = 0;j < y;j++)
        {
            int all = 0;
            int q,w;
            scanf("%d %d",&q,&w);
            for(;q <= w;q++)
            {
                all += ve[q-1];
            }
            printf("%d\n",all);
        }
        free(ve);
        free(ak);
    }

    return 0;
}