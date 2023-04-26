#include <stdio.h>
#include <stdlib.h>
/*To save Robin's physical power, he is expected to till
the largest square land every time, so the side length should be min(x,y),and the value of
the bigger one equals to itself minus the smaller one.
At the end of tilling, the length of
square should be */
long long pwrvlue(int x, int y)
{
    if(x==y)return 4*x;
    else if(!x%y&&x>y)return 4*x;
    else if(!y%x&&y>x)return 4*y;
    else return x>y?4*y+pwrvlue(x-y,y):4*x+pwrvlue(y-x,x);
}
int main()
{
    long long x,y;
    scanf("%lld%lld",&x,&y);
    printf("%lld",pwrvlue(x,y));
    return 0;
}
