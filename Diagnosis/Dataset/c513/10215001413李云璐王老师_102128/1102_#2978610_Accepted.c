#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int main()
{
    long long int n;
    scanf("%lld",&n);
    if(n==0) printf("(0,0)");
    else {
    
    long long int wei;
    for(long long int i=0;i<n+1;i++)
    {
        if(n>8*(1+i)*i/2&&n<=8*(2+i)*(1+i)/2) {wei=i+1;break;}
    }
    
    long long cha=n-8*wei*(wei-1)/2-1,bian=wei*2,heng,zong;
    if(cha<bian) {heng=wei-1-cha;zong=wei;}
    if(cha>=bian&&cha<bian*2) {heng=-wei;zong=wei-1-(cha-bian);}
    if(cha>=bian*2&&cha<bian*3) {heng=-wei+1+(cha-bian*2);zong=-wei;}
    if(cha>=bian*3&&cha<bian*4) {heng=wei;zong=-wei+1+(cha-bian*3);}
    printf("(%lld,%lld)",heng,zong);



    }
    return 0;
}