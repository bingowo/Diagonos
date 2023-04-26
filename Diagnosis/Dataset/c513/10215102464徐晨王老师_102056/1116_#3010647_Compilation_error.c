#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    long long int x,y,z;
    scanf("%lld%lld",&x,&y);
    if(x<0)x=-x;
    if(y<0)y=-y;
    z=x+y+1;
    if(z%2==0||x==0||y==0){
    double zz=log(z)/log(2);
    int zzz=0;
    while(zzz<zz)zzz++;
    printf("%d",(int)(zzz);
    }
    else printf("-1");
}