#include<stdio.h>
int main(){
    long long x,y,ener=0,temp,o;
    scanf("%lld",&x);
    scanf("%lld",&y);
    temp=x/y;
    o=x%y;
    ener+=y*y*temp;
    while(o!=0){
        temp=y/o;
        ener=o*o*temp;
        o=y%o;
    }
    printf("%d",ener);
    return 0;
}