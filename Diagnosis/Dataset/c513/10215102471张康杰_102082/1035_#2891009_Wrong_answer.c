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
    return st2->S - st2->S;
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
    long long int S_max = 0,R = 0;
    for(i = 0;i < m;i++)
    {
        if(volumn[i].radius > R)
            R = volumn[i].radius;
        S_max += volumn[i].S;
    }
    S_max += R*R;
    printf("%lld",S_max);

    return 0;
}