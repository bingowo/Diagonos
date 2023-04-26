#include <stdio.h>

typedef unsigned long long llu;
int main()
{
    llu l,w;
    llu str=0,temp;
    scanf("%llu %llu",&l,&w);
    if(l < w)
    {
        temp = l;
        l = w;
        w= temp;
    }

    while(w)
    {
        str+=4*w*(l/w);
        l-=w*(l/w);
        
        temp = l;
        l = w;
        w= temp;
    }
    printf("%llu\n",str);
    return  0;
}
