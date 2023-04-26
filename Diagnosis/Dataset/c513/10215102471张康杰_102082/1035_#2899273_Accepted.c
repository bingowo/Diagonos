#include <stdio.h>
#include <stdlib.h>
typedef struct{
    long long int height;
    long long int radius;
    long long int S1;
    long long int S2;
}VOL;
int cmp(const void*a,const void*b)
{
    VOL*st1,*st2;
    st1 = (VOL*)a,st2 = (VOL*)b;
    if(st1->S1 > st2->S1)
        return -1;
    else
        return 1;
}
int main()
{
    int n,m,i;
    scanf("%d %d",&n,&m);
    VOL volumn[n];
    for(i = 0;i < n;i++)
    {
        scanf("%lld %lld",&volumn[i].radius,&volumn[i].height);
        volumn[i].S1 = 2LL*volumn[i].radius*volumn[i].height;
        volumn[i].S2 = volumn[i].radius*volumn[i].radius;
    }
    qsort(volumn,n,sizeof(volumn[0]),cmp);
    long long int S_cur,S_max = 0;
    for(i = 0;i < n;i++)
    {
        S_cur = volumn[i].S1 + volumn[i].S2;
        int count = 1;
        for(int j = 0;j < n;j++)
        {

            if(j == i)
                continue;
            if(count == m)
                break;
            if(volumn[j].S2 <= volumn[i].S2)
            {
                S_cur += volumn[j].S1;
                count++;
            }

            if(count == m)
                break;
        }
        if(S_cur > S_max)
        {
            S_max = S_cur;
        }
        S_cur = 0LL;

    }
    printf("%lld",S_max);

    return 0;
}
