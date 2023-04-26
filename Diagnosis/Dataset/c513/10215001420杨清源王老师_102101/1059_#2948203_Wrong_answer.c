#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmp(const void *a, const void * b)
{
    int *p1 = (int *)a;
    int *p2 = (int *)b;
    return p1 - p2;
}

int gcd(int a,int b)
{
    if(b == 0)
        return a;
    return gcd(a%b,b);
}

int main()
{
    int n, s, cnt = 0, flag = 0;
    scanf("%d%d",&n,&s);
    getchar();
    int a[n];
    for(int i = 0 ; i < n ; i++)
        scanf("%d",&a[i]);
    //输入完成

    //对a从低到高排序
    qsort(a,n,sizeof(a[0]),cmp);
    int i;
    for(i = 0 ; i < n ; i++)
    {
        s -= a[i];
        cnt++;
        if( (s - a[i+1]) < 0)
            break;
        if( (s - a[i+1]) == 0)
            flag = 1;
    }
    cnt += a[0];

    if(flag == 1)
        printf("%d",cnt);
    else
    {
        int tmp = gcd(s,a[i+1]);
        printf("%d+%d/%d",cnt,s/tmp,a[i+1]/tmp);
    }
}
