#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void path(long long x,long long y,int k)
{
    if(k)
    {
        long long d = (1LL<<(k-1));
        if(llabs(x)>llabs(y))
        {
            if(x>0) {path(x-d,y,k-1);printf("E");}
            else {path(x+d,y,k-1);printf("W");}
        }
        else{
            if(y>0) {path(x,y-d,k-1);printf("N");}
            else {path(x,y+d,k-1);printf("S");}
        }
    }
}
int main()
{
    long long x,y,a,b;
    scanf("%lld %lld",&x,&y);
    a = llabs(x);b = llabs(y);
    if(a==0&&b==0) printf("0");
    else if((a + b)%2==0) printf("-1");
    else {
        int i;
        double m = log2(a + b + 1);
        for(i = 1;i<42;i++)
        {
            if(m>i-1&&m<=i) {printf("%d\n",i);break;}
        }
        path(x,y,i);

    }

    return 0;

}
