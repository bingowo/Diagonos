#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    long long x;
    long long y;
}Point;

long long jdz(long long a)
{
    if(a>=0) return a;
    else return -a;
}

int main()
{
    Point a;
    scanf("%lld%lld",&a.x,&a.y);
    long long len=jdz(a.x)+jdz(a.y);
    int re;
    long long mid=1,sum=0;
    if(len%2==0) re=-1;
    else
    {
        int i=1;
        sum+=mid;
        if(sum>=len) re=i;
        else
        {
            for(i=2;i<61;i++)
            {
                mid*=2;
                sum+=mid;
                if(sum>=len) {re=i;break;}
            }
        }
    }
    printf("%d",re);


}
