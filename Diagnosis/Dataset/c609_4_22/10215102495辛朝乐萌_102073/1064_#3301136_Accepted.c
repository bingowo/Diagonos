#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef unsigned long long int llu;


int main()
{
   llu w,l;
   llu num=0,temp;
   scanf("%llu %llu",&w,&l);
    if (w<l){
        temp=w;
        w=l;
        l=temp;
    }
    while (w&&l){
        num+=(4*l)*(w/l);
        w-=(l*(w/l));
        if (w<l){
            temp=w;
            w=l;
            l=temp;
        }
    }
    printf("%llu",num);
    return 0;
}