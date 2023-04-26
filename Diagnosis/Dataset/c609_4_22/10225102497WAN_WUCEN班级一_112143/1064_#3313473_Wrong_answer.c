#include <stdio.h>
#include <stdlib.h>

int main()
{
    typedef struct
    {
        long long int a;
        long long int b;
        long long int circumference;
    }Rectangle;
    Rectangle rt={0,0,0};
    scanf("%lld%lld",&rt.a,&rt.b);
    while(rt.a&&rt.b)
    {
        if(rt.a>=rt.b)
        {
            rt.circumference+=4*rt.a/rt.b*rt.b;
            rt.a-=rt.a/rt.b*rt.b;
        }
        else
        {
            rt.circumference+=4*rt.b/rt.a*rt.a;
            rt.b-=rt.b/rt.a*rt.a;
        }
    }
    printf("%lld",rt.circumference);
}
