#include <stdlib.h>
#include <stdio.h>
long long int max(long long int a,long long int b)
{
    if(a>b) return a;
    else return b;
}
long long int min(long long int a,long long int b)
{
    if(a<b) return a;
    else return b;
}
int main()
{
    long long int x,y,out=0;
    scanf("%lld %lld",&x,&y);
    x=max(x,y);
    y=min(x,y);
    if(x%y==0){
        printf("%lld",(x/y)*4*y);
    }
    else{
    while(x%y!=0){
        out=out+(x/y)*4*y;
        x=max(x-(x/y)*y,y);
        y=min(x-(x/y)*y,y);
    }
    printf("%lld",out);
    }
}