#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int num;
    int cnt;
}node;

int count(int num)
{
    if(num < 0)
        num = -num;
    int cnt = 0;
    while(num)
    {
        num /= 10;
        cnt++;
    }
    return cnt;
}

int cmp(const void *a,const void *b)
{
    node *pa = (node*)a;
    node *pb = (node*)b;
    if(pa->cnt != pb->cnt)
        return pb->cnt - pa->cnt;
    else
        return pa->num - pb->num;
}

int main()
{
    node *a = (node*)malloc(100000*sizeof(int));
    int cnt = 0;
    int res;
    while((scanf("%d",&res)) != EOF)
    {
        a[cnt].num = res;
        a[cnt++].cnt = count(res);
    }
    qsort(a,cnt,sizeof(int),cmp);
    for(int i = 0;i < cnt;i++)
    {
        printf("%d ",a[i].num);
    }

    return 0;
}