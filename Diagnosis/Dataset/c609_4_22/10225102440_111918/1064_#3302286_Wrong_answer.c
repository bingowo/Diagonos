#include <stdio.h>
#include <string.h>
long long int f(long long int x,long long int y){
    if(x==y) return 4*x;
    long long int a;
    if(x<y) a=x,x=y,y=a;
    return 4*y+f(x-y,y);
}
int main()
{
    long long int x,y;
    scanf("%d %d",&x,&y);
    printf("%lld",f(x,y));

    return 0;
}

