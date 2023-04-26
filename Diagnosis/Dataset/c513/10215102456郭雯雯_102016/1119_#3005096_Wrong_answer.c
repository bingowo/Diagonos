#include<stdio.h>
 
int main(){
    int d,n;
    scanf("%d",&d);
    scanf("%d",&n);
    int di,vi;
    double t=0;
    while(n--){
        scanf("%d %d",&di,&vi);
        double ti=(d-di)/vi;
        if(ti>t)t=ti;
    }
    printf("%.6lf",t);
}