#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
    return(*(int*)a-*(int*)b);
}

int gcd(int a,int b)
{
    if(b) return gcd(b,a%b);
    else return a;
}

int main()
{
    int n, s, height, i, lower, upper;
    scanf("%d%d",&n,&s);
    int a[n];
    for( i = 0 ; i < n ; i++)
        scanf("%d",&a[i]);
    //输入完成

    //对a从低到高排序
    qsort(a,n,sizeof(a[0]),cmp);

    height = a[0];//初始化当前高度值

    for( i = 0 ; i < n ; )
    {
        while( a[i] == height )
            i++;//求出此时山谷的最右端
            
        if( i >= n )//此时已在同一水平面
        {
            lower = n;//分母是n
            upper = s + height * n;
            break;
        }
        if( s > i*( a[i] - height ) )//剩余的水量大于当前格的总量
        {
            height = a[i];
            s -= i*( a[i] - height );
            continue;
        }
        else//剩余的水量小于等于当前格的总量
        {
            lower = i;
            upper = s + height * i;
            break;
        }
    }

    int num = upper / lower;//整数部分
    if( num != 0 )
        printf("%d",num);
    int g = gcd( upper, lower );
    upper -= num * lower;
    upper = upper / g;
    lower = lower / g;
    if( upper != 0 )
        printf("+%d/%d",upper,lower);

}