#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long n=0,i=0,m=1,k=1,d=0,g=0;
    long long x1=0,y1=0;
    scanf("%lld",&n);
    if(n==0)printf("(0,0)");
    else if(n==1)printf("(0,1)");
    else if(n==2)printf("(-1,1)");
     else if(n==3)printf("(-1,0)");
     else
     {
         for(i=2;;i++)
    {
        m=4*m;k=4*m;
        if(n>m-1 && n<=k-1){break;}
    }
    d=2*i-1;x1=-i+1;y1=-i+1;
    g=n-m;
    if(g>d-1)
    {
        x1=x1+d-1;g=g-d+1;
        if(g>d){y1=y1+d;g=g-d;}else {y1=y1+g;g=0;}
        if(g>d){x1=x1-d;g=g-d;}else {x1=x1+g;g=0;}
        if(g>0){y1=y1-g;}

    }
    else x1=x1+g;
    printf("(""%lld %lld"")",x1,y1);
     }

    return 0;
}
