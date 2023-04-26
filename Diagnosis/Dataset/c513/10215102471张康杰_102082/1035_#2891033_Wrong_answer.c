#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int height;
    int radius;
    long long int S;
}VOL;
int cmp(const void*a,const void*b)
{
    VOL*st1,*st2;
    st1 = (VOL*)a,st2 = (VOL*)b;
    if(st2->S != st2->S)
        return st2->S - st2->S;
    else
        return st2->radius - st1->radius;
}
int main()
{
    int n,m,i;
    scanf("%d %d",&n,&m);
    VOL volumn[n];
    for(i = 0;i < n;i++)
    {
        scanf("%d %d",&volumn[i].radius,&volumn[i].height);
        volumn[i].S = 2*volumn[i].radius*volumn[i].height;
    }
    qsort(volumn,n,sizeof(volumn[0]),cmp);
    long long int S_max = 0,R = 0,S1 = 0;
    for(i = 0;i < m - 1;i++)
    {
        if(volumn[i].radius > R)
            R = volumn[i].radius;
        S_max += volumn[i].S;
    }
    for(i = m-1;i < n;i++)
    {
        if(volumn[i].S + volumn[i].radius*volumn[i].radius > S1 && volumn[i].radius >= R)
            S1 = volumn[i].S + volumn[i].radius*volumn[i].radius;
    }
    S_max += S1;
    printf("%lld",S_max);

    return 0;
}
