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

    for(i = 0 ; i < n - 1 ; i++)
    {
        s -= a[i+1] - a[i];
        cnt++;
        if( (s - a[i+2] + a[i+1]) < 0)
            break;
        if( (s - a[i+2] + a[i+1]) == 0)
        {
            flag = 1;
            break;
        }
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
