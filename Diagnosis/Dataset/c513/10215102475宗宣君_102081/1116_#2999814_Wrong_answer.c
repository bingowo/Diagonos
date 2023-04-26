#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    long long x,y,a,b;
    scanf("%lld %lld",&x,&y);
    a = llabs(x);b = llabs(y);
    if((a + b)%2==0) printf("-1");
    else if(a==0&&b==0) printf("0");
    else {
        int i;
        double m = log2(a + b + 1);
        for(i = 1;i<42;i++)
        {
            if(m>i-1&&m<=i) {printf("%d",i);break;}
        }
    }
    return 0;

}
