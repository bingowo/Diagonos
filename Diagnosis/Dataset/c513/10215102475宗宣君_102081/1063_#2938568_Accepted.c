#include <stdio.h>
long long int res = 0;
long long int answer(long long int x,long long int y)
{
    long long int m;
    m = x/y;
    res = res + 4*y*m;
    x = x-m*y;
    if(x==0) return 0;
    else return answer(y,x);
}
int main()
{
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    answer(x,y);
    printf("%lld",res);
    return 0;

}
