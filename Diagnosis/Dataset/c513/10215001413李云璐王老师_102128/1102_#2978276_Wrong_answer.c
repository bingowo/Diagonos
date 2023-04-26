#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int main()
{
    long long int n;
    scanf("%lld",&n);
    long long int c[n/1000+1];c[0]=0;
    if(n==0) printf("(0,0)");
    else {
    for(long long int i=1;i<n/1000+1;i++)
    {
       c[i]=c[i-1]+i;
    }
    long long int wei;
    for(long long int i=0;i<n/1000+1;i++)
    {
        if(n>8*c[i]&&n<=8*c[i+1]) {wei=i+1;break;}
    }
    
    long long cha=n-8*c[wei-1]-1,bian=wei*2,heng,zong;
    if(cha<bian) {heng=wei-1-cha;zong=wei;}
    if(cha>=bian&&cha<bian*2) {heng=-wei;zong=wei-1-(cha-bian);}
    if(cha>=bian*2&&cha<bian*3) {heng=-wei+1+(cha-bian*2);zong=-wei;}
    if(cha>=bian*3&&cha<bian*4) {heng=wei;zong=-wei+1+(cha-bian*3);}
    printf("(%lld,%lld)",heng,zong);



    }
    return 0;
}
