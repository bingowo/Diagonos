#include <stdio.h>
#include <stdlib.h>
 
#define N 1003//二维数组的行数 
#define L 53//二维数组的列数 
 
int num[N][L];//定义要用的二维数组 
 
int cmp( const void *a, const void *b ) //比较函数 
{
    int *x = (int*)a;//把参数类型强制转换成int类型 
    int *y = (int*)b;
    int i;//数组下标 
    for ( i=0; (-1!=x[i])&&(-1!=y[i]); ++i )//判断比较的两个数都还没到行末 
    {
        if ( x[i] > y[i])//如果前面的大于后面的，则符合降序排序规则，返回负值（-1），不做变化 
        {
            return -1;
        }
        if ( x[i] < y[i]) //如果后面的大于前面的，不符合降序排序规则，返回正值（1），需要将二者对换 
        {
            return 1;
        }
    }
    if ( (-1 == x[i]) && (-1 == y[i])) //判断两个一直比较，直到行末都没有比出结果，则判断二者相等，返回0 
    {
        return 0;
    }
    if ( -1 == y[i]) //谁先到达行末谁就小，那么按照降序规则，后面的先，则符合，返回负值 
    {
         return -1;
    }
    return 1;//前面的先，则返回正值 
}
 
int main() 
{
    int t,n,a,i,j;
    scanf("%d",&t);//问题数 
    while (t-- > 0)//这个写法等价为：t>0(t)...t-- 
    {
        scanf( "%d", &n );//每一个问题的行数 
        for ( i = 0; i < n; ++i ) //输入二维数组 
        {
            a = 1;//a要初始化，才能进入循环 ，这里的a=1;只是一个工具人而已。 
            for ( j = 0; -1 != a; ++j )//为什么这里的j没有上限嘞，因为一旦我们输入时按了回车，这表示a已经 是行末，跳出循环。 
	    {
                scanf( "%d", &a );
                num[ i ][ j ] = a;
            }
        }
 
        qsort( num, n, sizeof(num[0]), cmp );
 
        for ( i = 0; i < n; ++i ) 
        {
            if ( -1 != num[ i ][ 0 ] ) //为什么要先判断第一个？ 
            {
                printf( "%d", num[ i ][ 0 ] );
                for ( j = 1; num[ i ][ j ] != -1; ++j ) 
                {
                    printf( " %d", num[ i ][ j ] );
                }
            }
            printf( "\n" );
        }
    }
    return 0;
}