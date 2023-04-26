#include <stdio.h>

int len(int n)
{
    if(n < 0)
        n = -n;
    if(n == 0)
        return 1;
    int l = 0;
    while(n > 0)
    {
        l++;
        n/=10;
    }
    return l;
}

int cmp(const void *a,const void *b)
{
    int *p1 = (int *)a;
    int *p2 = (int *)b;
    if(len(*p1)==len(*p2))
        return *p1-*p2;
    else
        return len(*p2)-len(*p1);
}

int main()
{
    int number;
    int n[1000000],i = 0;
    while(scanf("%d",&number)!=EOF)
    {
        n[i] = number;
        i++;
    }
    qsort(n,i,sizeof(n[0]),cmp);
    for(int j = 0;j < i;j++)
        printf("%d ",n[j]);
    return 0;
}
