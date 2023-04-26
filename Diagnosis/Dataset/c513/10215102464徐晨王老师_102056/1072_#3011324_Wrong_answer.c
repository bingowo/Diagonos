#include <stdio.h>
#include <string.h>
#include <math.h>
typedef long long int lli;
lli myabs(lli d){
    if(d<0)return -d;
    else return d;
}
void path(lli a,lli b,lli len){
    if(len==0)return;
    if(myabs(a)>myabs(b)){
        if(a>0){
            printf("W");
            path(a-len,b,len/2);
        }
        else{
            printf("E");
            path(a+len,b,len/2);
        }
    }
    else{
        if(b>0){
            printf("S");
            path(a,b-len,len/2);
        }
        else{
            printf("N");
            path(a,b+len,len/2);
        }
    }
}
int main(){
    lli x,y;
    scanf("%lld%lld",&x,&y);
    lli z=myabs(x)+myabs(y)+1;
    if(z%2==0){
    double zz=log(z)/log(2);
    lli zzz=0;
    while(zzz<zz)zzz++;
    printf("%lld",zzz);
    lli step=1;
    for(int i=1;i<zzz;i++){
        step=step*2;
    }
    path(x,y,step);
    }
    else printf("-1");
    return 0;
}
