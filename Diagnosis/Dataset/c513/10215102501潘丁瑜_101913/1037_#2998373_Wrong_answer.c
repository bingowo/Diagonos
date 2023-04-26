#include <stdio.h>
#include <stdlib.h>

int ncmp(const void *a,const void *b)
{
    return *(int *)b- *(int *)a;
}

int scmp(const void*a,const void*b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int n,m;
    int i;
    int number[10001];
    scanf("%d %d\n1",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&number[i]);
    //对输入的数字从大到小进行排序
    qsort(number,n,sizeof(number[0]),ncmp);

    //求两两间的差值
    int a[10001];
    for(i=0;i<n-1;i++)
        a[i] = number[i]-number[i+1];

    //求n-m+1种情况下的差值
    int count;
    count = n-m+1;
    int S[10001];
    int t=m;
        //求S1（记为S0）
    for(i=0;t>0;i++)
    {
        S[0] += a[i]*(t-1);
        t--;
    }
        //求S2-Scount（记为S1）
    t=m;
    for(i=1;i<count;i++)
        S[i]=S[i-1]-a[i-1]*(t-1)+(number[i] - number[i+m-1]);

    //排序
    qsort(S,count,sizeof(S[0]),scmp);
    printf("%d",S[0]);
    return 0;
}