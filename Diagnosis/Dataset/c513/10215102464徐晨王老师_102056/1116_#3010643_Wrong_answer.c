#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    long long int x,y,z;
    scanf("%lld%lld",&x,&y);
    if(x<0)x=-x;
    if(y<0)y=-y;
    z=x+y+1;
    double zz=log(z)/log(2);
    printf("%ld",(int)(floor(zz)+1));
}