#include<stdio.h>
long long int N =0;
void tian(long long int x,long long int y)
{
    if((x>0)&&(y>0))
    {
        int mini;
        if(x>y)
        {
            N=N+4*y;
            x=x-y;
            tian(x,y);
        }
        else
        {
            N=N+4*x;
            y=y-x;
            tian(x,y);
        }
        
        
    }
    else
        return 0;
}
int main()
{
    long long int x,y;
    scanf("%lld%lld",&x,&y);
    tian(x,y);
    printf("%lld",N);
}