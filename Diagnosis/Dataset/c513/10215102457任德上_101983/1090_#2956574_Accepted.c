#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    int t;
    while(scanf("%d",&t)){
        if(t==0)break;
        double a;
        a=1.0*t*log10(t);
        a-=(int)a;
        a=pow(10,a);
        int b=(int)a;
        while(b>=10)b/=10;
        printf("%d\n",b);
    }
    return 0;
}