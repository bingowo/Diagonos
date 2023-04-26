#include <stdio.h>
#include <stdlib.h>
int main(){
    int len,n;
    scanf("%d%d",&len,&n);
    double max=0;
    double t=0;
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        t=1.0*(len-a)/b;
        if(t>max)max=t;
    }
    printf("%lf",len*1.0/t);
}
