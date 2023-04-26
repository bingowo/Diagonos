#include <stdio.h>

int main(){
    int a,n,m,x,y;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    if(x==1) printf("%d",a);
    if(x==2) printf("%d",a);
    if(x==3) printf("%d",2*a);
    int c[20]={1,1,2,2,3,4,6,9,14,22,35,56,90,145,234,378,611,988,1598};
    int d[20]={0,0,0,1,2,4,7,12,20,33,54,88,143,232,376,609,986,1596,2583,4180};
    if(x>=4){
        y=(m-c[n-2]*a)/d[n-2];
        printf("%d",c[x-1]*a+d[x-1]*y);}
}