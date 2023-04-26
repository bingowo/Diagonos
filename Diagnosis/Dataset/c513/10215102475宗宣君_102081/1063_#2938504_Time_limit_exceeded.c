#include <stdio.h>
long long int res = 0;
int answer(int x,int y)
{
    while(x/y!=0)
    {
        res = res + 4*y;
        x = x - y;
    }
    if(x==0) return 0;
    else return answer(y,x-y);
}
int main()
{
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    answer(x,y);
    printf("%d",res);
    return 0;

}
