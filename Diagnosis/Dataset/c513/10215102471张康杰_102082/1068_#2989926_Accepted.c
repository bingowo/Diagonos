#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int f(int n,int m)
{
    if(n == m)
        return 1;
    else if(n < m)
        return 0;
    else
        return 2 * f(n - 1,m) + pow(2,n - m - 1) - f(n - m - 1,m);
    /*
        n - m - 1代表着长度为n - 1的字符串，最后m - 1个字符都为1
        导数第m个字符为0,剩下n - m - 1个字符的情况有pow(2,n - m - 1)种
    */
}

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m))
    {
        if(n == -1)
            break;
        printf("%d\n",f(n,m));
    }
    return 0;
}