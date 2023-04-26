#include<stdio.h>
 
int main(){
    int d,n;
    scanf("%d",&d);
    scanf("%d",&n);
    int di,vi,d0=0,v0=0;
    double ti,t=0;
    while(n--){
        scanf("%d %d",&di,&vi);
        ti=(d-di)/vi;
        if(ti>t){
            t=ti;
            d0=d-di;
            v0=vi;
        }
    }
    double v=(double)d*v0;v/=d0;
    printf("%.6f",v);
    return 0;
}