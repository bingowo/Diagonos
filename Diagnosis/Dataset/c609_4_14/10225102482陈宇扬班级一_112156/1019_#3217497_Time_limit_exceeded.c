#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    int d1 = *(int *)a;
    int d2 = *(int *)b;
    if(RF(d1) > RF(d2)) return -1;
    else if(RF(d1) < RF(d2)) return 1;
    else if(RF(d1) == RF(d2)) return d2 - d1;
}

int RF(int num)
{
    int cnt = 1;
    if(num < 0) num = -num;
    do
    {
        cnt++;
    }while(num /10);
    return cnt;
}

int main()
{
    int num[100] = {0};
    int i;
    for(i = 0; i != EOF; i++)
    {
        scanf("%d", &num[i]);
    }
    qsort(num, i, sizeof(num[0]), cmp);
    for(int j = 0; j < i; j++)
    {
        printf("%d", num[j]);
    }
    return 0;
}
