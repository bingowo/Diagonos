#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int f(long long int x,long long int y)
{
    long long int max=x>y?x:y;
    long long int min=x<y?x:y;
    if(max%min==0) return (max/min)*min*4;
    return (max/min)*min*4+f(max%min,min);
    
}

int main()
{

    long long int x,y;
    scanf("%lld %lld",&x,&y);
    printf("%lld\n",f(x,y));

    return 0;
}



