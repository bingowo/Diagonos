#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    unsigned long long res =0;
    unsigned long long x,y;
    scanf("%lu%lu",&x,&y);
    if(x<y)
            {
            x=x^y;
            y=y^x;
            x=x^y;
            }

while(x!=1&&y!=1)
    {

        if(x/y)
        {
            res+=4*y*(x/y);
            y=0;
            break;
        }
        else
        {

            res+=4*y;
            x-=y;
            if(x<y)
            {
            x=x^y;
            y=y^x;
            x=x^y;
            }
        }
    }
    res+=x*y*4;
    printf("%lu",res);
    return 0;
}
