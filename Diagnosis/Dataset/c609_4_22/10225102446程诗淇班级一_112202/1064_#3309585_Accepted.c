#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    long long int a=0;
    while(x*y!=0){
        if(x>y){
            a=a+y*4*(x/y);
            x=x%y;
        }
        else{
            a=a+x*4*(y/x);
            y=y%x;
        }

    }
    printf("%lld",a);

    return 0;
}
