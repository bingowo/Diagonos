#include <stdio.h>
#include <string.h>
int main()
{
    int n,m;
    scanf("%d",&n);
    m=numOf1(n);
    printf("%d",m);
    return 0;

}
int numOf1(int n)
{
    int cnt = 0;
    while (n)
    {
        ++cnt;
        n &= n-1;
    }
    return cnt;
}
