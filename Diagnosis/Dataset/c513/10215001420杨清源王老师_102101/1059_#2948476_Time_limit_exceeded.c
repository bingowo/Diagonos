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
    int n, s, cnt = 1, height, i;
    scanf("%d%d",&n,&s);
    getchar();
    int a[n];
    for( i = 0 ; i < n ; i++)
        scanf("%d",&a[i]);
    //输入完成

    //对a从低到高排序
    qsort(a,n,sizeof(a[0]),cmp);
    height = a[0];

    for(i = 0 ; i < n ; i++)
    {
        while(a[i+cnt]==a[i])
            cnt++;
        int tmp = cnt * (a[i+cnt] - a[i]);
        if(s-tmp>0)
        {
            s -= tmp;
            height++;
        }
        else if(s-tmp==0)
        {
            printf("%d",height+1);
            break;
        }
        else
        {
            int g = gcd(s,tmp);
            printf("%d+%d/%d",height,s/g,tmp/g);
            break;
        }
        cnt = 1;
    }


}
