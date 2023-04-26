#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int height;
    int radius;
    long long S1;
    long long S2;
}VOL;
int cmp(const void*a,const void*b)
{
    VOL*st1,*st2;
    st1 = (VOL*)a,st2 = (VOL*)b;
    return st2->S1 - st1->S1;
}
int main()
{
    int n,m,i;
    scanf("%d %d",&n,&m);
    VOL volumn[n];
    for(i = 0;i < n;i++)
    {
        scanf("%d %d",&volumn[i].radius,&volumn[i].height);
        volumn[i].S1 = 2*volumn[i].radius*volumn[i].height;
        volumn[i].S2 = volumn[i].radius*volumn[i].radius;
    }
    qsort(volumn,n,sizeof(volumn[0]),cmp);
    long long int S_cur,S_max = 0;
    for(i = 0;i < n;i++)
    {
        S_cur = volumn[i].S1 + volumn[i].S2;
        int count = 1;
        for(int j = i +1;j < n;j++)
        {
            if(volumn[j].S2 <= volumn[i].S2)
            {
                S_cur += volumn[j].S1;
                count++;
            }

            if(count >= m)
                break;
        }
        if(S_cur > S_max)
        {
            S_max = S_cur;
        }
        S_cur = 0;

    }
    printf("%lld",S_max);

    return 0;
}
