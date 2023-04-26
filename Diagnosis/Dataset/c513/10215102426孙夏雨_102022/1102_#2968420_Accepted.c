#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int n=0;
    scanf("%lld",&n);
    long long int zs=1;
    if(n==0) printf("(0,0)\n");
    else{
        while((n-zs*zs)>=(4*zs+4)) zs+=2;
        long long int x=zs/2,y=zs-x;
        long long int square=y;
        long long int cha=n-zs*zs;
        if(cha-zs<=0) printf("(%lld,%lld)\n",x-cha,y);
        else if(cha-zs*2-1<=0) printf("(%lld,%lld)\n",x-zs,y-cha+zs);
        else if(cha-zs*3-2<=0) printf("(%lld,%lld)\n",x-3*zs+cha-1,y-zs-1);
        else printf("(%lld,%lld)\n",x+1,y-4*zs-1+cha-2);
    }
    return 0;
}
