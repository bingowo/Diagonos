#include <stdio.h>
#include <stdlib.h>
int main(){
    int len,n;
    scanf("%d%d",&len,&n);
    double max=0
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        double t=1.0*(len-a)/b;
        if(t>max)max=t;
    }
    printf("%.6f",len*1.0/t);
}