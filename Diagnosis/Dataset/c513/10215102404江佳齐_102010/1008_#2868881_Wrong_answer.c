#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    unsigned a,b,c;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int num=0,d=1;
        scanf("%u %u",&a,&b);
        c=a^b;
        for(int r=0;r<32;r++)
        {
            if(c&d) num++;
            d=d<<1;
        }
        printf("%d",num);
    }
    return 0;
}

