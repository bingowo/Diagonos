#include <stdlib.h>
#include <stdio.h>
long long int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}
long long int min(int a,int b)
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
    while(x%y){
        out=out+(x/y)*4*y;
        x=max(x-(x/y)*y,y);
        y=min(x-(x/y)*y,y);
    }
    printf("%lld",out);
}
