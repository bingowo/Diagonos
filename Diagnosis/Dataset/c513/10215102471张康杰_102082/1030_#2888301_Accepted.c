#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    long long int number;
    int n;
}Integer;
int cmp(const void*a,const void*b)
{
    Integer*st1,*st2;
    st1 = (Integer*)a,st2 = (Integer*)b;
    if(st1->n > st2->n)
        return -1;
    else if(st1->n < st2->n)
        return 1;
    else
    {
        if(st1->number > st2->number)
            return 1;
        else
            return -1;
    }
}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int N;
        scanf("%d",&N);
        Integer integer[N];
        for(int j = 0;j < N;j++)
        {
            scanf("%lld",&integer[j].number);
            long long int copy = integer[j].number;
            while(copy>=10 || copy<=(-10))
            {
                copy /= 10;
            }
            if(copy < 0)
                integer[j].n = -copy;
            else
                integer[j].n = copy;
        }
        qsort(integer,N,sizeof(integer[0]),cmp);
        printf("case #%d:\n",i);
        for(int j = 0;j < N;j++)
            printf("%lld%c",integer[j].number,(j == N-1)?'\n':' ');
    }
    return 0;
}
