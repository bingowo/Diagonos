#include<stdio.h>
long int gcd(long int a,long int b){
    return a%b==0?b:gcd(b,a%b);
}
int main(){
    long int fz=0,fm=1;
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b;
        scanf("%d/%d",&a,&b);
        long int c=fz*b+a*fm;
        long int d=fm*b;
        long int g=gcd(c,d);
        fz=c/g;fm=d/g;
    }
    printf("%ld/%ld",fz,fm);
}