#include<stdlib.h>
#include<stdio.h>
int main(){
    long int dis;
    scanf("%ld",&dis);getchar();
    int n;
    scanf("%d",&n);getchar();
    long double maxv=10000000000;
    for(int i=0;i<n;i++){
        long double d,v;
        scanf("%lf%lf",&d,&v);
        long double tv=(v*dis)/(dis-d);
        if(tv<maxv)maxv=tv;
    }
    printf("%.6lf",maxv);
}
