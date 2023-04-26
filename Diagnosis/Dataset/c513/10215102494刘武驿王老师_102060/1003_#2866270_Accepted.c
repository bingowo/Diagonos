#include <stdio.h>
#include <stdlib.h>

int d2b(long long int a)
{
    int temp = 0,cnt = 0,flag = 0;
    long long comp = 1;
    if (a < 0) {a = -(a + 1); flag = 1;}
    while (cnt < 64)
    {
        cnt += 1;
        if(a & comp) temp += 1;
        comp = comp << 1;
    }
    if(!flag) return temp;
    else return (64 - temp);
}



int cmp(const void *a,const void *b)
{
    if (d2b(*(long long int *)a) > d2b(*(long long int *)b))
    {
        return -1;
    }
    else if (d2b(*(long long int *)a) < d2b(*(long long int *)b))
    {
        return 1;
    }
    else
    {
        if ((*(long long int *)a) > (*(long long int *)b))
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}
int main()
{
    int m;
    scanf("%d",&m);
    long long int a[m][10000];
    int n[10];
    int i,j;
    for (i = 0;i < m;i++)
    {
        scanf("%d",&n[i]);
        for (j = 0;j < n[i];j++)
        {
            scanf("%lld",&a[i][j]);
        }
        qsort(a[i],n[i],sizeof(a[0][0]),cmp);
    }
    for (i = 0;i < m;i++)
    {
        printf("case #%d:\n",i);
        for (j = 0;j < n[i];j++)
        {
            printf("%lld%c",a[i][j],j!=n[i]-1?' ':'\n');
        }
    }
    return 0;
}
