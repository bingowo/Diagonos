#include <stdio.h>
#include <math.h>

int step(long long x,long long y)
{
    int n;
    if (x==0 && y==0) n = 0;
    else if (fabs(x%2) == fabs(y%2)) n = -1;
    else{
        long long m;int i;
        m = fabs(x)+fabs(y);
        for (i=0;i<m;i++){
            if (m <= pow(2,i)){
                n = i;
                break;
            }
        }
    }
    return n;
}

int main()
{
    long long x,y;
    int s;
    scanf("%lld %lld",&x,&y);
    s = step(x,y);
    printf("%d",s);
    return 0;
}