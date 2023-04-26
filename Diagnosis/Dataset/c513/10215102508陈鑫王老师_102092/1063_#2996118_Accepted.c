#include<stdio.h>
#include<stdlib.h>

int main()
{
    unsigned long long int x,y,temp,ret=0;
    scanf("%llu %llu",&x,&y);
    while(x&&y)
    {
        ret+=(4*y)*(x/y);
        x-=(y*(x/y));
        if(x<y)
        {
            temp=x;
            x=y;
            y=temp;
        }
    }
    printf("%llu",ret);
    return 0;

}
