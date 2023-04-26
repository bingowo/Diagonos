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
    int n, s, cnt = 0, flag = 0, i;
    scanf("%d%d",&n,&s);
    getchar();
    int a[n];
    for( i = 0 ; i < n ; i++)
        scanf("%d",&a[i]);
    //输入完成

    //对a从低到高排序
    qsort(a,n,sizeof(a[0]),cmp);

}
