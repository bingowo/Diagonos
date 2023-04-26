#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp1(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}

int cmp2(const void *a,const void *b)
{
    return *(int *)b - *(int *)a;
}

int main()
{
    char order;
    scanf("%c",&order);
    int n[100],N;
    int i = 0;
    int flag[1000] = {0};
    while(scanf("%d",&N)!=EOF)
    {
        if(flag[N] == 0)
        {
            n[i++] = N;
            flag[N] = 1;
        }
    }
    if(order == 'A')
        qsort(n,i,sizeof(n[0]),cmp1);
    if(order == 'D')
        qsort(n,i,sizeof(n[0]),cmp2);
    for(int j = 0;j < i;j++)
        printf("%d ",n[j]);
    printf("\n");
    return 0;
}
