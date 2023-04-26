#include<stdio.h>
 
int main(){
    int d,n;
    scanf("%d",&d);
    scanf("%d",&n);
    int di,vi,d0=0,v0=0;
    double t=0;
    while(n--){
        scanf("%d %d",&di,&vi);
        double ti=(d-di)/vi;
        if(ti>t){
            d0=di;v0=vi;
        }
    }
    double v=d*v0/(d-d0);
    printf("%.6lf",v);
}